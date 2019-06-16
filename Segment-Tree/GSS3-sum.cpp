//
// Created by Xenon on 20-May-19.
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
    int _best;
    int _prefixBest;
    int _sufixBest;
    int _totalSum;

    node() {
        _best = _prefixBest = _sufixBest = _totalSum = 0;
    }
    node(int val){
        _best = _prefixBest = _sufixBest = _totalSum = val;
    }

    void merge(node left, node right){
        _prefixBest = max(left._prefixBest,left._totalSum+right._prefixBest);
        _sufixBest = max(right._sufixBest,right._totalSum+left._sufixBest);
        _totalSum = left._totalSum + right._totalSum;
        _best = max(left._best,max(right._best,left._sufixBest+right._prefixBest));
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
        node temp(-1000000);
        temp._totalSum = 0;
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
        int type;
        cin >> type;
        if(type) {
            int l, r;
            cin >> l >> r;
            cout << query(1, 0, n - 1, --l, --r)._best << endl;
        } else{
            int indx , val;
            cin >> indx >> val;
            update(1,0,n-1,indx-1,val);
        }
    }

    return 0;
}