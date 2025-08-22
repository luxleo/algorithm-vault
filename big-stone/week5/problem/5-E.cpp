//
// Created by 이동한 on 2025. 8. 22..
//
/** G5 [1931](https://www.acmicpc.net/problem/1931)
 * 전형적인 라인스위핑 알고리즘.
 * 라인스위핑의 기본 골자는 from, to를 재정의 해가면서 구간을 겹치지 않게 배치하는 것.
 *
 * 재배치의 파라미터는 from,to,size크게 세가지가 있으나 보통은 from, to젇도이다.
 * 또한 빠질수 없는 것이 '정렬'이다.
 *
 * 이 문제의 경우 to를 기준으로 정렬하여 재배치하면 풀 수 있다.
 */
#include <bits/stdc++.h>
using namespace std;

int N, a, b, from, to;
vector<pair<int, int> > v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ret = 1;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v.emplace_back(b, a); // 회의 끝나는 시간, 회의 시작시간 => 풀이에 필요한 정렬의 편의를 위해
    }
    sort(v.begin(), v.end());
    from = v[0].second;
    to = v[0].first;
    for (int i = 1; i < N; i++) {
        if (v[i].second >= to) {
            from = v[i].second;
            to = v[i].first;
            ret++;
        }
    }
    cout << ret << endl;
    return 0;
}
