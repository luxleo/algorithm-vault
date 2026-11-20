//
// Created by 5600G on 2026-11-20.
//
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10001;

int n,b1,b2, cal,c1,c2, dp[MAXN];


int main()
{
    while (true)
    {
        scanf("%d %d.%d", &n, &b1, &b2);
        if (n == 0) break;

        memset(dp, 0, sizeof(dp));
        int budget = b1*100 + b2;

        for (int i=0; i<n; i++)
        {
            scanf("%d %d.%d", &cal, &c1, &c2);
            int cost = c1*100 + c2;

            // Forward Loop (Unbounded Knapsack):
            // Sweep from candy price 'p' up to total budget 'cost'.
            // Going forward lets us buy the same candy multiple times in one pass.
            for (int j = cost; j <= budget; j++)
            {
                // Compare:
                // 1) dp[j]: best calories for 'j' cents without buying this candy again
                // 2) dp[j - p] + c: best calories for (j - p) cents + calories 'c' of this candy
                dp[j] = max(dp[j], dp[j-cost] + cal);
            }
        }

        printf("%d\n", dp[budget]);
    }
    return 0;
}
