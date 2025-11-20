//
// Created by 이동한 on 2025. 11. 21..
//

/** @see https://www.acmicpc.net/problem/2293
 * DP로 경우의 수 카운트하는 문제.
 * 문제에서 동전의 조합을 순서와 무관하게 사용한다는 조건으로 인해 dp를 이용할 수 있게됨.
 */
#include <cstdio>
#include <iostream>
using namespace std;

int dp[10001], n, k, temp;

int main() {
    scanf("%d %d", &n, &k);
    dp[0] = 1; // 아무것도 선택하지 않는 경우를 하나로 초기설정한다. ( 경로 찾는 문제로 바꾸어 생각해보기)
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        for (int j = temp; j <= k; j++) {
            dp[j] += dp[j - temp]; // 경우의 수를 카운트할 때는 누적하여 더함
        }
    }
    printf("%d", dp[k]);
    return 0;
}
