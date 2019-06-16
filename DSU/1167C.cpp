#include <bits/stdc++.h>
using  namespace std;
int rep[500005];
int rnk[500005];
int cnt[500005];

void make_set(int x) {
    rep[x] = x;
    rnk[x] = 0;
}

int find_p(int x) {
    if(rep[x] == x) return x;
    return rep[x] = find_p(rep[x]);
}

void union_rank(int x, int y) {
    int px = find_p(x);
    int py = find_p(y);
    if( px != py ){
        if(rnk[px] < rnk[py])
            swap(px,py);
        rep[py] = px;
        if( rnk[px] == rnk[py])
            rnk[px]++;
    }
}

int main() {
    memset(cnt, 0, sizeof(cnt));
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        make_set(i);
    }

    for (int i = 1; i <=m; ++i) {

        int k;
        cin >> k;
        vector<int>v;

        for (int j = 0; j < k; ++j) {
            int t;
            cin >> t;
            v.push_back(t);
        }

        for (int i = 1; i <k; ++i) {
            int y = v[0];
            int cur = v[i];
            union_rank(cur,y);
        }
    }

    for (int i = 1; i <=n; ++i) {
        int p = find_p(i);
        cnt[p]++;
    }
    for (int i = 1; i <=n; ++i) {
        int p = find_p(i);
        cout << cnt[p] << " ";
    }
    cout << "\n";
    return 0;
}