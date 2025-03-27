//
// Created by 이동한 on 2025. 3. 27..
//
/** bitmasking + dfs + connecteed component
문제 G3
대략 위의 그림과 같이 생긴 성곽이 있다.
굵은 선은 벽을 나타내고, 점선은 벽이 없어서
지나다닐 수 있는 통로를 나타낸다. 이러한 형태의
성의 지도를 입력받아서 다음을 계산하는 프로그램을
작성하시오.

이 성에 있는 방의 개수
가장 넓은 방의 넓이
하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기
위의 예에서는 방은 5개고, 가장 큰 방은 9개의 칸으로
이루어져 있으며, 위의 그림에서 화살표가 가리키는 벽을
제거하면 16인 크기의 방을 얻을 수 있다.

성은 M × N(1 ≤ M, N ≤ 50)개의 정사각형 칸으로
이루어진다. 성에는 최소 두 개의 방이 있어서, 항상
하나의 벽을 제거하여 두 방을 합치는 경우가 있다.

입력
첫째 줄에 두 정수 N, M이 주어진다. 다음 M개의
줄에는 N개의 정수로 벽에 대한 정보가 주어진다.
벽에 대한 정보는 한 정수로 주어지는데, 서쪽에 벽이
있을 때는 1을, 북쪽에 벽이 있을 때는 2를, 동쪽에
벽이 있을 때는 4를, 남쪽에 벽이 있을 때는 8을 더한
값이 주어진다. 참고로 이진수의 각 비트를 생각하면 쉽다.
따라서 이 값은 0부터 15까지의 범위 안에 있다.

출력
첫째 줄에 1의 답을,
둘째 줄에 2의 답을,
셋째 줄에 3의 답을 출력한다.

예제 입력 1
7 4
11 6 11 6 3 10 6
7 9 6 13 5 15 5
1 10 12 7 13 7 5
13 11 10 8 10 12 13
예제 출력 1
5
9
16
 * @see https://www.acmicpc.net/problem/2234
 */
#include <bits/stdc++.h>
using namespace std;
int M,N, arr[51][51],vst[51][51],memo[2501];
int roomNum, mxArea, ans;
// 방향을 동서 남북으로 맞추어준다. (0)
const int dy[] = {0,-1,0,1};
const int dx[] = {-1,0,1,0};

/**
 * 경로의 길이를 dfs로 탐색하는 전형적인 패턴. 숙지할것
 * @param y
 * @param x
 * @param cnt roomNum이다.
 * @return
 */
int dfs(int y, int x, int cnt) {
    if (vst[y][x]) return 0;
    vst[y][x] = cnt;
    int ret = 1;
    // 벽 유무 불리언 배열을 비트마스킹 이용한 이진수로 나타내었음.
    for (int i=0; i<4; i++) {
        if (!(arr[y][x] & (1<<i))) {
            int ny = y+dy[i]; int nx = x + dx[i];
            ret += dfs(ny,nx, cnt);
        }
    }
    return ret;
}
int main() {
    // ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++)
            cin >> arr[i][j];
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (!vst[i][j]) {
                roomNum++;
                memo[roomNum] = dfs(i,j,roomNum);
                mxArea = max(mxArea, memo[roomNum]);
            }
        }
    }

    // 하나의 벽을 뚫는 다는 것은 결국 이웃한 서로 다른 '두 개'의 방을 합하는 것과 같다.
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (i+1 < N) {
                int a = vst[i+1][j];
                int b = vst[i][j];
                if (a != b) ans = max(ans, memo[a] + memo[b]);
            }
            if ( j+1 < M) {
                int a = vst[i][j+1];
                int b = vst[i][j];
                if ( a != b) // 두 방을 합쳐주자.
                    ans = max(ans, memo[a] + memo[b]);
            }
        }
    }
    cout << roomNum << "\n" << mxArea << "\n" << ans << "\n";
    return 0;
}
