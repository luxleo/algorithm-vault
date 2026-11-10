//
// Created by 5600G on 2026-11-10.
//
#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1001;

int r,c, vstj[MAX_N][MAX_N], vstf[MAX_N][MAX_N];
int iyj, ixj, iyf, ixf;
char mp[MAX_N][MAX_N];
const int dy[4] = {0, 0, 1, -1};
const int dx[4] = {1, -1, 0, 0};
const int INF = 1e9;

int bfs(int r, int c)
{
    int res = INF;
    queue<pair<int,int>> qj;
    queue<pair<int,int>> qf;
    vstj[r][c] = 0;
    qj.emplace(r,c);
    vstf[iyf][ixf] = 0;
    qf.emplace(iyf,ixf);

    // 불을 먼저 이동시켜 j의 이동시간과 같으면 지나갈 수 없는 경로이다
    while (!qf.empty())
    {
        int y = qf.front().first, x = qf.front().second;
        qf.pop();
        for (int i=0; i<4; i++)
        {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny<0 || ny>=r || nx<0 || nx >= c) continue;
            if (mp[ny][nx] == '#') continue;
            if (vstf[ny][nx] != -1) continue;
            vstf[ny][nx] = vstf[y][x] + 1;
            qf.emplace(ny,nx);
        }
    }

    while (!qj.empty())
    {
        int y = qj.front().first, x = qj.front().second;
        qj.pop();
        for (int i=0; i<4; i++)
        {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny<0 || ny>=r || nx<0 || nx >= c) continue;
            if (mp[ny][nx] == '#') continue;
            if (vstj[ny][nx] != -1) continue;
            if (vstf[ny][nx] <= vstj[ny][nx]) continue; // 불길은 지나갈 수 없음
            if (ny == r-1 || nx == c - 1) res = min(res, vstj[y][x] + 1);
            vstj[ny][nx] = vstj[y][x] + 1;
            qj.emplace(ny,nx);
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(vstj, -1, sizeof(vstj));
    memset(vstf, -1, sizeof(vstf));
    cin >> r >> c;
    for (int i=0; i<r; i++)
        for (int j=0; j<c; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j]=='J')
            {
                iyj = i;
                ixj = j;
            }
            else if (mp[i][j]=='F')
            {
                iyf = i;
                ixf = j;
            }
        }
    int res = bfs(iyj, ixj);
    if (res == INF)
    {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }

    cout << res << '\n';

    return 0;
}
