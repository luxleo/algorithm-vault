//
// Created by 5600G on 2026-11-10.
//
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 61;
int n, a[3], vst[MAX_N][MAX_N][MAX_N];

int d[6][3] = {
    {9,3,1},
    {9,1,3},
    {3,9,1},
    {3,1,9},
    {1,3,9},
    {1,9,3}
};

struct A
{
    int a,b,c;
};

void bfs(int a, int b, int c)
{
    queue<A> q;
    memset(vst, -1, sizeof(vst));
    vst[a][b][c] = 0;
    q.push({a,b,c});

    while (!q.empty())
    {
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();

        if (vst[0][0][0] != -1) break;

        for (int i=0; i<6; i++)
        {
            int na = max(0,a - d[i][0]);
            int nb = max(0,b - d[i][1]);
            int nc = max(0,c - d[i][2]);

            if (vst[na][nb][nc] > -1) continue;

            vst[na][nb][nc] = vst[a][b][c] + 1;
            q.push({na,nb,nc});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];

    bfs(a[0], a[1], a[2]);

    cout << vst[0][0][0] << '\n';

    return 0;
}
