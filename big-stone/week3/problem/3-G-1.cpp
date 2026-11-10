//
// Created by 5600G on 2026-11-10.
//
#include <bits/stdc++.h>
using namespace std;

const int MAX_POS = 100001;
const int MAX_SEC = 1e9;
int N,K, ret;

map<int,int> mp;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int move(int idx, int here)
{
    if (idx == 0) return here -1;
    else if (idx == 1) return here + 1;
    else if (idx == 2) return here * 2;
    return -1;
}

void dfs(int here, int cnt)
{
    if (here == K)
    {
        ret = min(ret, cnt);
        mp[cnt]++;
        return;
    }

    for (int i=0; i<3; i++)
    {
        int next = move(i,here);
        if (next >= 0 && next < MAX_POS)
            dfs(next, cnt++);
    }
}

int main()
{
    fastIO();
    cin >> N >> K;

    dfs(N,0);

    cout << ret << '\n';
}
