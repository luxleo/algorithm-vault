//
// Created by 5600G on 2026-11-10.
//
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 51;
int n,l,r, mp[MAX_N][MAX_N], vst[MAX_N][MAX_N],res;
bool isUpdated = false;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

bool bfs(int r, int c)
{
    vector<pair<int,int>> points;
    queue<pair<int,int>> q;
    vst[r][c] = 1;
    points.emplace_back(r,c);
    q.emplace(r,c);

    // 시작 위치에서 국경을 넓힐 수 있는지 탐색한다
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i=0; i<4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny>=0 && ny<n && nx>=0 && nx<n && !vst[ny][nx] && l<=abs(mp[ny][nx]-mp[y][x]) && abs(mp[ny][nx]-mp[y][x])<=r)
            {
                vst[ny][nx] = 1;
                q.emplace(ny,nx);
                points.emplace_back(ny,nx);
                isUpdated = true;
            }
        }
    }

    // 국경을 넓힌 경우 이동시킨다
    if (isUpdated)
    {
        int sum = 0;
        for (auto [y,x] : points)
        {
            sum += mp[y][x];
        }

        for (auto [y,x] : points)
        {
            mp[y][x] = sum / points.size();
        }
    }

    return isUpdated;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l >> r;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> mp[i][j];

    int cnt = 0;
    do
    {
        // 하루 별로 탐색을 초기화한다
        isUpdated = false;
        memset(vst, 0, sizeof(vst));
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                if (!vst[i][j])
                    isUpdated = bfs(i,j);
        if (isUpdated) cnt++;
    } while (isUpdated);

    cout << cnt << '\n';

    return 0;
}
