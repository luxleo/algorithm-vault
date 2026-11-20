//
// Created by 5600G on 2026-11-20.
//
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000001;
const int INF = 1e9;
int n, dp[MAXN];

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// Path Reconstruction Function: Prints the sequence of numbers from 'here' down to 1
void go(int here)
{
    // Base Case: Stop once we pass 1 (when here becomes 0)
    if (here == 0) return;
    cout << here << ' ';
    // Check which of the 3 operations actually produced the optimal score dp[here]:
    // 1. Did we come from (here / 3)? Only valid if 'here' is divisible by 3 and its cost is 1 less.
    if (here % 3 == 0 && dp[here] == dp[here/3] + 1) go(here/3);
    else if (here % 2 == 0 && dp[here] == dp[here/2] + 1) go(here/2);
    else if (dp[here] == dp[here-1] + 1) go(here-1);
}

int main()
{
    fastIO();
    cin >> n;
    fill(dp, dp+MAXN, INF);
    dp[1] = 0;

    // Bottom-Up DP: Calculate the minimum operations for every number from 1 up to n
    for (int i=1; i<=n; i++)
    {
        // Option 1: If 'i' is divisible by 3, compare current best with (operations for i/3) + 1
        // Note: '!(i % 3)' is a shorthand for '(i % 3 == 0)'
        if (i % 3 == 0) dp[i] = min(dp[i/3] + 1,dp[i]);
        // Option 2: If 'i' is divisible by 2, compare current best with (operations for i/2) + 1
        if (i % 2 == 0) dp[i] = min(dp[i/2] + 1,dp[i]);
        // Option 3: Compare current best with (operations for i - 1) + 1
        // (For i = 1, dp[0] is INF, so min(INF + 1, 0) safely keeps dp[1] = 0)
        dp[i] = min(dp[i-1] + 1, dp[i]);
    }

    cout << dp[n] << '\n';
    go(n);
    return 0;
}
