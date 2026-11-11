//
// Created by 5600G on 2026-11-11.
//
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 21;
int R,C, vst[27],ret;
char mp[MAX_N][MAX_N];

const int dy[] = {-1,1,0,0};
const int dx[] = {0,0,-1,1};

void dfs(int y, int x, int cnt)
{
    ret = max(ret, cnt);
    for (int i=0; i<4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >=R || nx < 0 || nx >=C) continue;
        int next = mp[ny][nx] - 'A';
        if (vst[next]) continue;

        vst[next] = 1;
        dfs(ny,nx, cnt+1);
        vst[next] = 0;
    }
}

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    fastIO();
    cin >> R >> C;
    for (int i=0; i<R; i++)
        for (int j=0; j<C; j++)
            cin >> mp[i][j];

    vst[mp[0][0] - 'A'] = 1;
    dfs(0,0,1);

    cout << ret << '\n';
    return 0;
}
