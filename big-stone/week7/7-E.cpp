//
// Created by 이동한 on 2025. 11. 2..
//

/** @see https://www.acmicpc.net/problem/4811 - 알약 문제
 * dp로 경우의 수를 카운트하는 경우 모든 케이스를 더해준다.
 */
#include <bits/stdc++.h>
#define MAX_DAY 31
typedef long long ll;
using namespace std;

ll n, dp[MAX_DAY][MAX_DAY];

// 탑다운 방식으로 알약 먹는 방법을 갱신
ll go(int whole, int not_whole) {
    if (whole == 0 && not_whole == 0) return 1;
    ll &ret = dp[whole][not_whole];
    // 캐싱 되어 있으면 캐싱된값 반환
    if (ret) return ret;

    // 온전한 알약을 쪼개서 반쪽 먹는 경우 더해주기
    if (whole > 0) ret += go(whole - 1, not_whole + 1);
    // 반쪽 알약을 먹는 경우
    if (not_whole > 0) ret += go(whole, not_whole - 1);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n = -1;
    while (true) {
        cin >> n;
        if (n == 0) break;
        // 아래 처럼 갱신해주어야한다고 생각할 수 있으나 갱신하면 기존에 계산된 값을 이용할 수 없음.
        // 즉 입력으로 똑같은 수가 들어오면 오히려 이득이다.
        // memset(dp, -1, sizeof(dp));
        cout << go(n, 0) << "\n";
    }
    return 0;
}
