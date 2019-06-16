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
///START YOUR CODE FROM HERE.... Happy Coding.... ! ;)

int main(){

  fastInput

  int testCase, n, m;

  cin >> n >> m;
  bool full = false;
  int left1;
  bool extra = false;
  bool perfect = false;
  bool extra1 = false;
  if(m >= n -1) {
       left1 = m - (n -1);
        if(left1  > 0) {
            left1--;
        }
        else {
            perfect = true;
        }
        if(left1 > 0) {
            left1--;
            full = true;
        } else {
            extra1 = true;
        }
        if(left1 > 0) {
            extra = true;
        }
  } else {
      cout << -1 << endl;
      return 0;
  }
    //dbg(perfect,extra,extra1,full,n,m, left1)
    if(left1 > n+1)
    {
        cout << -1 << endl;
        return 0;
    }
    vector<int>ans;
    if(perfect) {
        while (m >0 || n >0) {
            if(n >0 && m <=0 )
                cout << 0;
            else
                cout << "01";
            m--;
            n--;
        }
        cout << endl;

        return 0;
    }
    else if(extra1) {
        while (m >0 || n >0) {
            cout << "01";
            m--;
            n--;
        }
        cout << endl;

        return 0;
    }
    else if(full && !extra) {
        //dbg("here")
        cout << 1;
        m--;
        while (m >0 || n >0) {
            cout << "01";
            m--;
            n--;
        }
        cout << endl;
        return 0;
    } else {
        while (m > 0 || n > 0) {
            if (m > 0) {
                if (left1 > 0 && m > 1) {
                    ans.push_back(11);
                    left1--;
                    m -= 2;
                } else {
                    ans.push_back(1);
                    m -= 1;
                }
            }

            if (n > 0) {
                ans.push_back(0);
                n--;
            }
        }
    }

    for(auto i : ans) {
        cout << i;
    }
    cout << endl;


  return 0;
}