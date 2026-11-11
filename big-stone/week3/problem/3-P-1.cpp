//
// Created by 5600G on 2026-11-11.
//
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 11;
const int INF = 1e9;
int N,mp[MAX_N][MAX_N],vst[MAX_N][MAX_N],ret = INF;
const int dy[4] = {-1,0,1,0},dx[4] = {0,1,0,-1};

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int cost()
{
    int cost = 0;
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            if (vst[i][j]) cost += mp[i][j];
    return cost;
}

// 꽃이 심은자리에서 온전히 필 수 있는지 검사
bool check(int y, int x)
{
    if (vst[y][x]) return false;
    for (int i=0; i<4; i++)
    {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny<0 || ny>=N || nx<0 || nx>=N) return false;
        if (vst[ny][nx]) return false;
    }
    return true;
}

void dfs(int y, int x, int cnt)
{
    if (cnt==3)
    {
        ret = min(ret, cost());
        return;
    }
    if (y<0 || y>=N || x<0 || x>=N) return;

    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            if (check(i,j))
            {
                vst[i][j] = 1;
                for (int k=0; k<4; k++)
                {
                    int ny = i + dy[k], nx = j + dx[k];
                    vst[ny][nx] = 1;
                }
                dfs(i, j, cnt+1);
                for (int k=0; k<4; k++)
                {
                    int ny = i + dy[k], nx = j + dx[k];
                    vst[ny][nx] = 0;
                }
                vst[i][j] = 0;
            }
        }
    }
}

int main()
{
    fastIO();
    cin >> N;
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            cin >> mp[i][j];

    dfs(0,0,0);
    cout << ret;
    return 0;
}
