//
// Created by 이동한 on 2025. 9. 14..
//
/** G3 [](https://www.acmicpc.net/problem/15683)
 *
 */
#include <bits/stdc++.h>
using namespace std;

int n, m, a[9][9], temp[9][9], ret = 987654321;;
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
vector<pair<int, int> > v;
vector<vector<vector<int> > > cctvDirs = {
    {},
    {{0}, {1}, {2}, {3}}, // 한방향
    {{0, 2}, {1, 3}}, // 두방향: 서로 반대 방향
    {{0, 1}, {1, 2}, {2, 3}, {3, 0}}, // 두방향: 직각방향
    {{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}}, // 세방향
    {{0, 1, 2, 3}} // 네 방향
};

vector<pair<int, int> > go(int here, int dir) {
    vector<pair<int, int> > changed;
    int y = v[here].first;
    int x = v[here].second;
    int type = a[y][x];

    for (int d: cctvDirs[type][dir]) {
        int ny = y, nx = x;
        while (true) {
            ny += dy[d];
            nx += dx[d];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) break;
            if (a[ny][nx] == 6) break; // 벽인 경우
            if (a[ny][nx] == 0) {
                a[ny][nx] = 8; // 감시 표시
                changed.emplace_back(ny, nx);
            }
        }
    }
    return changed;
}

void dfs(int here) {
    if (here == v.size()) {
        // 카메라 개수만큼 처리하였으면 사각지대 갱신
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 0) cnt++;
            }
        }
        ret = min(ret, cnt);
        return;
    }
    int type = a[v[here].first][v[here].second];
    for (int k = 0; k < (int) cctvDirs[type].size(); k++) {
        // 필요한 만큼만 순회한다.
        vector<pair<int, int> > _change = go(here, k);
        dfs(here + 1);
        for (auto b: _change) a[b.first][b.second] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            // cctv 위치 저장
            if (a[i][j] != 6 && a[i][j] != 0) v.emplace_back(i, j);
        }
    }
    dfs(0);
    cout << ret << endl;
    return 0;
}
