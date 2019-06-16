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
const int maxN = 2e5+7;
map<ll,ll>compress;
vector< pair<ll,ll> >seg(maxN), qq(maxN);
ll cnt[maxN];
ll tree[4*maxN];
void build(int node,ll int left,ll int right){
    if(left == right)
    {
        tree[node] = cnt[left];
        return;
    }
    ll int mid = (left+right)/2;
    build(2*node,left,mid);
    build(2*node+1,mid+1,right);
    tree[node] = max(tree[2*node],tree[2*node+1]);
}

ll int query(int node, int left, int right,ll int l,ll int r) {
    if(left > r || right < l)
        return INT_MIN;
    if( left >= l && right <= r){
        return tree[node];
    }
    int mid = (left+right)/2;
    return max(query(2*node,left,mid,l,r)
            ,query(2*node+1,mid+1,right,l,r));

}

int main(){
    //fileIn
    fastInput

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        ll l,r;
        cin >> l >> r;
        seg[i].first = l;
        seg[i].second = r;
        compress[l] = compress[r] = 1;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        ll l,r;
        cin >> l >> r;
        qq[i].first = l;
        qq[i].second = r;

        compress[l] = compress[r] = 1;
    }

    ll a = 0;
    for(auto &x: compress)
        x.second = a++;
    for(int i = 0; i < n ; i++)
    {
        cnt[compress[seg[i].first]]++;
        cnt[compress[seg[i].second]+1]--;
    }
    for(int i = 0; i < maxN; i++)
        cnt[i] += cnt[i-1];

    build(1,0,maxN-1);
    for (int i = 0; i < q; ++i) {
        ll int x = compress[qq[i].first];
        ll int y = compress[qq[i].second];
        cout << query(1,0,maxN-1,x,y) << endl;
    }
    return 0;
}
