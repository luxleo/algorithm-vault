//
// Created by 이동한 on 2026. 2. 7..
//
/** @see https://www.acmicpc.net/problem/2302
 * dp로 경우의 수 구하는 문제이다.
 * 경우의 수를 구할 때는 경우의 수가 0일수 있으므로 -1 로 초기화 해준다.
 * 항상 그래프로 식이 어떻게 전개 되는지 구성해본다.
 */
#include <bits/stdc++.h>
using namespace std;
int N, M, cnt[41], dp[41];

int go(int here) {
    if (here >= N - 1) return 1; // 탐색 끝난 노드경우의 수 1 더해주기
    if (cnt[here]) return go(here + 1); // VIP 자리 이므로 바꿀수 없는 경우 넘어간다.
    if (dp[here] != -1) return dp[here];
    int &ret = dp[here];
    ret = 0;
    if (!cnt[here + 1]) ret += (go(here + 1) + go(here + 2));
        // 바꿀 수 있는 경우 ( 현재 노드의 다음 노드가 VIP가 아닌 경우) 바꾸지 않는 경우 + 바꾸는 경우로 넘겨준다.
    else ret += go(here + 1); // 바꿀 수 없으면 넘겨준다.
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M; // 줄 바꿈으로 입력 되어도 이렇게 받을 수 있다.
    int temp;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        cnt[temp - 1] = 1;
    }
    memset(dp, -1, sizeof(dp));
    cout << go(0) << "\n";
    return 0;
}
