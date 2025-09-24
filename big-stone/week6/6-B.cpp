//
// Created by 이동한 on 2025. 9. 24..
//
/** S1 이분탐색 + 결정문제 @see https://www.acmicpc.net/problem/2343
 * 이분탐색은 선형 탐색을 o(logn)의 결정 문제로 바꾼다.
 * 이떼 관건은 lo, hi의 갱신 조건함수인 check를 유의미 하게 작성하는 것이다.
 *
 * 해당 문제는 다음의 조건을 만족하는 check 함수를 작성하는 것이다.
 * 1. 블루레이의 길이는 가장 긴 강의의 시간 보다 길어야한다.
 * 2. 최소시간으로 결정된 mid의 크기에 의해 만들어지는 블루레이의 수가 m 이하이다.
 */
#include <bits/stdc++.h>
using namespace std;

const int MAX_LEN = 987654321;
int n, m, a[100001], ret = MAX_LEN, mx;

bool check(int mid) {
    if (mx > mid) return false;
    int temp = mid;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        // if 절과 빼는 조건을 바꾸면 오류가 발생한다.
        if (mid - a[i] < 0) {
            cnt++;
            mid = temp;
        }
        mid -= a[i];
    }
    if (mid != temp) cnt++;
    return cnt <= m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int sum = 0; // 이분탐색 상한(sum), 하한(mx)을 구하기 위함
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
    }
    int lo = 0, hi = sum; // lo = mx로 하면 더 나음.
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (check(mid)) {
            hi = mid - 1;
            ret = mid;
        } else lo = mid + 1;
    }
    cout << ret << endl;
    return 0;
}
