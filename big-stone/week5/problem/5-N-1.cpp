//
// Created by 5600G on 2026-11-18.
//
#include <bits/stdc++.h>
using namespace std;

int n, k, l, y, x, t, ret, idx, dir = 1;
int a[104][104], visited[104][104], cur_time;
char c;
deque<pair<int, int>> dq;
vector<pair<int, int>> _time;
// dir과 일치하도록 dy, dx 잘 맞춰 줘야한다.
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main()
{
    fastIO();
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        cin >> y >> x;
        a[--y][--x] = 1;
    }

    cin >> l;
    for(int i = 0; i < l; i++){
        cin >> t >> c;
        if(c == 'D') _time.push_back({t, 1});
        else _time.push_back({t, 3});
    }
    // 뱀 초기위치 입력
    dq.push_back({0, 0});
    visited[0][0] = 1; // [수정 2] 시작 칸 (0, 0)에도 뱀 몸통이 있음을 반드시 표시

    while (!dq.empty())
    {
        cur_time++;
        tie(y,x) = dq.front();
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) break;
        if (a[ny][nx] == 0)
        {
            visited[dq.back().first][dq.back().second] = 0;
            dq.pop_back();
        } else
        {
            a[ny][nx] = 0;
        }

        visited[ny][nx] = 1;
        dq.push_front({ny, nx});

        // 현재 초(time)가 끝난 뒤 방향을 회전해야 할 타이밍인지 확인
        if(idx < l && cur_time == _time[idx].first){
            dir = (dir + _time[idx].second) % 4; // 0 ~ 3 범위 내에서 90도 회전
            idx++;                               // 다음 방향 전환 명령을 가리키도록 인덱스 증가
        }
    }

    // 5. 게임이 끝난 시각(초) 출력
    cout << cur_time << "\n";
    return 0;
}
