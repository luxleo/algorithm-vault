#include <chrono>
#include <cstring>
#include <iostream>
//
// Created by 5600G on 2025-10-24.
//
using namespace std;
typedef long long ll;
ll dp[101];

ll bottom_up(int num)
{
    if (num < 1) return 0;
    memset(dp, -1, sizeof(dp));
    if (num == 1) return 1;
    dp[0] = 0;
    dp[1] = 1;
    for (int i=2; i<=num; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[num];
}

ll top_down(int idx, int num)
{
    if (idx <= 1) return idx;
    ll &ret = dp[idx];
    if (ret != -1) return ret;
    return ret = top_down(idx - 1, num) + top_down(idx - 2, num);
}

int main()
{
    int targetNum = 7;
    cout << "fibo to " << targetNum << "\n";
    chrono::system_clock::time_point start = chrono::system_clock::now();
    cout << "bottom up: " << bottom_up(targetNum) << "\n";
    chrono::system_clock::time_point end = chrono::system_clock::now();
    cout << "time: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms\n";
    memset(dp, -1, sizeof(dp));

    start = chrono::system_clock::now();
    cout << "top down: " << top_down(targetNum, targetNum) << "\n";
    end = chrono::system_clock::now();
    cout << "time: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms\n";
    return 0;
}

// 1 1 2 3 5 8 13 21 35 56 91 147 238