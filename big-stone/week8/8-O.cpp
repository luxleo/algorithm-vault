//
// Created by 이동한 on 2026. 2. 10..
//
/** @see https://www.acmicpc.net/problem/16118
 * 번갈아 가면서 갱신하는 이차원 dist 배열
 * 양방향 연결 노드일떄 dijkstra 는 인접배열을 adj[from].push(to) , adj[to].push(from) 으로 해준다.
 */
#include <bits/stdc++.h>
using namespace std;
const int MAX_TREE = 4001;

typedef pair<int, int> PI;
typedef tuple<int, int, int> TI;
int dist[MAX_TREE], dist_wolf[MAX_TREE][2]; // 늑대의 최단 거리 저장 배열 [노드번호][0:다음 가속, 1:다음 감속]
int n, m, from, to, d, ret;
vector<PI> adj[MAX_TREE];
const int INF = 1e9;

void dijkstra(int s) {
    // 초기화 시작점 부터 다른 노드까지 거리 INF, dist[s] = 0;
    fill(dist, dist + MAX_TREE, INF);
    dist[s] = 0;
    priority_queue<PI, vector<PI>, greater<PI> > pq;
    pq.emplace(0, s);
    while (!pq.empty()) {
        int here = pq.top().second;
        int here_cost = pq.top().first;
        pq.pop();

        if (dist[here] < here_cost) continue;
        for (PI there: adj[here]) {
            int next = there.second;
            int next_cost = there.first;

            if (dist[next] > dist[here] + next_cost) {
                dist[next] = dist[here] + next_cost;
                pq.emplace(dist[next], next);
            }
        }
    }
}

void dijkstra_wolf(int s) {
    fill(&dist_wolf[0][0], &dist_wolf[0][0] + MAX_TREE * 2, INF);
    dist_wolf[s][0] = 0; // 시작 노드에 빠르게 달릴 상태로 시작
    priority_queue<TI, vector<TI>, greater<TI> > pq;
    pq.emplace(0, s, 0);
    while (!pq.empty()) {
        int here_cost, here, cnt;
        tie(here_cost, here, cnt) = pq.top();
        pq.pop();

        if (dist_wolf[here][cnt] < here_cost) continue;
        for (PI there: adj[here]) {
            int next = there.second;
            int next_cost = !cnt ? there.first / 2 : there.first * 2; // 천천히가면 거리두배 빨리가면 거리 /2
            if (dist_wolf[next][!cnt] > dist_wolf[here][cnt] + next_cost) {
                dist_wolf[next][!cnt] = dist_wolf[here][cnt] + next_cost;
                pq.emplace(dist_wolf[next][!cnt], next, !cnt); // 이번 차례에 뛰었으면 다음에는 뛰게하도록
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &from, &to, &d);
        // /2 연산시 소수가 나오지 않게 하기 위해 *2 를 해준다.
        adj[from].emplace_back(d * 2, to);
        adj[to].emplace_back(d * 2, from);
    }
    int start_node = 1;
    dijkstra(start_node);
    dijkstra_wolf(start_node);

    int ret = 0;
    for (int i = 2; i <= n; i++) {
        int wolf_min = min(dist_wolf[i][0], dist_wolf[i][1]);
        if (dist[i] < wolf_min) ret++;
    }
    printf("%d\n", ret);
    return 0;
}




