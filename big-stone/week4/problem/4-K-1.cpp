//
// Created by 5600G on 2026-11-13.
//
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1001;
int T, N,M,a,b,cnt, vst[MAX_N];
vector<int> adj[MAX_N];

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void dfs(int here)
{
    vst[here] = 1;
    for (int next : adj[here])
    {
        if (!vst[next]) dfs(next);
    }
}

int main()
{
    fastIO();
    cin >> T;

    while (T--)
    {
        for (int i=0; i<MAX_N; i++) adj[i].clear();
        memset(vst, 0 , sizeof(vst));
        cnt = 0;
        // 3. 정점의 개수(n)와 간선의 개수(m) 입력
        cin >> N >> M;

        // 4. m개의 간선 정보를 입력받아 양방향(무방향) 그래프 구성
        for (int i=0; i<M; i++)
        {
            cin >> a >> b;
            adj[a].emplace_back(b);
            adj[b].emplace_back(a);
        }

        // 5. 1번부터 n번 정점까지 순회하며 연결된 덩어리(연결 요소) 개수 세기
        for (int i=1; i<=N; i++)
            // 아직 방문하지 않은 정점을 만났다는 것은 새로운 독립된 덩어리를 발견했다는 뜻
            if (!vst[i])
            {
                dfs(i);
                cnt++;
            }

        // 6. 트리 판별 조건 확인 및 결과 출력
        // 조건 1 (m == n - 1): 간선 수가 (정점 수 - 1)개여야 함 (사이클/중복 간선 방지)
        // 조건 2 (cnt == 1): 모든 정점이 하나의 덩어리로 연결되어 있어야 함
        if (cnt == 1 && M == N-1) cout << "tree" << '\n';
        else cout << "graph" << '\n';
    }
    return 0;
}
