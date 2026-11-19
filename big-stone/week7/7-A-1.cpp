//
// Created by 5600G on 2026-11-19.
//
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 17;
const int INF = 1e9;

int n,dp[MAXN][1<<MAXN], dist[MAXN][MAXN];

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int dfs(int here, int vst)
{
    if (vst == (1 << n) - 1)
    {
        // 출발 노드 '0' 으로 가는길이 갱신 되었으면 값 반환하고 아니면 갈 수 없음을 반환
        return dist[here][0] ? dist[here][0] : INF;
    }
    int &ret = dp[here][vst];
    if (ret != -1) return ret;
    ret = INF;

    for (int i=0; i<n; i++)
    {
        if (vst & (1 << i)) continue;
        if (dist[here][i] == 0) continue;
        ret = min(ret, dfs(i, vst | (1 << i)) + dist[here][i]);
    }
    return ret;
}

int main()
{
    fastIO();
    cin >> n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> dist[i][j];
    memset(dp, -1, sizeof(dp));
    cout << dfs(0,1) << '\n';
    return 0;
}
