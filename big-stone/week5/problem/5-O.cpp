//
// Created by 이동한 on 2025. 9. 2..
//
/** G4 (https://www.acmicpc.net/problem/17406)
 * 배열을 양파처럼 층별로 돌리는 문제였다.
 * 갱신 순서(dy,dx)가 중요하였음.
 * 새로운 구조체(Rotation)을 정의하고 생성하는 경험 처음임.
 */
#include <bits/stdc++.h>
using namespace std;
int N, M, K, mp[54][54], temp[54][54], vst[54][54];
const int INF = 987654321;
int ret = INF;
const int dy[] = {0, 1, 0, -1}; // Right, Down, Left, Up
const int dx[] = {1, 0, -1, 0};
int sy, sx, ey, ex, dir;

struct Rotation {
    int r, c, s;
};

vector<Rotation> ops;
vector<int> op_orders;
vector<pair<int, int> > path;

void traceLayer(int y, int x, bool first) {
    if (!first && y == sy && x == sx) dir++;
    if (!first && y == sy && x == ex) dir++;
    if (!first && y == ey && x == ex) dir++;
    if (!first && y == ey && x == sx) dir++;
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if (vst[ny][nx]) return;
    vst[ny][nx] = 1;
    path.emplace_back(ny, nx);
    traceLayer(ny, nx, 0);
}

void rotateAll(int y, int x, int range) {
    for (int i = 1; i <= range; i++) {
        sy = y - 1 * i;
        sx = x - 1 * i;
        ey = y + 1 * i;
        ex = x + 1 * i;
        path.clear();
        dir = 0;
        memset(vst, 0, sizeof(vst)); // 배열 전체 초기화
        vst[sy][sx] = 1;
        path.emplace_back(sy, sx);
        traceLayer(sy, sx, 1);

        vector<int> shell;
        for (auto &pos: path) {
            shell.push_back(temp[pos.first][pos.second]);
        }
        // 요게 핵심 -> 원형의 층을 일차원 배열로 두고 한칸씩 밀어줌.
        rotate(shell.rbegin(), shell.rbegin() + 1, shell.rend());

        // 한칸씩 회전시킨 배열로 임시배열 초기화
        for (int i = 0; i < path.size(); i++) {
            temp[path[i].first][path[i].second] = shell[i];
        }
    }
}

int solve() {
    for (int i: op_orders) rotateAll(ops[i].r, ops[i].c, ops[i].s);
    int minSum = INF;
    for (int i = 0; i < N; i++) {
        int acc = 0;
        for (int j = 0; j < M; j++) {
            acc += temp[i][j];
        }
        minSum = min(minSum, acc);
    }
    return minSum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> mp[i][j];
        }
    }
    int r, c, s;
    for (int i = 0; i < K; i++) {
        cin >> r >> c >> s;
        ops.push_back({--r, --c, s}); // 인덱스 맞춰주기위해서 -1해줌
        op_orders.emplace_back(i);
    }

    do {
        memcpy(temp, mp, sizeof(mp));
        ret = min(ret, solve());
    } while (next_permutation(op_orders.begin(), op_orders.end())); // 순열 next_permutation(begin,end) 로 쉽게 구하기
    cout << ret << endl;
    return 0;
}
