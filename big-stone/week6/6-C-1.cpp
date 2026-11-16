//
// Created by 이동한 on 2026. 11. 14..
//
#include <bits/stdc++.h>
using namespace std;

int n, m; // n: 용돈을 사용할 총 일수(N), m: 목표 인출 횟수(M)
int a[100005]; // i번째 날에 사용할 금액을 저장하는 배열
int mx; // N일 중 하루 최대 지출 금액 (인출 금액 K의 하한선)
int ret; // 답: 최소 인출 금액 K
int lo, hi; // 이분 탐색의 시작점(lo)과 끝점(hi)

void fastIO() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

/**
 * @brief 한 번에 mid원씩 인출할 때, N일 동안의 지출을 M번 이하의 인출로 감당할 수 있는지 판별
 * @param mid 가정한 1회 인출 금액 (K원)
 * @return 필요한 최소 인출 횟수가 M번 이하이면 true, M번을 초과하면 false
 */
bool check(int mid) {
    // cnt: 총 인출 횟수 (첫째 날 시작할 때 무조건 1번 인출하고 시작하므로 1로 초기화)
    // temp: 돈을 다시 인출할 때 수중에 mid원을 채워 넣기 위해 원래 인출 금액을 백업해 둔 변수
    int cnt = 1, temp = mid;

    // 0일차부터 n-1일차까지 순서대로 지출 시뮬레이션
    for (int i = 0; i < n; i++) {
        // 현재 수중에 남은 돈(mid)으로 오늘 쓸 돈(a[i])을 낼 수 없다면?
        if (mid - a[i] < 0) {
            mid = temp; // 남은 돈을 통장에 넣고, 다시 temp(K원)를 새로 인출
            cnt++; // 인출 횟수 1 증가
        }
        // 오늘 사용할 금액만큼 수중의 돈에서 차감
        mid -= a[i];
    }

    // 최소 인출 횟수(cnt)가 목표 횟수(m) 이하라면, 불필요한 재인출을 섞어 정확히 m번을 맞출 수 있음
    return cnt <= m;
}

int main() {
    fastIO();

    // 1. 일수(n)와 인출 횟수(m) 입력
    cin >> n >> m;

    // 2. 매일 사용할 금액을 입력받으면서 하루 최대 지출액(mx)을 찾음
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(a[i], mx);
    }

    // 3. 이분 탐색 범위 설정
    // lo: 하루 최대 지출액(mx)보다 작으면 그날 지출이 불가능하므로 mx부터 시작
    // hi: 최악의 경우(N=100,000, 매일 10,000원, M=1) 필요한 최대 금액 10억(10^9) 이상으로 설정
    lo = mx, hi = 1000000004;

    // 4. 이분 탐색 수행
    while (lo <= hi) {
        int mid = (lo + hi) / 2; // 중간값(1회 인출 금액 후보)

        // mid원씩 인출해서 M번 이하로 생활이 가능하다면?
        if (check(mid)) {
            hi = mid - 1; // 더 적은 금액으로도 가능한지 왼쪽(작은 값) 범위 탐색
            ret = mid; // 현재 가능한 금액을 정답으로 기록
        }
        // M번을 초과해서 인출해야 한다면 금액이 부족한 것이므로 오른쪽(큰 값) 범위 탐색
        else {
            lo = mid + 1;
        }
    }

    // 5. 최소 인출 금액 출력
    cout << ret << "\n";
    return 0;
}
