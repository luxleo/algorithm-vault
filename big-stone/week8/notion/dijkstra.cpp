//
// Created by 5600G on 2026-02-09.
//

/** 다익스트라 알고리즘
 * 양의 가중치를 가지는 그래프에서
 * 한 정점에서 다른 모든 정점까지의 최단 거리를 구하는 문제이다
 * 우선순위 큐와 함께 사용된다.
 */
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1001

const int INF = 987654321;
vector<pair<int, int> > adj[MAX_N];
vector<int> dist(MAX_N, INF); // 거리 배열은 최소로 갱신하므로 최대값으로 초기화 DIST의 의미는 특정 지점으로 부터 dist[node_idx] 의 node_idx 까지의 최단 거리이다.

void dijkstra(int start) {
    // 우선순위 큐에는 {비용 , 노드} 가 담겨서 비용으로 오름차순 정리한다.
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    dist[start] = 0;
    pq.emplace(0, start);
    while (!pq.empty()) {
        int here_cost = pq.top().first;
        int here_node = pq.top().second;
        // 만일 다른 노드를 경우한 경로가 현재의 경로보다 짧다면 그냥 넘어간다.
        if (dist[here_node] < here_cost) continue;
        for (auto &[next_node, cost]: adj[here_node]) {
            int next_cost = here_cost + cost;
            if (dist[next_node] > next_cost) {
                dist[next_node] = next_cost;
                pq.emplace(next_cost, next_node);
            }
        }
    }
}

int main() {
    return 0;
}
