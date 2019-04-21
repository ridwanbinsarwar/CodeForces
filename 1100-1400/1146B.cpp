//
// Created by User on 21-Apr-19.
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

  string s;
  cin >> s;
    string a , b;

    auto len = s.size()-1;
    while(s[len] != 'a' && len >0) {
        string t(1,s[len]);
        b.insert(0,t);
        len--;
    }
    //cout << b << endl;
    string ans;
    int j = 0;
    bool found = false;
    for(int i = 0; i<s.size(); i++) {
        ans += s[i];
        if(s[i] != 'a'){
            a += s[i];
        }
        if( i >= len) {
            if (a == b ) {
                cout << ans << endl;
                found = true;
                return 0;
            }
            if(b.size() == 0)
                break;
            b = b.substr(1,b.size());
            //cout << a << " " << b << endl;
            //cout << a.size() << " " << b.size() << endl;
            j++;
        }
    }
    if(len == s.size()-1) {
        if( a == b)
            cout << s << endl;
        else
            cout << ":(\n";
    }
    else if (!found) {
        cout << ":(\n";
    }

  return 0;
}
