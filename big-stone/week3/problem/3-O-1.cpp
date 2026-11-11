//
// Created by 5600G on 2026-11-11.
//
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX_H = 31;
const int MAX_COL = 11;
int N,M,H,a,b,ret = INF, vst[MAX_H][MAX_COL];

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool check()
{
    for (int i=1; i<=N; i++)
    {
        int start = i;
        for (int j=1; j<=H; j++)
        {
            if (vst[j][start - 1]) start--;
            else if (vst[j][start]) start++;
        }
        if (start != i) return false;
    }
    return true;
}

void dfs(int here, int cnt)
{
    if (cnt > 3 || cnt >= ret ) return;
    if (check())
    {
        ret = min(ret, cnt);
        return;
    }

    for (int i = here; i<=H; i++)
    {
        for (int j=1; j<N; j++)
        {
            if (vst[i][j-1] || vst[i][j] || vst[i][j+1]) continue;
            vst[i][j] = 1;
            dfs(i, cnt+1);
            vst[i][j] = 0;
        }
    }
}

int main()
{
    fastIO();
    cin >> N >> M >> H;
    for (int i=0; i<M; i++)
    {
        // 이미 존재하는 사다리 설치
        cin >> a >> b;
        vst[a][b] = 1;
    }

    dfs(1, 0);

    if (ret == INF) cout << -1 << '\n';
    else cout << ret << '\n';

    return 0;
}
