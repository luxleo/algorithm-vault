//
// Created by 이동한 on 2025. 11. 7..
//

/** @see https://www.acmicpc.net/problem/2294 G5
 * 냅색문제이다.
 * 냅색 문제는 사용할 수 있는 동전의 갯수의 제한에 따라 갱신 방향이 달라진다.
 * 1. 만일 동전의 개수에 제한이 없다면 왼쪽에서 오른쪽으로 진행하며 dp를 '갱신'한다.
 * 2. 만일 동전을 단 한번만 사용할 수 있다면 오른쪽에서 왼쪽으로 진행하며 갱신한다.
 *
 * 이번 문제는 1번 유형의 문제이다.
 */
#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321; // 최솟값을 갱신할 때는 가장 큰 값을 먼저 정하고 갱신해 나간다.
int n, k, temp, dp[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fill(dp, dp + 10001, INF); // dp를 0,1로 초기화하는 경우를 제외하면 fill을 이용한다.
    dp[0] = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        for (int j = temp; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - temp] + 1); // dp[j] = min(dp[j], dp[j-temp] + 1) 를 실행하여 갱신한다.
        }
    }
    if (dp[k] == INF) cout << -1 << "\n";
    else cout << dp[k] << "\n";
    return 0;
}
