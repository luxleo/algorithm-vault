//
// Created by 이동한 on 2025. 11. 2..
//

/** @see https://www.acmicpc.net/problem/12852
 * dp + if - else if 로 연산 순위를 정해줌으로써 일종의 tracking 을 구현함.
 */
#include <bits/stdc++.h>
#define MAX_N 1000001
using namespace std;

const int INF = 987654321;
int N, dp[MAX_N];

void go(int here) {
    if (here == 0) return;
    cout << here << " ";
    // if else if 의 특성을 이용하여 연산의 우선순위를 정해준다. /3 -> /2 -> -1 순으로 연산 초기화
    if (here % 3 == 0 && dp[here] == dp[here / 3] + 1) go(here / 3);
    else if (here % 2 == 0 && dp[here] == dp[here / 2] + 1) go(here / 2);
    else if (here - 1 >= 0 && dp[here] == dp[here - 1] + 1) go(here - 1);
}

int main() {
    cin >> N;
    // memset은 1,0으로 초기화 할거 아니면 쓰면 안된다, fill 로 쓰자
    fill(dp, dp + N + 1, INF);
    // dp 값 갱신 - 연산횟수를 나타낸다.
    dp[1] = 0; // 1은 연산이 필요 없음
    for (int i = 1; i < N + 1; i++) {
        if (i % 3 == 0) dp[i] = min(dp[i / 3] + 1, dp[i]);
        if (i % 2 == 0) dp[i] = min(dp[i / 2] + 1, dp[i]);
        dp[i] = min(dp[i], dp[i - 1] + 1);
    }
    cout << dp[N] << "\n";
    go(N);
    return 0;
}
