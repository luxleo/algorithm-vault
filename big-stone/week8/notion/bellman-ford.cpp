//
// Created by 이동한 on 2026. 2. 9..
//

/** 벨만 포드 알고리즘
 * 한 간선에서 다른 모든 간선까지의 최단거리를 구하는 알고리즘이다.
 * 가중치가 음수, 음수 사이클이 있는 경우에도 사용 가능하다.
 * 음수 사이클 판별을 위해 노드가 V 일때 다른 노드로의 최장 경유 간선은 V-1 임을 이용한다.
 * 만일 V-1 인데 최단거리가 갱신 된다면 음수 사이클이 있는 것으로 판별한다.
 * 초기화는 시작 간선 거리를 0 나머지를 INF 로 초기화 한다.
 *
 * 인접 배열 이용하여 간선 정보를 저장한다.
 */
#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 1004;
const int INF = 1e9;
int dist[MAX_N];

int main() {
    int num_node, num_edge;
    cin >> num_node >> num_edge;
    fill(dist, dist + MAX_N, INF); //memset(dist, INF, sizeof(dist)); memset은 0,1로 초기화 할때만 사용
    vector<pair<int, int> > adj[MAX_N]; // 노드, 가중치 저장

    // 가중치 초기화
    for (int i = 0; i < num_edge; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        adj[from].emplace_back(to, cost);
    }
    dist[1] = 0; // 시작점 1번 노드였으면 거리 0으로 초기화
    queue<int> q;

    // 최대 간선 수(노드 -1) 만큼 갱신한다.
    for (int i = 0; i < num_node; i++) {
        for (int here = 1; i <= num_node; here++) {
            for (auto &[to,cost]: adj[here]) {
                if (dist[here] != INF && dist[here] + cost < dist[to]) {
                    if (i == num_node - 1) q.push(to); // 만일 최대 갱신 횟수(노드 -1) 만큼 했는데 또 갱신이 되면 (노드 수와 같이) 음수 사이클이 있다.
                    dist[to] = dist[here] + cost;
                }
            }
        }
    }
    if (q.size()) cout << "음수 사이클 있어요" << "\n";
    return 0;
}
