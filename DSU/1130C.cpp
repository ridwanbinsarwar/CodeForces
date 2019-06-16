#include <bits/stdc++.h>
using namespace std;

int rep[4000];
int rnk[4000];

void make_set(int x) {
    rep[x] = x;
    rnk[x] = 0;
}

int find_p(int x) {
    if(rep[x] == x ) return x;
    return rep[x] = find_p(rep[x]);
}

void union_rank(int x, int y) {
    int px = find_p(x);
    int py = find_p(y);

    if( px != py) {
        if(rnk[px] < rnk[py])
            swap(px,py);
        rep[py] = px;
        if(rnk[px] == rnk[py] )
            rnk[px]++;
    }
}



int main() {


    int n;
    cin >> n;
    for (int i = 0; i <= 4000; ++i) {
        make_set(i);
    }
    int r1,c1,t1,t2;
    cin >> r1 >> c1;
    cin >> t1 >> t2;
    vector<string>v;
    for (int i = 0; i < n; ++i) {
        string temp;
        cin >> temp;
        v.push_back(temp);
    }
    r1-- , c1--, t1--,t2--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if(v[i][j] == '0') {
                if(i!=0 && v[i-1][j] == '0')
                    union_rank(i*n+j,(i-1)*n+j);
                if(i!=n-1 && v[i+1][j] == '0')
                    union_rank(i*n+j,(i+1)*n+j);
                if(j!=n-1 && v[i][j+1] == '0')
                    union_rank(i*n+j,i*n+j+1);
                if(j!=0 && v[i][j-1] == '0')
                    union_rank(i*n+j,i*n+j-1);
            }
        }
    }

    vector< pair<int,int> > vpair_s;
    vector< pair<int,int> > vpair_f;

    for (int i = 0; i <n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(find_p(r1*n+c1) == find_p(i*n+j))
                vpair_s.emplace_back(i,j);
            if(find_p(t1*n+t2) == find_p(i*n+j))
                vpair_f.emplace_back(i,j);
        }
    }

    if(find_p(r1*n+c1) == find_p(t1*n+t2)) {
        cout << 0 << endl;
        return 0;
    }
    int ans = INT_MAX;
    for (auto &vpair_ : vpair_s) {
        for (auto &j : vpair_f) {
            ans = min(ans,(vpair_.first - j.first)*(vpair_.first - j.first)+
                          (vpair_.second - j.second)*(vpair_.second - j.second));
        }
    }
    cout << ans << endl;
}