#include <bits/stdc++.h>
template<class T, class U, class O, class P> T arrayOutofBoundary(T r, U c, O m, P n) {
    return r < 0 || c < 0 || r == m || c == n;
}
using namespace std;
int dx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = {-1, +1, +0, +0, +1, +1, -1, -1};
vector<string>v;
bool visited[50][50];
int n,m;
/************************************* flood ************/
int flood(int a, int b) {
    visited[a][b] = true;
    int cnt = 1;
    for (int i = 0; i < 4; ++i) {
        int ix = a + dx[i];
        int iy = b + dy[i];
        if(!arrayOutofBoundary(ix,iy,n,m)) {
            if(v[a][b] == v[ix][iy] && !visited[ix][iy])
                cnt += flood(ix,iy);
        }
    }
}

int main(){

}
