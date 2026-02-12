//
// Created by 5600G on 2026-02-12.
//
/** @see https://www.acmicpc.net/problem/1238
 * 주어진 경로 인접 배열을 뒤집으면 각 점에서 시작점의 최단거리 가 된다.
 */
#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1001;
const int INF = 1e9;
int N,M,X,s,e,t, dist_go[MAX_N], dist_back[MAX_N];
vector<pair<int,int>> adj_go[MAX_N], adj_back[MAX_N];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

void dijkstra(int *dist, int start, vector<pair<int,int>> *adj)
{
    dist[start] = 0;
    pq.emplace(0, start);
    while (!pq.empty())
    {
        int here = pq.top().second;
        int here_cost = pq.top().first;
        pq.pop();
        if (dist[here] < here_cost) continue;
        for (auto &[next_cost,next] : adj[here])
        {
            if (dist[next] > dist[here] + next_cost)
            {
                dist[next] = dist[here] + next_cost;
                pq.emplace(dist[next], next);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> X;
    fill(dist_go, dist_go + MAX_N, INF);
    fill(dist_back, dist_back + MAX_N, INF);
    for (int i=0; i<M; i++)
    {
        cin >> s >> e >> t;
        adj_go[s].emplace_back(t, e);
        adj_back[e].emplace_back(t, s);
    }
    dijkstra(dist_go, X, adj_go);
    dijkstra(dist_back, X, adj_back);
    int ret = 0;
    for (int i=1; i<=N; i++)
    {
        if (i == X) continue;
        ret = max(ret, dist_go[i] + dist_back[i]);
    }
    cout << ret << "\n";
    return 0;
}
