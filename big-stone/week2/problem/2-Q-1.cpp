//
// Created by 5600G on 2026-11-05.
//
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100;
int N,M, mp[MAX_N][MAX_N], vst[MAX_N][MAX_N],ret, current;
const int dy[4] = {0, 0, 1, -1};
const int dx[4] = {1, -1, 0, 0};

int melt()
{
    vector<pair<int,int>> melt_list;
    for (int y=0; y< N; y++)
    {
        for (int x=0; x<M; x++)
        {
            if (mp[y][x] == 0) continue;
            for (int k=0; k<4; k++)
            {
                int ny = y + dy[k];
                int nx = x + dx[k];
                if (mp[ny][nx] == 0)
                {
                    melt_list.emplace_back(y,x);
                    continue;
                }
            }
        }
    }

    for (auto & i : melt_list)
    {
        mp[i.first][i.second] = 0;
    }

    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            if (mp[i][j] != 0) current++;
    return current;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] != 0) ret++; // 처음 치즈 갯수 세아리기
        }

    current = ret;

    // 치즈 다 없어질 때 까지 돌림
    while (current > 0)
    {
        int remained = melt();
        if (remained > 0) ret = min(ret, remained);
    }

    cout << ret << '\n';
    return 0;
}
