//
// Created by 5600G on 2026-06-23.
//
#include <bits//stdc++.h>
using namespace std;

const int MAX_N = 101;
const int dy[] = {-1,1,0,0}, dx[] = {0,0,-1,1};
int R,C,K,x,y,x2,y2, arr[MAX_N][MAX_N], vst[MAX_N][MAX_N];

void bfs(int y, int x, priority_queue<int, vector<int>, greater<int>> &pq)
{
    int ret=1;
    queue<pair<int,int>> q;
    q.emplace(y,x);
    vst[y][x] = 1;

    while (!q.empty())
    {
        auto [cy,cx] = q.front();
        q.pop();
        for (int i=0; i<4; i++)
        {
            int ny = cy+dy[i], nx = cx+dx[i];
            if (ny<0 || ny>=R || nx < 0 || nx >=C || arr[ny][nx] == 1 || vst[ny][nx]) continue;
            q.emplace(ny,nx);
            vst[ny][nx] = 1;
            ret++;
        }
    }

    pq.emplace(ret);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> R >> C >> K;

    for (int i=0; i<K; i++)
    {
        cin >> x >> y >> x2 >> y2;
        for (int k=y; k<y2; k++)
            for (int j=x; j<x2; j++)
                arr[k][j] = 1;
    }

    for (int i=0; i<R; i++)
    {
        for (int j=0; j<C; j++)
        {
            if (arr[i][j] == 0 && vst[i][j] == 0)
                bfs(i,j,pq);
        }
    }

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";
    return 0;
}
