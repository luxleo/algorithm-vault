//
// Created by 5600G on 2026-11-20.
//
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
const int MAX_MOVE = 31;
// dp[idx][tree][cnt]: Stores the max plums Jadu can catch starting from:
// - idx: current second (0 to 1000)
// - tree: current tree Jadu is under (0 for Tree 1, 1 for Tree 2)
// - cnt: number of moves Jadu still has left (0 to 30)
int N,M,a[MAXN],dp[MAXN][2][MAX_MOVE];

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int dfs(int sec, int tree, int move)
{
    // Base Case 1 (Invalid State): If Jadu used more moves than allowed (cnt < 0),
    // return a massive negative number (-1 billion) so max() will never pick this path.
    if (move < 0) return -1e9;

    // Base Case 2 (Time's Up): All T seconds have passed, so 0 more plums can be caught.
    // 이미 초과 되어 더 이상 자두 획득 할 수 없다
    if (sec == N) return 0;

    // Memoization Check: Create a reference 'ret' pointing to this state's DP cell.
    int &ret = dp[sec][tree][move];
    if (~ret) return ret;

    // Decision & Transition:
    // Choice 1: go(idx + 1, tree ^ 1, cnt - 1) -> Move to the other tree (0^1 = 1, 1^1 = 0) and spend 1 move.
    // Choice 2: go(idx + 1, tree, cnt)         -> Stay under the same tree and save moves.
    // Reward: (tree == b[idx] - 1) checks if Jadu's current tree (0 or 1) matches the dropping tree (1-1 or 2-1).
    //         It evaluates to 1 (caught a plum) or 0 (missed).
    return ret = max(dfs(sec+1, tree ^ 1, move - 1), dfs(sec+1, tree, move)) + ((tree == a[sec] - 1) ? 1 : 0);
}

int main()
{
    fastIO();
    cin >> N >> M;

    // Fill the entire DP table with -1 to mark all states as "unvisited".
    // (We use -1 instead of 0 because catching 0 plums is a valid actual answer!)
    memset(dp,-1,sizeof(dp));

    for (int i=0; i<N; i++) cin >> a[i];

    // At second 0, Jadu starts at Tree 1 (index 0), but can choose to move immediately before the first plum falls:
    // - go(0, 1, m - 1): Immediately move to Tree 2 (index 1) at second 0, costing 1 move.
    // - go(0, 0, m):     Stay at Tree 1 (index 0) at second 0, costing 0 moves.
    cout << max(dfs(0,1,M-1), dfs(0,0,M)) << '\n';
    return 0;
}
