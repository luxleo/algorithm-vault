#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200001;

int a, b, A[MAXN], B[MAXN];

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    fastIO();
    cin >> a >> b;
    for (int i = 0; i < a; i++) cin >> A[i];
    for (int i = 0; i < b; i++) cin >> B[i];

    // B 배열에서 이분 탐색을 수행하기 위해 오름차순 정렬 (A는 정렬하지 않아도 무방함)
    sort(B, B + b);

    int cnt = 0; // 두 집합 A와 B에 공통으로 들어있는 원소(교집합)의 개수

    for (int i = 0; i < a; i++) {
        // B에서 A[i] 이상인 값이 처음 나오는 위치를 찾음
        auto pos = lower_bound(B, B + b, A[i]);

        // 1. pos != B + b : 배열 범위 끝까지 못 찾고 넘어간 경우가 아니어야 함 (역참조 오류 방지)
        // 2. *pos == A[i] : 찾은 위치의 실제 값이 A[i]와 정확히 일치해야 교집합 원소임
        if (pos != B + b && *pos == A[i]) {
            cnt++;
        }
    }

    // 대칭 차집합 원소 개수 = |A| + |B| - 2 * |A ∩ B|
    cout << a + b - 2 * cnt << '\n';

    return 0;
}
