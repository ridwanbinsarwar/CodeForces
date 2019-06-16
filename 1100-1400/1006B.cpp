/******************************************************************************
                   ------Bismillahir-Rahmanir-Rahim------

***********************************--XENON--***********************************/

#include <bits/stdc++.h>

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

int main() {

    fastInput

    int testCase, n, m;

    cin >> n;
    cin >> m;

    vector<int>v;
    vector<int>v1;

    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        v.push_back(t);
        v1.push_back(t);
    }
    ll int res= 0;
    sort(v.begin(),v.end(),greater<int>());
    map<int,int>map;
    for (int i = 0; i < m; ++i) {
        res += v[i];
        map[v[i]]++;
    }
    cout << res << endl;
    int c = 0;
    bool b = false;
    for (int i = 0; i < n; i++) {
        c++;
        if ((map.find(v1[i]) != map.end())) {
            if (b) {
                if (map[v1[i]] != 0) {
                    b = false;
                    cout << c - 1 << " ";
                    c = 1;
                }
            }
        }
        if(map.find(v1[i]) != map.end() && map[v1[i]] != 0) {
            map[v1[i]] = map[v1[i]] -1;
            b= true;
        }
    }
    cout << c << endl;
    return 0;
}