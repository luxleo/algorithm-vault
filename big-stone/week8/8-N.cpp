//
// Created by 5600G on 2026-02-10.
//

/** @see https://www.acmicpc.net/problem/5719
 * 다익스트라를 이용한 역추적이 가능하다.
 * 다익스트라 갱신 조건이 추가되는 경우가 있다.
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

const int MAX_N = 501;
const int INF = 1e9;
using namespace std;

int n,m,x,y,z,s,e;
int adj[MAX_N][MAX_N], dist[MAX_N];

void dijkstra(int start)
{
    // 거리 배열 초기화
    fill(dist, dist + MAX_N, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.emplace(0, start);
    dist[start] = 0;

    while (!pq.empty())
    {
        int here = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (dist[here] < cost) continue;
        for (int to=0; to<n; to++)
        {
            if (adj[here][to] == -1) continue; // (갱신 조건 추가) 삭제된 경로라면 넘어간다.
            if (dist[to] > cost + adj[here][to])
            {
                dist[to] = cost + adj[here][to];
                pq.emplace(dist[to], to);
            }
        }
    }
}

void eraseEdge(int end)
{
    queue<int> q;
    q.emplace(end); // 끝 노드에서 부터 최단 경로를 탐색한다.

    while (!q.empty())
    {
        int to = q.front(); q.pop();
        for (int prev =0; prev<n; prev++)
        {
            // 핵심 로직: (i에서 cx로 오는 거리) + (i와 cx 사이 도로 길이) == (cx까지의 최단 거리)
            // 이 조건이 맞다면 해당 도로는 최단 경로에 포함된 도로입니다.
            if (dist[to] == adj[prev][to] + dist[prev] && adj[prev][to] != -1)
            {
                // 도로 삭제
                adj[prev][to] = -1;
                q.emplace(prev);
            }
        }

    }
}

int main()
{
    while (true)
    {
        scanf("%d%d", &n, &m);
        if (n == 0 && m == 0) break;

        scanf("%d%d", &s, &e);
        memset(adj, -1, sizeof(adj)); // 초기에 모든 간선이 없음 처리
        for (int i=0; i<m; i++)
        {
            scanf("%d%d%d", &x,&y,&z); // x에서 y로 가는 도로길이가 z
            adj[x][y] = z;
        }

        // 최단 경로 찾기
        dijkstra(s);
        eraseEdge(e);
        // 최단 경로 삭제후 다시 근사치 거리 구하기
        dijkstra(s);
        printf("%d\n", dist[e] == INF ? -1 : dist[e]);
    }
    return 0;
}
