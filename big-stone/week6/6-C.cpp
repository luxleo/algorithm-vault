//
// Created by 이동한 on 2025. 9. 25..
//
/** S1 @see https://www.acmicpc.net/problem/6236
 * 다음과 같이 주어진 문제의 조건을 유연하게 해석하는 안목이 필요했다.
 * M번만 통장에서 돈을 뺀다 -> M번 이하로 인출하는것으로 계산하고 만약 모자라면 마지막 단계에 남은 횟수만큼
 * 추가인출한다.
 *
 * 이분탐색 + 결정 문제(최적화) 에서 중요한 점은 갱신 조건 함수 (check)를 잘 작성하는 것이다.
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, ret, a[100001], mx, lo, hi;

bool check(ll mid) {
    int cnt = 1, temp = mid; // 처음 무조건 한번은 인출한채로 시작한다.
    for (int i = 0; i < n; i++) {
        if (mid - a[i] < 0) {
            cnt++;
            mid = temp;
        }
        mid -= a[i];
    }
    return cnt <= m; // 인출 횟수가 문제의 제약조건보다 적어야한다.
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    lo = mx;
    hi = 100000 * 10000; // hi는 문제 조건에 의해 구해진다.
    while (lo <= hi) {
        ll mid = (lo + hi) >> 1;
        if (check(mid)) {
            hi = mid - 1;
            ret = mid;
        } else lo = mid + 1;
    }
    cout << ret << endl;
    return 0;
}
