//
// Created by 5600G on 2026-11-12.
//
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 28;
int N,M, vst[MAX_N],ret = INT_MIN;
const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};
char mp[MAX_N][MAX_N];

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

/**
 * @brief DFS 탐색을 진행하는 재귀 함수
 * @param y 현재 위치의 행 좌표 (y)
 * @param x 현재 위치의 열 좌표 (x)
 * @param num 지금까지 지나온 알파벳들의 방문 상태 (비트마스크 정수)
 * @param cnt 현재까지 지나온 총 칸 수
 */
void go(int y, int x, int num, int cnt){
    // 현재까지 지나온 칸 수로 최댓값(ret) 갱신
    ret = max(ret, cnt);

    // 상, 우, 하, 좌 4방향 탐색
    for(int i = 0; i < 4; i++){
        ny = y + dy[i];
        nx = x + dx[i];

        // 1. 보드 범위를 벗어나는 경우 스킵
        if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;

        // 2. 다음 칸 알파벳의 비트 위치 계산
        // 예: 'A' -> 1<<0 (1), 'B' -> 1<<1 (2), 'C' -> 1<<2 (4)
        int _next = (1 << (int)(a[ny][nx] - 'A'));

        // 3. (num & _next) == 0 : 다음 알파벳을 아직 방문하지 않았다면
        // 비트 OR 연산(num | _next)으로 방문 표시를 더하고 다음 칸으로 재귀 이동
        if((num & _next) == 0) {
            go(ny, nx, num | _next, cnt + 1);
        }
    }
    return;
}

void dfs(int y, int x, int cnt)
{
    bool flag = false;

    for (int i=0; i<4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= 0 && ny < N && nx >= 0 && nx < M && !vst[mp[ny][nx] - 'A'])
        {
            int next_idx = mp[ny][nx] - 'A';
            vst[next_idx] = 1;
            dfs(ny,nx,cnt+1);
            vst[next_idx] = 0;
            flag = true;
        }
    }

    // 더 이상 진행할 수 없었으므로 갱신해준다
    if (!flag)
        ret = max(ret,cnt);
}

int main()
{
    fastIO();
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j=0; j<M; j++)
            cin >> mp[i][j];

    // vst[mp[0][0] - 'A'] = 1;
    // dfs(0,0,1);

    // 3. (0,0) 위치에서 출발
    // 첫번째 칸의 알파벳을 비트로 변환(1 << (a[0][0] - 'A'))하여 첫 방문 처리하고, 지나온 칸 수는 1부터 시작
    go(0, 0, 1 << (int)(a[0][0] - 'A'), 1);

    cout << ret << '\n';
    return 0;
}
