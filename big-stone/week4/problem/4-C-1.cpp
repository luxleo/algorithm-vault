//
// Created by 5600G on 2026-11-12.
//
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 11;
const int INF = 1e9;
int n,t1,t2,a[MAXN], comp[MAXN], vst[MAXN],ret=INF;
vector<int> adj[MAXN]; // 2차원 연결 배열 설정하기

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

pair<int,int> dfs(int here, int group)
{
    vst[here] = 1;
    pair<int,int> res = {1, a[here]};
    for (int next : adj[here])
    {
        if (vst[next]) continue;
        if (comp[next] != group) continue;
        pair<int,int> _next = dfs(next,group);
        res.first += _next.first;
        res.second += _next.second;
    }
    return res;
}

int main()
{
    fastIO();
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];

    for (int i=1; i<=n; i++)
    {
        cin >> t1;
        for (int j = 0; j < t1; j++)
        {
            cin >> t2;
            adj[i].emplace_back(t2);
            adj[t2].emplace_back(i);
        }
    }

    for (int i=1; i<(1<<n) - 1; i++)
    {
        memset(comp, 0, sizeof(comp));
        memset(vst, 0 ,sizeof(vst));

        int idx1 = -1;
        int idx0 = -1;

        for (int j=0; j<n; j++)
        {
            if (i & (1 << j))
            {
                comp[j+1] = 1;
                idx1 = j+1;
            } else
            {
                comp[j+1] = 0;
                idx0 = j+1;
            }
        }

        pair<int,int> comp1 = dfs(idx1, 1);
        pair<int,int> comp0 = dfs(idx0, 0);

        if (comp1.first + comp0.first == n)
        {
            ret = min(ret, abs(comp1.second - comp0.second));
        }
    }

    cout << (ret == INF ? -1 : ret) << '\n';

}
