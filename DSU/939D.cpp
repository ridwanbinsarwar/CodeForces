/******************************************************************************
                   ------Bismillahir-Rahmanir-Rahim------

***********************************--XENON--***********************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <set>
#include <iomanip>
#include <queue>
#include <map>
#include <functional>
#include <memory.h>
#include <list>
#include <sstream>
#include <ctime>
#include <climits>
#include <bitset>
#include <list>

#define ll long long
#define fileInOut freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define fileIn freopen("input.txt","r",stdin);
#define F(i, start, end) for( int i = (int)start; i <= (int)end; i++)
#define FB(i, start, end) for( int i = (int)start; i >= (int)end; i--)
#define pb push_back
#define infi for(;;)
#define debug(i) cout << "Debug : " << i << endl;
#define Pprint cout<<setprecision(8)<<fixed<<
#define fastInput ios_base::sync_with_stdio(false); cin.tie(NULL);

template<class T, class U>
T getMin(T a, U b) { return (a < b ? a : b); }

template<class T, class U>
T getMax(T a, U b) { return (a > b ? a : b); }

template<class T>
T charIndexS(T c) { return c - 96; }

template<class T>
T charIndexL(T c) { return c - 64; }

template<class T, class U, class O, class P>
T arrayOutofBoundary(T r, U c, O m, P n) {
    return r < 0 || c < 0 || r == m || c == n;

}

template<class T, class U>
T power(T base, U exponent) {
    return (exponent == 0) ? 1 : (base * pow(base, exponent - 1));
}

int hx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int hy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = {-1, +1, +0, +0, +1, +1, -1, -1};
using namespace std;

///START YOUR CODE FROM HERE.... Happy Coding.... ! ;)
int n, m;
struct Edge {
    int v;

    Edge(int n) {this->v = n;}
};

vector<Edge> adj[200010];
int rep[200010];
int rnk[200010];
int cnt[200010];

void make_set(int x) {
    rep[x] = x;
    rnk[x] = 0;
}

int find_p(int x) {
    if(rep[x] == x) return x;
    return rep[x] = find_p(rep[x]);
}
int ans = 0;
bool union_rank(int x, int y) {
    int px = find_p(x);
    int py = find_p(y);
    if( px != py ){
        if(rnk[px] < rnk[py])
            swap(px,py);
        rep[py] = px;
        if( rnk[px] == rnk[py])
            rnk[px]++;
        return true;
    } else {
        //cout << "Cycle Found\n";
        return false;
    }
}
int main() {

    fastInput
    for (int i1 = 0; i1 < 27; ++i1) {
        make_set(i1);
    }
    int testCase, n, m;

    int x, y;
    int tc, t;

    cin >> n;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    vector< pair<char, char> > vpair;
    for (int i = 0; i < s1.size(); ++i) {
        if(union_rank(s1[i]-'a',s2[i]-'a')){
            ans++;
            vpair.emplace_back(s1[i],s2[i]);
        }
    }

    cout << ans << endl;
    for (auto &i : vpair) {
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}