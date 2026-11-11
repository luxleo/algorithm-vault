//
// Created by 5600G on 2026-11-11.
//
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 301;
int N,M, x1,y1,x2,y2, vst[MAX_N][MAX_N];
bool flag;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
char mp[MAX_N][MAX_N];

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void bfs()
{
    memset(vst,0,sizeof(vst));
    queue<pair<int,int>> q;
    q.emplace(y2,x2);
    vst[y2][x2] = 1;

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i=0; i<4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if (vst[ny][nx]) continue;

            vst[ny][nx] = 1;
            if (mp[ny][nx] == '1') // 쓰러뜨리는데 사용되면 더 이상 진행하지 못한다
            {
                mp[ny][nx] = '0';
                continue;
            }
            q.emplace(ny,nx);
        }
    }

    // 종료조건 달성
    if (vst[y1][x1] == 1) flag = true;
}

int main()
{
    fastIO();
    cin >> N >> M;
    cin >> y1 >> x1 >> y2 >> x2;
    y1--; x1--; y2--; x2--;

    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            cin >> mp[i][j];

    int cnt = 0;
    while (!flag)
    {
        cnt++;
        bfs();
    }

    cout << cnt << '\n';

    return 0;
}
