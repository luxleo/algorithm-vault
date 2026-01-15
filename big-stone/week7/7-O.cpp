//
// Created by 이동한 on 2026. 1. 15..
//
#include <bits/stdc++.h>
using namespace std;

int n, k, a[14][14], y, x, dir;

struct Point {
    int y, x, dir;
};

vector<int> v[14][14];
vector<Point> status;
const int dy[] = {0, 0, -1, 1};
const int dx[] = {1, -1, 0, 0};

/** @see https://www.acmicpc.net/problem/17837
 * 시뮬레이션 + 비트연산자( 방향전환에 이용) + 맵에 연속된 군체가 있는 경우 (vector<int> [][])
 *
 */
void move(int y, int x, int dir, int id) {
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    // 낙 이거나 파란색인 경우 방향을 바꾸고 이동.
    if (ny < 0 || ny >= n || nx < 0 || nx >= n || a[ny][nx] == 2) {
        status[id].dir ^= 1; // 방향 바꾸는 것을 비트연산을 통해서 한다. (0^1=1, 1^1=0, 2^1 = 3, 3^1= 2)
        ny = y + dy[status[id].dir];
        nx = x + dx[status[id].dir];
        // 만일 또 파란색이거나 아웃이면 문제의 조건에 따라.이동하지 않고 끝낸다
        if (ny < 0 || ny >= n || nx < 0 || nx >= n || a[ny][nx] == 2) return;
    }
    vector<int> &cur_v = v[y][x];
    vector<int> &next_v = v[ny][nx];
    auto pos = find(cur_v.begin(), cur_v.end(), id);
    if (a[ny][nx] == 1) reverse(pos, cur_v.end());; // 빨간색이면 뒤집고 이동시킴
    for (auto it = pos; it != cur_v.end(); it++) {
        // 쌓여있는 동전 모두 옮겨준다.
        next_v.emplace_back(*it);
        status[*it].y = ny;
        status[*it].x = nx;
    }
    cur_v.erase(pos, cur_v.end()); // 이동시킴 처리
}

bool isOver() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (v[i][j].size() >= 4) return true;
    return false;
}

bool go() {
    for (int i = 0; i < status.size(); i++) {
        int y = status[i].y, x = status[i].x, dir = status[i].dir;
        move(y, x, dir, i);
        if (isOver()) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> a[i][j];
    for (int i = 0; i < k; i++) {
        cin >> y >> x >> dir;
        v[--y][--x].emplace_back(i);
        status.push_back({y, x, --dir});
    }
    int cnt = 0;
    bool flag = false;
    while (cnt <= 1000) {
        cnt++;
        if (go()) {
            flag = true;
            break;
        }
    }
    if (flag) cout << cnt << "\n";
    else cout << -1 << "\n";
    return 0;
}
