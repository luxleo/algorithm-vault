#include <bits/stdc++.h>
using namespace std;

const int n = 10;
const int dy[] = {-1,1,0,0,-1,-1,1,1};
const int dx[] = {0,0,1,-1,1,-1,1,-1};
int mp[n][n], vst[n][n];

void go_eight(int y, int x)
{
    vst[y][x] = 1;
    cout << y << " " << x << "\n";

    for (int i=0; i<8; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny > n || nx < 0 || nx > n) continue;
        if (vst[ny][nx]) continue;
        go_four(ny, nx);

    }

}

int main()
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++) cin >> mp[i][j];
    }
    go_eight(0,0);
    return 0;
}
