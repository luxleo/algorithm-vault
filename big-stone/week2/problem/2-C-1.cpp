//
// Created by 5600G on 2026-06-22.
//
#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 101;
int N,max_h,cur_h, mp[MAX_SIZE][MAX_SIZE], vst[MAX_SIZE][MAX_SIZE],ret;
int dy[] = {-1,1,0,0}, dx[] = {0,0,-1,1};

void dfs(int y, int x)
{
    vst[y][x] = 1;
    for (int i=0; i<4; i++)
    {
        int ny = y+dy[i];
        int nx = x+dx[i];
        if (ny>=N || ny<0 || nx>=N || nx<0 || vst[ny][nx] || mp[y][x] <= cur_h) continue;
        dfs(ny,nx);
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            int temp;
            cin >> temp;
            mp[i][j] = temp;
            max_h = max(max_h, temp);
        }
    }
    for (int i=1; i<=max_h; i++)
    {
        cur_h = i;
        memset(vst,0,sizeof(vst));
        int temp = 0;
        for (int r=0; r<N; r++)
        {
            for (int c=0; c<N; c++)
            {
                if (mp[r][c] > cur_h && vst[r][c] == 0)
                {
                    dfs(r,c);
                    temp++;
                }
            }
        }
        ret = max(ret, temp);
    }
    cout << ret;
}
