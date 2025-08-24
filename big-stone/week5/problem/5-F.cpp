//
// Created by 이동한 on 2025. 8. 24..
//
/** G2
 * 전형적인 냅색 문제이다.
 * 아이디어:
 *  1. 가방을 무게가 낮은 순으로 정렬한다.
 *  2. 훔칠수 있는 보석도 무게가 낮은 순으로 정렬한다.
 *  3. 가방을 무게가 낮은 순으로 순회하며 그 가방의 한계까지 담을 수 있는 보석의 범위를 스캔하여 넣는다.
 *  4. 매 가방의 순회마다 우선순위 큐에서 가장 높은 가치를 가지는 보석을 담는다.
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; // static 레벨에서 선언해주어야 0으로 초기화 한다.

int N, K;
ll ret;

int main() {
    // ll ret; 이 처럼 함수내에서 선언하면 값이 초기화 되어있지 않아 쓰레기 값으로 부터 연산시작한다.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    vector<pair<int, int> > v(N);
    vector<int> vv(K);
    priority_queue<int> pq;

    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }
    for (int i = 0; i < K; i++) {
        cin >> vv[i];
    }

    sort(v.begin(), v.end());
    sort(vv.begin(), vv.end());
    int j = 0;
    for (int i = 0; i < K; i++) {
        while (j < N && vv[i] <= v[j].first) {
            // 현재 가방의 캐파(capacity) 보다 낮다면 후보에 넣어준다.
            pq.push(v[j++].second);
        }
        if (!pq.empty()) {
            // 매 가방마다 담을 수 있는 최고가치의 보석을 담아준다 (이후 다음 가방까지 계속 후보 누적)
            ret += pq.top();
            pq.pop();
        }
    }
    cout << ret << endl;
    return 0;
}
