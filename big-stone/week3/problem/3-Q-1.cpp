//
// Created by 5600G on 2026-11-11.
//
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 6;
int R,C,K,vst[MAXN][MAXN],ret;
char mp[MAXN][MAXN];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void dfs(int r, int c, int cnt)
{
    if (cnt > K)
        return;
    if (r == 0 && c == C-1)
    {
        if (cnt == K)
            ret++;
        return;
    }

    for (int i=0; i<4; i++)
    {
        int ny = r + dy[i];
        int nx = c + dx[i];
        if (ny < 0 || ny >= R || nx < 0 || nx >= C)
            continue;
        if (mp[ny][nx] == 'T')
            continue;
        if (vst[ny][nx])
            continue;
        vst[ny][nx] = 1;
        dfs(ny, nx, cnt+1);
        vst[ny][nx] = 0;
    }
}

int main()
{
    fastIO();
    cin >> R >> C >> K;

    for (int i=0; i<R; i++)
        for (int j=0; j<C; j++)
            cin >> mp[i][j];

    vst[R-1][0] = 1;
    dfs(R-1, 0, 1);
    cout << ret << '\n';

    return 0;
}
