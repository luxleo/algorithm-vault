//
// Created by 5600G on 2026-11-18.
//
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 21;

int N,sum,a[MAXN][MAXN];

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void counting(int board[MAXN][MAXN])
{
    int res = 0;
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            sum = max(sum, board[i][j]);
}

void slide(int board[MAXN][MAXN])
{
    int temp[MAXN][MAXN] = {0};
    for (int i=0; i<N; i++)
    {
        int cnt = 0;
        for (int j=0; j<N; j++)
        {
            if (board[i][j] == 0) continue;
            if (temp[i][cnt] == 0) temp[i][cnt] = board[i][j];
            else if (temp[i][cnt] == board[i][j])
            {
                temp[i][cnt] *= 2;
                cnt++;
            } else
            {
                cnt++;
                temp[i][cnt] = board[i][j];
            }
        }
    }

    memcpy(board,temp, sizeof(temp));
}

void rotate(int board[MAXN][MAXN])
{
    int temp[MAXN][MAXN] = {0};
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            temp[i][j] = board[N-1-j][i];
    memcpy(board,temp, sizeof(temp));
}

void go(int here, int board[MAXN][MAXN])
{
    if (here == 5)
    {
        counting(board);
        return;
    }

    for (int i=0; i<4; i++)
    {
        int cpy[MAXN][MAXN];
        memcpy(cpy, board, sizeof(cpy));

        slide(cpy);
        go(here+1, cpy);
        rotate(board);
    }
}

int main()
{
    fastIO();
    cin >> N;

    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            cin >> a[i][j];

    go(0,a);

    cout << sum << '\n';

    return 0;
}
