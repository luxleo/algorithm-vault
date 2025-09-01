//
// Created by 이동한 on 2025. 9. 2..
//
/** G4 구현,[3190](https://www.acmicpc.net/problem/3190)
 * 1. 뱀의 경로를 계산하기 위해 deque를 사용한다.
 * 2. 회전을 나타내기 위해 모듈 연산을 사용한다.
 */
#include <bits/stdc++.h>
using namespace std;
#define time ff

int N, K, L, mp[104][104], vst[104][104], y, x;
int t; // 회전 정보를 받기 위함
char r;
int sec; // 경과 초를 표시하기 위함.
vector<pair<int, int> > rots; // 회전 정보를 표시
deque<pair<int, int> > dq; // 뱀의 이동을 나타낸다. (새 위치를 밀어넣고, 꼬리 위치를 제거하고)
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        // 사과가 있는 장소 표시
        cin >> y >> x;
        mp[--y][--x] = 1;
    }
    cin >> L;
    for (int i = 0; i < L; i++) {
        cin >> t >> r;
        // 오른쪽 회전
        if (r == 'D') rots.emplace_back(t, 1);
            // 왼쪽 회전
        else rots.emplace_back(t, 3);
    }
    dq.emplace_back(0, 0);
    int dir = 1;
    int idx = 0;
    while (!dq.empty()) {
        sec++;
        tie(y, x) = dq.front();
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny >= N || ny < 0 || nx >= N || nx < 0 || vst[ny][nx]) break; // 게임 종료조건
        if (mp[ny][nx] == 0) {
            // 사과 없는 경우 이동시켜준다.
            vst[dq.back().first][dq.back().second] = 0;
            dq.pop_back();
        } else {
            mp[ny][nx] = 0; // 사과 먹음 처리, 뱀은 이동하지 않고 길이가 커진다.
        }
        vst[ny][nx] = 1;
        dq.emplace_front(ny, nx);
        if (sec == rots[idx].first) {
            dir = (dir + rots[idx].second) % 4;
            idx++;
        }
    }
    cout << sec << endl;
    return 0;
}
