/** G1 @see https://www.acmicpc.net/problem/1561
 * 상한값 max_n을 구하는 것
 * lower_bound를 찾고 -1 을 해주어 최소 시간 chunk 구하기
 * 다시 lower_bound 를 기준으로 모듈러 연산이 0인값 찾기 => lower_bound값에서 탑승을 정확히 완료함
 */
#include <bits/stdc++.h>
#define max_n 60000000004 // max_n 의 값은 가능한 N의 수와 M=1일때 가능한 최대 시간인 30분으로 계산하였다.
#define MAX_M 10001

using namespace std;
typedef long long ll;
ll n, m, a[MAX_M], lo, hi = max_n, ret;

bool check(ll mid) {
    ll temp = m; // 맨마지막에는 무조건 다 태울 수 있으므로.
    for (int i = 0; i < m; i++) temp += mid / a[i];
    return temp >= n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    if (n <= m) {
        cout << n << "\n";
        return 0;
    }
    for (int i = 0; i < m; i++) cin >> a[i];
    ll mid = 0;
    while (lo <= hi) {
        mid = (lo + hi) >> 1;
        if (check(mid)) {
            hi = mid - 1;
            ret = mid;
        } else {
            lo = mid + 1;
        }
    }
    ll temp = m;
    for (int i = 0; i < m; i++) temp += (ret - 1) / a[i]; // lower_bound - 1
    for (int i = 0; i < m; i++) {
        if (ret % a[i] == 0) temp++; // lower_bound에서 탑승 완료
        if (temp == n) {
            cout << i + 1 << "\n";
            return 0;
        }
    }
    return 0;
}
