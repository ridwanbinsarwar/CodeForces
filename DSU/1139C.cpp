#include <bits/stdc++.h>
using  namespace std;
int rep[500005];
int sz[500005];
int cnt[500005];
#define FOR(n)          for(int i=0; i<(int)(n); ++i)
#define all(V)          V.begin(),V.end()
#define dbg(args...)    {string sss(#args);sss+=',';cout<<"-->";debugger::call(all(sss), args);cout<<"\n";}
#define dbgA(A, n)      {cout<<"-->"<<#A<<"=(";FOR(n)cout<<A[i]<<" ";cout<<")\n";}
#define dbgA2(A, n, m)  {cout<<"-->"<<#A<<"=\n";FOR(n){FORI(j, 0, m){cout<<A[i][j]<<" ";}cout<<"\n";}cout<<"\n";}

struct debugger {
   typedef string::iterator si;
   static void call(si it, si ed) {}
   template<typename T, typename ... aT>
   static void call(si it, si ed, T a, aT... rest) {
      string b;
      for(; *it != ','; ++it)
         if(*it != ' ')
            b += *it;
      cout << b << "=" << a << " ";
      call(++it, ed, rest...);
   }
};
const long long MOD = 1e9 + 7;
long long int fast_power(long long int base, long long int power) {
    long long int result = 1;
    while(power > 0) {

        if(power % 2 == 1) { // Can also use (power & 1) to make code even faster
            result = (result*base) % MOD;
        }
        base = (base * base) % MOD;
        power = power / 2; // Can also use power >>= 1; to make code even faster
    }
    return result;
}
void make_set(int x) {
    rep[x] = x;
    sz[x] = 1;
}

int find_p(int x) {
    if(rep[x] == x) return x;
    return rep[x] = find_p(rep[x]);
}

void union_rank(int x, int y) {
    int px = find_p(x);
    int py = find_p(y);
    if( px != py ){
        sz[px] += sz[py];
        rep[py] = px;
    }
}

int main() {
    int n,k;
    cin >> n >> k;
    int u[100100],v[100100],c[100100];
    for (int i = 0; i < n; ++i) {
        make_set(i);
    }

    for (int i = 1; i < n ; ++i) {
        cin >> u[i] >> v[i] >> c[i];
        u[i]--; v[i]--;
        if(c[i] == 0) {
            union_rank(u[i],v[i]);
        }
    }
    long long ans = fast_power(n,k);
    for (int i = 0; i < n; ++i) {
        if(rep[i] != i) continue;
        ans = (ans - fast_power(sz[i], k) + MOD) % MOD;
    }
    cout << ans << endl;
}
