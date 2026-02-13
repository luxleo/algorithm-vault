//
// Created by 5600G on 2026-02-13.
//

/** @see https://www.acmicpc.net/problem/4485
 * 0. 2차원 그래프 다익스트라 적용
 * 1. 차원 압축 (2차원 -> 1차원)
 * 2. 이동으로 2차원 dist 배열 갱신
 */
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 126;
const int INF = 1e9;
const int dy[] = {1,-1,0,0}, dx[] = {0,0,1,-1};
int N, dist[MAX_N][MAX_N], mp[MAX_N][MAX_N]; // dist는 2차원이 되어도 특정 좌표에서 나머지 좌표까지의 최단거리를 갱신하는데는 변함이 없다.

// 2차원 배열 1차원으로 압축해서 넣는다. 1000 * y + x; ( x좌표 자릿수와 겹치지 않게한다.)
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
void dijkstra(int y1,int x1)
{
    dist[y1][x1] = mp[y1][x1];
    pq.emplace(mp[y1][x1], 1000*y1 + x1);

    while (!pq.empty())
    {
        int y = pq.top().second / 1000;
        int x = pq.top().second % 1000;
        int here_cost = pq.top().first;
        pq.pop();

        if (dist[y][x] < here_cost) continue;
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            int next_cost = mp[ny][nx];
            if (dist[ny][nx] > dist[y][x] + next_cost)
            {
                dist[ny][nx] = dist[y][x] + next_cost;
                pq.emplace(dist[ny][nx], 1000*ny + nx); // 2차원 좌표를 압축하여 넣는다. 새로운 좌표 안넣어서 틀렸다.
            }
        }
    }
}

int main()
{
    int idx = 0;
    while (++idx) // idx++ 하면 시작하자마자 종료된다.
    {
        scanf("%d", &N);
        if (N == 0) break;
        for (int i=0; i<N; i++)
        {
            for (int j=0; j<N; j++)
            {
                scanf("%d", &mp[i][j]);
            }
        }
        fill(&dist[0][0], &dist[0][0] + MAX_N * MAX_N, INF);
        dijkstra(0,0);
        printf("Problem %d: %d\n", idx, dist[N-1][N-1]);
    }
    return 0;
}
