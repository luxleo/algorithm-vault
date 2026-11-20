//
// Created by 5600G on 2026-11-20.
//
#include <bits/stdc++.h>
using namespace std;

// Good naming practice: clear constants prevent mixing up N and health limits!
const int MAXN = 21;
const int MAX_HEALTH = 101;

// N: number of people (up to 20)
// L[i]: health lost when greeting person 'i'
// J[i]: joy gained when greeting person 'i'
// dp[j]: maximum joy achievable when starting with 'j' health without dying (health > 0)
int N, L[MAXN], J[MAXN], dp[MAX_HEALTH], health = 100;

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    fastIO();

    // Read number of people, health costs L[], and joy rewards J[]
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> L[i];
    for (int i = 0; i < N; i++)
        cin >> J[i];

    // Process each person one by one (0/1 Knapsack)
    for (int i = 0; i < N; i++) {
        // Backward Loop (ensures each person is greeted at most ONCE):
        // Notice the strict inequality 'j > L[i]' instead of 'j >= L[i]'.
        // At j = 100, this only allows greeting person 'i' if 100 > L[i] (leaving >= 1 health),
        // and looks up dp[100 - L[i]] which itself only used up to (100 - L[i] - 1) health!
        for (int j = 100; j > L[i]; j--) {
            // Compare:
            // 1) dp[j]: max joy with 'j' health without greeting person 'i'
            // 2) dp[j - L[i]] + J[i]: max joy with remaining health (j - L[i]) + joy from person 'i'
            dp[j] = max(dp[j], dp[j - L[i]] + J[i]);
        }
    }

    // Print the maximum joy achievable starting with 100 health (with at least 1 health left)
    cout << dp[100] << '\n';

    return 0;
}
