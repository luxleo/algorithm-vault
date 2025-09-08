//
// Created by 이동한 on 2025. 9. 8..
//
/** S2 다이내믹 프로그래밍
 * 연속하는 최대의 구간합 구하기.
 * 특수하기 배열을 구하지 않아도 되었다.
 *
 * 만일 누적합의 값이 음수가 된다면 처음부터 시작하는 것이
 * 이득이기에 0으로 겂울 할당하여 처음부터 시작하도록한다.
 */
#include <bits/stdc++.h>
using namespace std;
int N, ret = -1001, a, sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        sum += a;
        ret = max(ret, sum);
        if (sum < 0) sum = 0;
    }
    cout << ret << endl;
    return 0;
}
