//
// Created by 5600G on 2026-11-19.
//
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 9;
int n,m,a[MAXN][MAXN],ret = INT_MAX;

// 시계 방향 순서 위,오른쪽,아래,왼쪽
const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};

vector<pair<int,int>> v;
// [핵심] 1번~5번 CCTV가 기준 방향(dir)으로부터 추가로 감시하는 회전 오프셋 표
const vector<vector<int>> cctvDir = {
    {},             // 0번 (빈 칸이므로 미사용)
    {0},            // 1번 CCTV
    {0, 2},         // 2번 CCTV
    {0, 1},         // 3번 CCTV
    {0, 1, 2},      // 4번 CCTV
    {0, 1, 2, 3}    // 5번 CCTV
};

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<pair<int,int>> extendCCTV(int here, int dir)
{
    vector<pair<int,int>> changed = {};
    int y = v[here].first, x = v[here].second;

    for (int offset : cctvDir[a[y][x]])
    {
        int ny = y, nx = x;
        int curDir = (dir + offset) % 4;

        while (true)
        {
            ny += dy[curDir];
            nx += dx[curDir];
            if (ny < 0 || ny >=n || nx<0 || nx>=m || a[ny][nx] == 6) break;
            if (a[ny][nx] == 0)
            {
                a[ny][nx] = 8;
                changed.push_back({ny,nx});
            }
        }
    }
    return changed;
}

/**
 *
 * @param here 회전 시킬 cctv 번호
 */
void dfs(int here)
{
    if (here == v.size())
    {
        int cnt = 0;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                if (a[i][j] == 0) cnt++;

        ret = min(ret, cnt);
        return;
    }
    for (int i=0; i<4; i++)
    {
        vector<pair<int,int>> changed = extendCCTV(here,i);
        dfs(here + 1);
        // 백트래킹 원복 시켜준다
        for (auto [y,x] : changed)
            a[y][x] = 0;
    }
}

int main()
{
    fastIO();
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin >> a[i][j];
            // cctv 위치 넣어줌
            if (a[i][j] != 0 && a[i][j] != 6) v.push_back({i,j});
        }

    dfs(0);

    cout << ret << '\n';
    return 0;
}
