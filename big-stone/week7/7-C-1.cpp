//
// Created by 5600G on 2026-11-20.
//
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 51;

int N,M,dp[MAXN][MAXN],vst[MAXN][MAXN];
char mp[MAXN][MAXN];
string s;
const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool isOk(int y, int x)
{
    if (y < 1 || y > N || x < 1 || x > M || mp[y][x] == 'H') return false;
    return true;
}

// DFS + Memoization function: Returns the max moves possible from cell (y, x)
int dfs(int y, int x)
{
    // Base Case 1: If the coin goes out of bounds or falls into a hole ('H'),
    // this move ends the game, so return 0 additional moves.
    if (!isOk(y,x)) return 0;

    // if already visited it means we found cycle!
    if (vst[y][x])
    {
        cout << -1 << '\n';
        exit(0);
    }
    // Memoization Check: Create a reference 'ret' pointing to d[y][x].
    // If d[y][x] is already calculated (non-zero), return the saved answer immediately.
    int &ret = dp[y][x];
    if (ret) return ret;

    vst[y][x] = 1;
    int weight = mp[y][x] - '0';
    for (int i=0; i<4; i++)
    {
        int ny = y + dy[i] * weight;
        int nx = x + dx[i] * weight;
        ret = max(ret, dfs(ny,nx) + 1);
    }
    // Backtracking: Unmark the current cell as we finish exploring all paths from it,
    // so other future paths can visit this cell without falsely triggering a cycle.
    vst[y][x] = 0;
    return ret;
}

int main()
{
    fastIO();
    cin >> N >> M;

    for (int i=1; i<=N; i++)
    {
        cin >> s;
        for (int j=1; j<=M; j++)
            mp[i][j] = s[j-1];
    }

    cout << dfs(1,1) << '\n';
    return 0;
}
