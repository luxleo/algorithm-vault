//
// Created by 이동한 on 2026. 2. 11..
//
/** @see https://www.acmicpc.net/problem/1219
 * 벨만 포드 갱신 조건 커스텀화 (이 문제에서는 비용이 클 수록임)
 * 루프가 존재하는 경우 특정 지점, 끝 점 에 도달할 수 있는지는 bfs로 탐색한다.
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 104;

int n, m, s, e, from, to, c;
int visited[MAX_N];
vector<pair<int, int> > adj[MAX_N];
ll dist[MAX_N], cost[MAX_N];
ll INF = 1e18;

int main() {
    scanf("%d %d %d %d", &n, &s, &e, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &from, &to, &c);
        adj[from].emplace_back(to, c);
    }
    // 도시에서 벌 수 있는 비용 입력받음
    for (int i = 0; i < n; i++) scanf("%lld", &cost[i]);

    //초기화
    fill(dist, dist + n, -INF);
    dist[s] = cost[s];

    queue<int> q;
    //벨만포드 수행
    for (int i = 0; i < n; i++) {
        for (int here = 0; here < n; here++) {
            for (auto &edge: adj[here]) {
                int next = edge.first;
                int next_cost = edge.second;
                if (dist[here] == -INF) continue; // here 가 초기화 안되어있으면 패스
                // 다음 노드로 가는 벌이가 더 크면 이동
                if (dist[here] + cost[next] - next_cost > dist[next]) {
                    if (i == n - 1) q.push(here); // n번째 (최대 간선수 n-1을 넘어서) 에도 갱신되면 사이클 존재.
                    dist[next] = dist[here] + cost[next] - next_cost;
                }
            }
        }
    }

    int ok = 0;
    // BFS를 통해 목적지 e 까지 도달가능한지 확인
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v == e) {
            ok = 1;
            break;
        }
        for (auto &edge: adj[v]) {
            int next = edge.first;
            if (!visited[next]) {
                visited[next] = 1;
                q.push(next);
            }
        }
        if (ok) break;
    }

    if (dist[e] == -INF) puts("gg");
    else if (ok) puts("Gee");
    else printf("%lld\n", dist[e]);
    return 0;
}
