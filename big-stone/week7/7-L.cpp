//
// Created by 이동한 on 2025. 12. 28..
//
#include <bits/stdc++.h>
using namespace std;
int N, L[21], J[21], dp[101];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &L[i]);
    for (int i = 0; i < N; i++) scanf("%d", &J[i]);
    // 역방향 dp 갱신
    for (int i = 0; i < N; i++) {
        for (int j = 100; j > L[i]; j--)
            dp[j] = max(dp[j], dp[j - L[i]] + J[i]);
    }
    printf("%d\n", dp[100]);
    return 0;
}
