//
// Created by 이동한 on 2025. 8. 20..
//
/**
 * G2 [1781](https://www.acmicpc.net/problem/1781)
 *
 * 5-A와 거의 같은 문제이다.
 * 합의 최대를 구하라는 말은 다음과 같다.
 * - 최소인 요소를 작게하라
 * - 최대인 요소를 많게하라
 *
 * 위 문제는 데드라인을 구간으로 보았을때 구간에 해당하는 요소를 '배치'하여 최대의 합을 가지게 하는 것이다.
 *
 * 분석:
 * - 구간 이기 때문에 '라인 스위핑'을 생각할 수 있다.
 * - 구간내에 배치를 효율화 하기 위하여 '정렬'을 생각할 수 있다.
 * - 최대 또는 최소에 해당하는 요소를 연속으로 뽑아 내야하므로 'priority_queue'를 생각할 수 있다.
 */
#include <bits/stdc++.h>
using namespace std;

int N, a, b, ret;
vector<pair<int, int> > v;
priority_queue<int, vector<int>, greater<> > pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a >> b; // a: dead line, b: 컵라면 개수
        v.emplace_back(a, b);
    }
    sort(v.begin(), v.end()); // sort하면 pair의 첫번째 요소를 기준으로 정렬한다. (데드라인이 적은 녀석을 기준으로)
    for (pair<int, int> p: v) {
        pq.push(p.second);
        if (pq.size() > p.first) {
            // 데드라인(구간) 보다 담긴 요소가 많다면 가장 보상이 작은 요소를 pop
            pq.pop();
        }
    }
    while (!pq.empty()) {
        ret += pq.top();
        pq.pop();
    }

    cout << ret << endl;

    return 0;
}
