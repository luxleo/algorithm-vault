//
// Created by 5600G on 2026-11-20.
//
#include <bits/stdc++.h>
using namespace std;

const int MAXK = 100001;
const int MAXN = 101;

int n,k,w,v,dp1[MAXK][MAXN], dp2[MAXK];
vector<pair<int,int>> vv;


void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// Recursive DP function returning max value from state (remaining weight, current item index)
int go(int weight, int here)
{
    // Base Case: No items left to consider (idx == n) OR backpack is completely full (weight == 0)
    if (here == n || weight == 0) return 0;
    // Memoization Check: If this state was already computed (not -1), return the cached answer
    int &ret = dp1[weight][here];
    if (~ret) return ret;

    // case 1 here 에 해당하는 물건 안 담고 넘어감
    ret = go(weight, here + 1);

    // case 2 here 에 해당하는 물건 담고 넘어감
    if (weight - vv[here].first >= 0)
        ret = max(ret, go(weight - vv[here].first, here + 1) + vv[here].second);

    return ret;
}

void sol1()
{
    // dp1[weight][idx]: Stores the max value achievable using items from 'idx' to 'n-1'
    // with 'weight' capacity remaining in the backpack.
    for (int i=0; i<n; i++)
    {
        cin >> w >> v;
        vv.emplace_back(w,v);
    }

    // Initialize the entire 2D DP table with -1 ("unvisited"), because 0 is a valid answer
    fill(&dp1[0][0], &dp1[0][0] + MAXK * MAXN, -1);

    cout << go(k,0);
}

void sol2()
{
    for (int i=0; i<n; i++)
    {
        cin >> w >> v;
        // Backward Loop (0/1 Knapsack Key Trick):
        // Sweep from max capacity 'k' DOWN to item weight 'w'.
        // Going backward ensures that dp[j - w] still holds the result from BEFORE
        // the current item was added, preventing the same item from being packed twice!
        for (int j= k; j >= w; j--)
            // Compare:
                // 1) dp[j]: max value at weight 'j' without taking this item
                    // 2) dp[j - w] + v: max value at weight (j - w) + this item's value 'v'
            dp2[j] = max(dp2[j-w] + v, dp2[j]);
    }
    cout << dp2[k] << '\n';
    return;
}

int main()
{
    fastIO();
    cin >> n >> k;

    // sol1();
    sol2();
    return 0;
}
