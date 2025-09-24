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
        // if 절과 빼는 조건을 바꾸면 오류가 발생한다.(누락의 위험이 있기 떄문이다.)
        /**
        * 실제 입력으로 한 눈에 보기 (n=9, m=3, a=1…9, 정답 용량=17)

예를 들어 **mid=16**일 때:

첫 코드(잘못)
진행 중 6에서 초과 → 블루레이 추가 후 6을 새 블루레이에 다시 넣지 않음 →
실제로는 [1..5], [6..7], [8], [9]로 4장 필요인데,
6이 빠져서 [1..5], [7..8], [9]처럼 계산되어 3장으로 잘못 판단(가능하다고 true)합니다.

두 번째 코드(정상)
6에서 초과 직전 감지 → 블루레이 추가 → 6을 즉시 적재 →
최종 [1..5], [6..7], [8], [9]로 4장 → false(불가능) 판정.

이 차이 때문에 첫 코드는 mid=10~16 구간을 가능하다고 착각하고, 이분 탐색이 잘못된 더 작은 답으로 수렴합니다.
         */
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
