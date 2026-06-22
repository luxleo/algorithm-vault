//
// Created by 5600G on 2026-06-19.
//
#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 51;

int R,C,N,ret,MP[MAX_SIZE][MAX_SIZE],VST[MAX_SIZE][MAX_SIZE];
const int dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};

void dfs(int y, int x)
{
    VST[y][x] = 1;
    for (int i=0; i<4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny > R || ny < 0 || nx > C || nx < 0 || VST[ny][nx] || MP[ny][nx] == 0)
            continue;
        dfs(ny,nx);
    }
}

void bfs(int y, int x)
{
    if (MP[y][x] == 0 || VST[y][x]) return;
    ret++;
    queue<pair<int,int>> q;
    q.emplace(y,x);

    while (!q.empty())
    {
        tie(y,x) = q.front(); q.pop();
        VST[y][x] = 1;
        for (int i=0; i<4; i++)
        {
            int ny = y+dy[i];
            int nx = x+dx[i];
            if (ny > R || ny < 0 || nx > C || nx < 0 || MP[ny][nx] == 0 || VST[ny][nx]) continue;
            q.emplace(ny,nx);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    while (N--)
    {
        memset(MP,0, sizeof(MP));
        memset(VST,0, sizeof(VST));
        ret = 0, R = 0, C = 0;
        int NP,X,Y;
        cin >> R >> C >> NP;
        for (int i=0; i<NP; i++)
        {
            cin >> X >> Y;
            MP[X][Y] = 1;
        }

        // for (int i=0; i<R; i++)
        // {
        //     for (int j=0; j<C; j++)
        //     {
        //         if (MP[i][j] == 1 && VST[i][j] == 0)
        //         {
        //             ret++;
        //             dfs(i,j);
        //         }
        //     }
        // }
        for (int i=0; i<R; i++)
        {
            for (int j=0; j<C; j++)
            {
                bfs(i,j);
            }
        }
        cout << ret << "\n";
    }
}
