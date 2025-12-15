//
// Created by 이동한 on 2025. 12. 15..
//

#include <cstdio>
#include <algorithm>
using namespace std;

int n, k, w, v, dp[100001];
/** 냅색 알고리즘 @see https://www.acmicpc.net/problem/12865
 * 냅색은 크게 두 가지 경우로 나눌 수 있다.
 * 1. 아이템을 한번만 사용 가능한 경우
 * 2. 아이템을 무한히 사용 가능한 경우
 *
 * 1. 의 경우 오른쪽에서 왼쪽으로 갱신하고
 * 2. 의 경우 왼쪽에서 오른쪽으로 갱신한다.
 *
 * 지금의 문제는 1번의 경우이다.
 *
 * @return
 */


int main() {
    scanf("%d %d", &n, &k);
    while (n--) {
        scanf("%d %d", &w, &v);
        for (int j = k; j >= w; j--)
            dp[j] = max(dp[j], dp[j - w] + v);
    }
    printf("%d\n", dp[k]);
    return 0;
}
