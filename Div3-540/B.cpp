//
// Created by User on 23-Apr-19.
//
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
        for (; *it != ','; ++it)
            if (*it != ' ')
                b += *it;
        cout << b << "=" << a << " ";
        call(++it, ed, rest...);
    }
};
///START YOUR CODE FROM HERE.... Happy Coding.... ! ;)

int main() {

    fastInput

    int testCase, n, m;

    cin >> n;

    vector<int> v;
    vector<ll int> odd_v;
    vector<ll int> even_v;
    ll int ans = 0;
    ll int odd = 0;
    ll int even = 0;
    v.push_back(0);
    odd_v.push_back(0);
    even_v.push_back(0);
    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        if (i % 2 == 0) {
            even += t;
            even_v.pb(even);
        } else {
            odd += t;
            odd_v.push_back(odd);
        }
        ans += t;
        v.push_back(t);
    }
    //dbg(ans,even,odd)
    //dbgA(even_v,even_v.size())
    //dbgA(odd_v,odd_v.size())
    int c = 0;
    for (int j = 1; j <= n; ++j) {
        if ((ans - v[j]) % 2 == 0) {

            int odd_indx = ceil(j / 2.0);
            if (j % 2 == 0) {
                odd_indx++;
            }
            int even_indx = ceil(j / 2.0);

            ///dbg(j , odd_indx , even_indx)

            ll int odd_prev = odd_v[odd_indx - 1];
            ll int even_prev = even_v[even_indx - 1];
            ll int t = 0;
            if (odd_indx <= even_v.size()) {
                t = even_v[even_v.size() - 1] - even_v[odd_indx - 1];
            }
            ll int t1 = 0;
            if (even_indx + 1 <= odd_v.size()) {
                t1 = odd_v[odd_v.size() - 1] - odd_v[even_indx];
            }
            odd_prev += t;
            even_prev += t1;
            //dbg(even_prev, odd_prev)
            if (odd_prev == even_prev)
                c++;

        }
    }
    cout << c << endl;

    return 0;
}
