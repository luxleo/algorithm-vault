//
// Created by 이동한 on 2025. 10. 16..
//
/** G5
 * ㅇㅏ이디어를 내는게 가장 중요했던 문제이다.
 * 전기선이 꼬이지 않게 배치하는 수는 '전체수 - LIS 수' 라는 것을 간파하는 것이 핵심이었다.
 *
 * LIS 탐색 방법중 O(logn)으로 조회 하는 방법을 숙달해야한다.
 */
#include <bits/stdc++.h>
using namespace std;

int lis[501], len, n;
vector<pair<int, int> > v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.emplace_back(a, b);
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        auto it = lower_bound(lis, lis + len, v[i].second);
        if (*it == 0) len++;
        *it = v[i].second;
    }
    cout << n - len << "\n";
    return 0;
}
