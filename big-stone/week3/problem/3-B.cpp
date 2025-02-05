#include <bits/stdc++.h>
using namespace std;

/**
 * 
 * @see 
 */
int N,M, vst[51][51],ans;
int dy[] = {-1,1,0,0};
int dx[] = {0,0, -1,1};
char arr[51][51];
vector<pair<int,int>> landPos;
void bfs(int iy, int ix) {
    queue<pair<int,int>> q;
    vst[iy][ix] = 1;
    q.push({iy,ix});

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (nx < 0 || ny < 0 || nx >=M || ny >=N || vst[ny][nx] || arr[ny][nx] == 'W') continue;
            vst[ny][nx] = vst[y][x] + 1;
            q.push({ny,nx});
            ans = max(ans, vst[ny][nx]);
        }
    }
}
int main() {
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> arr[i][j]; // (0) 연속한 문자열 받는 방법
            if (arr[i][j] == 'L') landPos.emplace_back(i,j);
        }
    }
    for (auto [y,x] : landPos) {
        memset(vst,0,sizeof(vst));
        bfs(y,x);
    }
    cout << ans - 1 << "\n";
    return 0;
}
