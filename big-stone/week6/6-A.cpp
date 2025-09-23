//
// Created by 이동한 on 2025. 9. 23..
//
/** S1 @see https://www.acmicpc.net/problem/2792
 * 선형적 탐색 -> 결정 문제로 바꾸기
 * 브루트 포스로 풀었다면 선형적으로 탐색하며 가능한 색의 조합수를 구해야한다.
 * 하지만 이분탐색을 통하여 결정문제(최소 질투수가 전체 학생수보다 작음을 만족하는가)로 바꾸어
 * 갱신해가며 O(logn)으로 풀이를 완료하였다.
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, ret = 987654321, a[300004];

/**
 * 색에 해당하는 최소 질투수로 그룹을 나눈다.
 * 그룹수가 전체 학생수보다 작은지 판별한다.
 * 그룹수가 작다면 최소 질투수를 줄여 그룹수를 늘릴것이다.
 * 그룹수가 크다면 최소 질투수를 늘려 학생수보다 작도록 갱신한다.
 *
 * @param mid 검증할 최소 질투수
 * @return 최소 질투수로 그룹을 나누었을때 전체 학생수 보다 작은지 판단
 */
bool check(ll mid) {
    ll num = 0;
    for (int i = 0; i < m; i++) {
        num += a[i] / mid;
        if (a[i] % mid) num++;
    }
    return n >= num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    ll lo = 1, hi = 0, mid;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        hi = max(hi, a[i]);
    }
    while (lo <= hi) {
        mid = (lo + hi) >> 1;
        if (check(mid)) {
            ret = min(ret, mid);
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ret << endl;
    return 0;
}
