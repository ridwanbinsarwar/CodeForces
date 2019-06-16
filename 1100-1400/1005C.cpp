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

    vector<ll int> p2;

    for (int i = 1; i <= 35; ++i) {
        p2.push_back((2ULL << (i - 1)));
    }

    map<ll int, ll int> map;
    vector<int> v;

    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        v.push_back(t);
        map[t]++;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        bool b = false;
        ll int temp;
        for (int j = 0; j <= 35; ++j) {

            temp = p2[j] - v[i];
            if (temp == v[i]) {
                if (map[temp] > 1) {
                    b = true;
                    break;
                }
            } else {
                if (map.find(temp) != map.end()) {
                    b = true;
                    break;
                }
            }
        }
        if(!b)
            ans++;
    }

    cout << ans << endl;
    return 0;
}