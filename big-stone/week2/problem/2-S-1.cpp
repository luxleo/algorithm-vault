//
// Created by 5600G on 2026-11-09.
//
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 10001;
int n,m,a,b, memo[MAX_N], vst[MAX_N],ret;
vector<int> tree[MAX_N];

int dfs(int here)
{
    vst[here] = 1;
    int ret = 1; // 자기 자신을 미리 포함시킴

    for (int node : tree[here])
    {
        if (vst[node] != 0) continue; // 방문한 컴퓨터인 경우 거른다
        ret += dfs(node);
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i=0; i<m; i++)
    {
        cin >> a >> b;
        tree[b].emplace_back(a);
    }

    for (int i=1; i<=n; i++)
    {
        memset(vst, -1, sizeof(vst));
        memo[i] = dfs(i);
        ret = max(ret, memo[i]);
    }

    for (int i=1; i<=n; i++)
        if (ret == memo[i])
            cout << i << ' ';
    cout << '\n';
    return 0;
}
