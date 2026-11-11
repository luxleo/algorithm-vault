//
// Created by 5600G on 2026-11-11.
//
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1501;
const int dy[4] = {-1,1,0,0}, dx[4] = {0,0,1,-1};
int R,C, vst[MAX_N][MAX_N];
char mp[MAX_N][MAX_N];
vector<pair<int,int>> pos; // 종료조건 달성하는지 bfs 돌릴 위치 저장
bool flag = false;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void bfs(int y, int x)
{
    memset(vst, 0, sizeof(vst));
    queue<pair<int,int>> q;
    vst[y][x] = 1;
    q.emplace(y,x);
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i=0; i<4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx >= R || ny < 0 || nx >= C) continue;
            if (vst[ny][nx]) continue;
            if (mp[ny][nx] == '#')
            {
                mp[ny][nx] = '.';
                continue;
            }

            q.emplace(ny,nx);
            vst[ny][nx] = 1;
        }
    }
}

void bfs_check()
{
    memset(vst,0,sizeof(vst));
    pair<int,int> start = pos[0];
    pair<int,int> end = pos[1];

    queue<pair<int,int>> q;
    q.emplace(start.first,start.second);
    vst[start.first][start.second] = 1;

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i=0; i<4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx >= R || ny < 0 || nx >= C) continue;
            if (vst[ny][nx]) continue;
            if (mp[ny][nx] == '#') continue;
            if (ny == end.first && nx == end.second)
            {
                flag = true;
                return;
            }
            vst[ny][nx] = 1;
            q.emplace(ny,nx);
        }
    }
}

int main()
{
    fastIO();
    cin >> R >> C;
    for (int i=0; i<R; i++)
        for (int j=0; j<C; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == 'L')
                pos.emplace_back(i, j);
        }

    int res = 0;

    while (!flag)
    {
        for (int i=0; i<R; i++)
            for (int j=0; j<C; j++)
                bfs(i,j);
        res++;

        bfs_check();
    }

    cout << res << '\n';

    return 0;
}
