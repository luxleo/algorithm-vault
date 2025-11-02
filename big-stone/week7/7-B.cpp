//
// Created by 이동한 on 2025. 11. 1..
//

/** @see https://www.acmicpc.net/problem/17070 G5
 * 3차원 dp 그래프 나타내기 차원은 필요로 하는 정보에 따라 달라진다.
 * 따라서 복잡하게 생각할 필요가 없다.
 * 여기서 3차원은 y,x,dir으로 좌표 (x,y) 에서 방향 dir 인 파이프의 시작점으로 부터 이동횟수이다.
 * 갱신할때 이전 dp에서의 값을 더하는 방향으로 해준다.
 */
#include <bits/stdc++.h>
#define MAX_N 20
using namespace std;

int N, a[MAX_N][MAX_N], dp[MAX_N][MAX_N][3];

bool check(int y, int x, int dir) {
    if (dir == 0 || dir == 2) return a[y][x] == 0;
    return a[y][x] == 0 && a[y][x - 1] == 0 && a[y - 1][x] == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> a[i][j];
        }
    }
    dp[1][2][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            // 처음 위치가 가로인 경우 ( 가로로 밀거나, 대각선으로 밀거나)
            if (check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][0];
            if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][0];

            // 처음 위치가 대각선인 경우 ( 가로,대각선,세로로 민다).
            if (check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][1];
            if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][1];
            if (check(i + 1, j, 2)) dp[i + 1][j][2] += dp[i][j][1];

            // 처음 위치가 세로인 경우 }
            if (check(i + 1, j, 2)) dp[i + 1][j][2] += dp[i][j][2];
            if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][2];
        }
    }
    int ret = dp[N][N][0];
    ret += dp[N][N][1];
    ret += dp[N][N][2];
    cout << ret << "\n";
    return 0;
}
