//
// Created by 5600G on 2026-11-10.
//
#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 51;
int n,m, mx, vst[MAX_N][MAX_N];
char mp[MAX_N][MAX_N];
const int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};

void bfs(int r, int c)
{
    memset(vst, -1, sizeof(vst));
    queue<pair<int,int>> q;
    q.emplace(r,c);
    vst[r][c] = 0;

    while (!q.empty())
    {
        int y = q.front().first, x = q.front().second;
        q.pop();
        for (int i=0; i<4; i++)
        {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (mp[ny][nx] == 'W') continue;
            if (vst[ny][nx] > -1) continue;
            vst[ny][nx] = vst[y][x] + 1;
            mx = max(mx, vst[ny][nx]);
            q.emplace(ny,nx);
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    // 띄어쓰기 없이 주어지는 문자열 다음과 같이 받으면 된다
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> mp[i][j];

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (mp[i][j] == 'L') bfs(i,j);

    cout << mx << '\n';
    return 0;
}
