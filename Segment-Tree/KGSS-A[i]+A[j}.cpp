//
// Created by Xenon on 21-May-19.
//
/******************************************************************************
                   ------Bismillahir-Rahmanir-Rahim------

***********************************--XENON--***********************************/

#include <bits/stdc++.h>

#define ll long long
#define fileInOut freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define fileIn freopen("input.txt","r",stdin);
#define pb push_back
#define infi for(;;)
#define fastInput ios_base::sync_with_stdio(false); cin.tie(NULL);

template<class T , class U> T power(T base, U exponent){
    return (exponent == 0) ? 1 : (base * pow(base, exponent-1));
}
int hx[] = {-1, -2, -2, -1, 1, 2,  2,  1};
int hy[] = {-2, -1,  1,  2, 2, 1, -1, -2};
int dx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = {-1, +1, +0, +0, +1, +1, -1, -1};
using namespace std;
inline int nextint(){ int x; scanf("%d",&x); return x; }
inline ll nextll(){ ll x; scanf("%lld",&x); return x; }
///START YOUR CODE FROM HERE.... Happy Coding.... ! ;)
const int maxN = 5e5+7;
int A[maxN];

struct node {
    int _mx;
    int _2ndmx;

    node() {
        _2ndmx = _mx = INT_MIN;
    }
    node(int val){
        _2ndmx  = INT_MIN;
        _mx = val;
    }

    void merge(node left, node right){

        _2ndmx = min(left._mx,right._mx);
        _2ndmx = max(_2ndmx,max(left._2ndmx,right._2ndmx));
        _mx = max(left._mx,right._mx);
    }

}tree[4*maxN];

void build(int n, int left, int right){

    if(left == right) {
        tree[n] = node(A[left]);
        return;
    }

    int mid = (left+right)/2;

    build(2*n,left,mid);
    build(2*n+1,mid+1,right);

    tree[n] = node();
    tree[n].merge(tree[2*n], tree[2*n+1]);
}

node query(int n , int left , int right, int l , int  r){
    if(left > r || right < l) {
        node temp(-10000000);
        return temp;
    }

    if( left >= l && right <= r) {
        return tree[n];
    }
    int mid = (left+right)/2;

    node l_node = query(2*n,left,mid,l,r);
    node r_node = query(2*n+1,mid+1,right,l,r);

    node boss = node();
    boss.merge(l_node,r_node);
    return boss;
}

void update(int n, int left , int right, int indx , int val) {
    if(right == left) {
        tree[n] = node(val);
        return;
    }

    int mid = (left+right)/2;
    if(indx <= mid)
        update(2*n,left,mid,indx,val);
    else
        update(2*n+1,mid+1,right,indx,val);

    tree[n] = node();
    tree[n].merge(tree[2*n],tree[2*n+1]);
}
int main(){

    fastInput

    int testCase, n, m;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    cin >> m;
    build(1,0,n-1);
    while (m--) {
        char type;
        cin >> type;
        if(type == 'Q') {
            int l, r;
            cin >> l >> r;
            node res = query(1, 0, n - 1, --l, --r);
            cout << res._mx + res._2ndmx << endl;
        } else{
            int indx , val;
            cin >> indx >> val;
            update(1,0,n-1,indx-1,val);
        }
    }

    return 0;
}