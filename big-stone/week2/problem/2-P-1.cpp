//
// Created by 5600G on 2026-11-05.
//
#include <bits/stdc++.h>
using namespace std;

int N,M, mp[8][8], vst[8][8],ret;
vector<pair<int,int>> virus, wall;
const int dy[4] = {-1,1,0,1}, dx[4] = {0,0,-1,1};

void dfs(int y, int x)
{
    vst[y][x] = 1;
    mp[y][x] = 2;
    for (int i=0; i<4; i++)
    {
        int ny = y+ dy[i];
        int nx = x + dx[i];
        if (ny >= N || nx < 0 || vst[ny][nx] || mp[ny][nx] != 0) continue;
        dfs(ny,nx);
    }
}

int solve()
{
    fill(&vst[0][0], &vst[0][0] + 8*8, 0);
    int count = 0;
    // 바이러스 유포

    for (pair<int,int> p : virus)
    {
        dfs(p.first, p.second);
    }

    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            if (mp[i][j] == 0 && !vst[i][j])
                count++;
        }
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            // 주의
            cin >> mp[i][j];
            if (mp[i][j] == 2)
                virus.emplace_back(i,j);
            else if (mp[i][j] == 0)
                wall.emplace_back(i,j);
        }
    }
    // 리스트의 모든 조합을 구하는 순회문인데 직관적이지 않다 더 직관적인 방법 =>
    for (int i=0; i<wall.size(); i++)
    {
        for (int j=0; j< i; j++)
        {
            for (int k=0; k< j; k++)
            {
                // 벽 조합으로 세팅
                mp[wall[i].first][wall[i].second] = 1;
                mp[wall[j].first][wall[j].second] = 1;
                mp[wall[k].first][wall[k].second] = 1;
                ret = max(ret, solve());
                // 원복
                mp[wall[i].first][wall[i].second] = 0;
                mp[wall[j].first][wall[j].second] = 0;
                mp[wall[k].first][wall[k].second] = 0;
            }
        }
    }

    cout << ret << "\n";
    return 0;
}
