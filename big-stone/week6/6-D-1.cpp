//
// Created by 이동한 on 2026. 11. 14..
//
#include <bits/stdc++.h>
using namespace std;

int t, n, m; // t: 테스트 케이스 개수, n: A의 수, m: B의 수

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. 전체 테스트 케이스 개수 입력
    cin >> t;

    // 2. 각 테스트 케이스마다 독립적으로 실행
    while (t--) {
        int ret = 0; // 이번 테스트 케이스에서 A가 B를 먹을 수 있는 총 쌍의 개수

        // 3. A의 크기(n)와 B의 크기(m) 입력
        cin >> n >> m;
        vector<int> a(n), b(m);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

        // 4. 이분 탐색을 수행하기 위해 배열 b를 오름차순으로 정렬 (필수!)
        sort(b.begin(), b.end());

        // 배열 a도 오름차순 정렬 (이분 탐색 동작 자체에는 필수가 아니지만, 메모리 캐시 효율을 높여 실행 속도를 개선함)
        sort(a.begin(), a.end());

        // 5. 생명체 A를 한 마리씩 꺼내면서 먹을 수 있는 B의 개수 계산
        for (int i = 0; i < n; i++) {
            // 정렬된 b에서 'a[i] 이상'인 값이 처음으로 나타나는 위치(반복자)를 이분 탐색으로 찾음
            auto pos = lower_bound(b.begin(), b.end(), a[i]);

            // (찾은 위치 - 배열 시작 위치) = a[i]보다 작은 원소들의 개수
            ret += (int) (pos - b.begin());
        }

        // 6. 결과 출력
        cout << ret << "\n";
    }
    return 0;
}
