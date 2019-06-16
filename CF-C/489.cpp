//
// Created by User on 01-May-19.
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


  vector<int>maxv;

  cin >> n >> m;
  if(n==1 and m == 0){
      cout << 0 <<  " " << 0 << endl;
      return 0;
  }
  vector<int>minv(n,0);
  int maxi = m;
  int mini= m;
  if(m != 0) {
      mini--;
      minv[0] = 1;
  }

  for(int i = 0; i<n; i++) {
      if(maxi-9 >= 0) {
          maxv.push_back(9);
          maxi -= 9;
      } else {
          maxv.push_back(maxi);
          maxi = 0;
      }
  }

    for(int i = minv.size()-1; i>=0; i--) {
        if(i==0) {
            if(mini > 9)
                break;
            else{
                minv[i] = minv[i] + mini;
                mini = 0;
                continue;
            }
        }
        if(mini-9 >= 0) {
            minv[i] = 9;
            mini -= 9;
        } else {
            minv[i] = mini;
            mini = 0;
        }
    }

    if(mini != 0 || maxi != 0 || maxv[0] == 0 || minv[0] == 0) {
        cout << -1 << " " << -1 << endl;
        return 0;
    }

    for( auto i : minv) {
        cout << i;
    }
    cout << " ";

    for(auto i : maxv){
        cout << i;
    }
    cout <<endl;

  return 0;
}