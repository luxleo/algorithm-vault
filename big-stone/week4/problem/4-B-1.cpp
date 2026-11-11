//
// Created by 이동한 on 2026. 11. 11..
//
#include <bits/stdc++.h>
#define maxn 200005
typedef long long ll;
using namespace std;

const int INF = 987654321;
int n, a[44], ret = INF;
string s;

// go(here): 'here' 번째 행을 뒤집을지 말지 결정하는 재귀 함수
void go(int here) {
    // [종료 조건] 모든 행(1 ~ n행)의 뒤집기 여부를 모두 결정했을 때
    if (here == n + 1) {
        int sum = 0; // 현재 상태에서 만들 수 있는 최소 뒷면(T)의 총 개수

        // i는 비트마스크 위치를 의미함 (1, 2, 4, 8, ... 2^(n-1)) -> 각 '열'을 탐색
        for (int i = 1; i <= (1 << (n - 1)); i *= 2) {
            int cnt = 0; // 현재 열(i번째 비트)에서 뒷면(T)의 개수

            // 모든 행을 순회하며 해당 열에 T(1)가 몇 개 있는지 셈
            for (int j = 1; j <= n; j++) {
                if (a[j] & i) cnt++;
            }

            // 열을 안 뒤집으면 뒷면 개수는 cnt
            // 열을 뒤집으면 뒷면 개수는 (n - cnt)
            // 따라서 둘 중 더 작은 값을 최종 뒷면 개수에 더함
            sum += min(cnt, n - cnt);
        }

        // 여태까지 구한 최댓값/최솟값 중 최솟값을 갱신
        ret = min(ret, sum);
        return;
    }

    // 1. 현재 행(here)을 뒤집지 않고 다음 행으로 진행
    go(here + 1);

    // 2. 현재 행(here)의 모든 동전을 뒤집고(비트 반전 ~) 다음 행으로 진행
    a[here] = ~a[here];
    go(here + 1);
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    // 입력받은 H/T 문자를 2진수 비트 정보로 변환하여 a[i]에 저장
    // T = 1 (뒷면), H = 0 (앞면)
    for (int i = 1; i <= n; i++) {
        cin >> s;
        int value = 1;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == 'T') a[i] |= value; // T인 위치의 비트를 1로 켬
            value *= 2; // 다음 열 비트 자리수로 이동 (1, 2, 4, 8...)
        }
    }

    // 1번째 행부터 재귀 탐색 시작
    go(1);

    // 최소 뒷면 개수 출력
    cout << ret << "\n";
    return 0;
}
