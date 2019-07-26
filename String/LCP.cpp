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
#define pb push_back
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


  return 0;
}

...
import java.math.*;
import java.io.*;
class Main
{
public static void main(String[] args)throws IOException
            {
                    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
                    int t;
                    t=Integer.parseInt(br.readLine());
                    BigInteger p;
                    while(t>0)
                    {
                        int n;
                        n=Integer.parseInt(br.readLine());
                        p=new BigInteger("1");
                        for(int i=2;i<=n;i++)
                            p=p.multiply(new BigInteger(""+i));
                        System.out.println(p);
                        t--;
                    }
            }
}



#include <bits/stdc++.h>
using namespace std;
int val[2000];
/*DP matrix is used to store
results calculated(Memoization)*/
int dp[2000][2000];
int n;
int TRT(int start,int end,int yr)
{
    /*Recursion + memoization*/
    if(start>end)
        return 0;
    if(dp[start][end]!=-1)
        return dp[start][end];
    else
        return dp[start][end]=max(TRT(start+1,end,yr+1)+val[start]*yr,
                                  TRT(start,end-1,yr+1)+val[end]*yr);
}
int main() {
    std::ios::sync_with_stdio(false);

    cin>>n;
    for(int i=0;i<n;++i)
        cin>>val[i];
    memset(dp,-1,sizeof(dp));
    cout<<TRT(0,n-1,1);
    return 0;
}












int main()
{
    int t;
    scanf("%d" , &t);
    int ans = 0;
    while(t--) {
        ans++;
        int k , n , m;
        for(int i = 0 ; i <= 1100 ; i++) {
            s[i].clear();
        }
        memset(map , 0 , sizeof(map));
        scanf("%d%d%d" , &k , &n , &m);
        for(int i = 0 ; i < k ; i++)
            scanf("%d" , &a[i]);
        for(int i = 0 ; i < m ; i++) {
            int x , y;
            scanf("%d%d" , &x , &y);
            s[x].push_back(y);
        }
        for(int i = 0 ; i < k ; i++) {
            memset(vis , 0 , sizeof(vis));
            map[a[i]]++;
            dfs(a[i]);
        }
        int cnt = 0;
        for(int i = 1 ; i <= n ; i++) {
            //cout << map[i] << endl;
            if(map[i] == k)
                cnt++;
        }
        printf("Case %d: %d\n" , ans , cnt);
    }
    return 0;
}