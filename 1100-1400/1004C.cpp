/******************************************************************************
                   ------Bismillahir-Rahmanir-Rahim------

***********************************--XENON--***********************************/

#include <bits/stdc++.h>

#define ll long long
#define fileInOut freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define fileIn freopen("input.txt","r",stdin);
#define F(i,start,end) for( int i = (int)start; i <= (int)end; i++)
#define FB(i,start,end) for( int i = (int)start; i >= (int)end; i--)
#define pb push_back
#define infi for(;;)
#define debug(i) cout << "Debug : " << i << endl;
#define Pprint cout<<setprecision(8)<<fixed<<
#define fastInput ios_base::sync_with_stdio(false); cin.tie(NULL);

template<class T , class U> T getMin(T a , U b) {return (a<b?a:b);}
template<class T , class U> T getMax(T a , U b) {return (a>b?a:b);}
template<class T> T charIndexS(T c) {return c-96;}
template<class T> T charIndexL(T c) {return c-64;}
template<class T, class U, class O, class P> T arrayOutofBoundary(T r, U c, O m, P n) {
    return r < 0 || c < 0 || r == m || c == n;

}
template<class T , class U> T power(T base, U exponent){
    return (exponent == 0) ? 1 : (base * pow(base, exponent-1));
}
int hx[] = {-1, -2, -2, -1, 1, 2,  2,  1};
int hy[] = {-2, -1,  1,  2, 2, 1, -1, -2};
int dx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = {-1, +1, +0, +0, +1, +1, -1, -1};
using namespace std;

///START YOUR CODE FROM HERE.... Happy Coding.... ! ;)

int main(){

    fastInput

    int testCase, n, m;


    cin >> n;
    int arr[n];
    arr[n-1] = 0;
    int cnt = 0;
    unordered_set<int>visited1;
    unordered_set<int>visited2;
    vector<int>v;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        v.push_back(t);

    }

    for (int i = n-1; i >0; --i) {
        if(visited1.find(v[i]) != visited1.end())
            arr[i-1] = cnt;
        else
            arr[i-1] = ++cnt;
        visited1.insert(v[i]);
    }

    ll int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        if(visited2.find(v[i]) !=  visited2.end()){
            continue;
        }

        ans += arr[i];
        visited2.insert(v[i]);
    }

    cout << ans << endl;

    return 0;
}