//
// Created by 5600G on 2026-02-12.
//

/** @see https://www.acmicpc.net/problem/9370
 * 모든 간선을 짝수 특정 간선을 홀수로 표시하여 특정간선 지났는지 표기하기
 */
#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2001;
const int INF = 1e9;
int dist[MAX_N], n, m, t, s, g, h, a, b, d,T;

void dijkstra(int start, vector<pair<int,int>> *adj)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[start] = 0;
    pq.emplace(0, start);

    while (!pq.empty())
    {
        int here = pq.top().second;
        int here_cost = pq.top().first;
        pq.pop();

        if (dist[here] < here_cost) continue;
        for (auto &[ next_cost, next] : adj[here])
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--)
    {
        vector<pair<int, int>> adj[2004];
        cin >> n >> m >> t >> s >> g >> h;
        for(int i = 0; i < m; i++){
            cin >> a >> b >> d;
            d *= 2;
            if(a == g && b == h){
                d--;
            }else if(a == h && b == g)d--;
            adj[a].emplace_back(d, b);
            adj[b].emplace_back(d, a);
        }
        vector<int> candi(t); // vector를 쓰면 정렬하기 편합니다
        for (int i = 0; i < t; i++) {
            cin >> candi[i];
        }

        // --- 수정 포인트 1: 오름차순 정렬 ---
        sort(candi.begin(), candi.end());
        fill(dist, dist + 2004, INF);
        dijkstra(s, adj);
        for(int i = 0; i < t; i++){
            if(dist[candi[i]] % 2 == 1) cout << candi[i] << "\n";
        }
    }
}
