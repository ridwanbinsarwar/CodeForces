//
// Created by User on 29-Apr-19.
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
    //fileIn
    fastInput

    int testCase, n, m;

    cin >> n;

    char c = 'a';

    vector<vector<char> > v;

    for (int i = 0; i < n; ++i) {
        v.emplace_back();
        for (int j = 0; j < n; ++j) {
            char t;
            cin >> t;
            v[i].push_back(t);
        }
    }

    for (int i = 0; i < n - 1; ++i) {

        for (int j = 0; j < n - 1; ++j) {
            if (v[i][j] == '#')
                continue;

            if (v[i][j] == '.') {
                //cout << i << " " << j << endl;
                int x = i;
                int y = j;
                bool b = true;

                for (int q = 0; q < 4; q++) {
                    int cx, cy;
                    cx = x + dx[q];
                    cy = y + dy[q];
                    // dbg(cx, cy)
                    if (arrayOutofBoundary(cx, cy, n, n))
                        b = false;
                    else if (v[cx][cy] != '.') {
                        b = false;
                    }
                }

                if (b) {

                    v[i][j] = c;
                    for (int l = 0; l < 4; l++) {
                        int nx = i + dx[l];
                        int ny = j + dy[l];
                        if (arrayOutofBoundary(nx, ny, n, n))
                            b = false;
                        else if (v[nx][ny] == '.') {
                            v[nx][ny] = c;
                        }
                    }
                    c++;
                    if (c == 'z') {
                        c = 'A';
                    }
                    if (c == '.')
                        c++;
                }

            }

        }
    }


    for (int i = 0; i < n; ++i) {

        for (int j = 0; j < n; ++j) {
            // cout << v[i][j];
            if (v[i][j] == '.') {
                cout << "NO\n";
                return 0;
            }
        }
        // cout << endl;
    }

    cout << "YES\n";

    return 0;
}
