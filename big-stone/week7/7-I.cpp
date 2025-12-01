//
// Created by 이동한 on 2025. 12. 2..
//
/** @see https://www.acmicpc.net/problem/4781
 * 중복 사용가능한 경우 갱신할때 왼쪽에서 부터 갱신해준다.
 * scanf 를 이용하여 특정 포맷의 문자열로 부터 '손쉽게' 정수 추출할 수 있다.
 * 실수등 복잡한 조건을 정수로 나타내는 것이 주요 풀이 포인트 였다.
 */
#include <bits/stdc++.h>
using namespace std;

int cost, n, m1, m2, c;
int dp[100001];

int main() {
    while (1) {
        scanf("%d %d.%d", &n, &m1, &m2); // scanf 이용하여 포맷된 문자열로 부터 정수 추출
        if (n == 0) break;
        cost = m1 * 100 + m2; // 실수로 주어지는 비용을 정수로 변환하여 계산의 편의성을 높인다.
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            scanf("%d %d.%d", &c, &m1, &m2);
            int p = m1 * 100 + m2;
            for (int j = p; j <= cost; j++) {
                // 중복하여 사용할 수 있는 냅색의 경우 왼쪽에서 부터 갱신한다.
                dp[j] = max(dp[j], dp[j - p] + c);
            }
        }
        printf("%d\n", dp[cost]);
    }
    return 0;
}
