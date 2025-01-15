//
// Created by 이동한 on 2025. 1. 15..
//
#include <bits/stdc++.h>
using namespace std;
const int SIZE_OF_MAP = 101;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int n,m,arr[SIZE_OF_MAP][SIZE_OF_MAP], y,x;

/**
*문제
N×M크기의 배열로 표현되는 미로가 있다.

1	0	1	1	1	1
1	0	1	0	1	0
1	0	1	0	1	1
1	1	1	0	1	1
미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.
위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

입력
첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.

출력
첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.

예제 입력 1     예제 출력 1
4 6           15
101111
101010
101011
111011

 * @see https://www.acmicpc.net/problem/2178
 */
int main() {
    scanf("%d %d",&n,&m);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++){
            scanf("%1d", &arr[i][j]); // (1) 연속한 수 받는 방법
        }
    }
    queue<pair<int,int> > q;
    q.push(make_pair(0,0));
    while (!q.empty()) {
        tie(y,x) = q.front(); q.pop(); // (2) tie 로 구조할당?
        for (int i=0; i<4; i++) {
            int ny = y+dy[i];
            int nx = x+dx[i];
            if (ny>=0 && nx>=0 && ny<n && nx<m && arr[ny][nx]==1) {
                q.push(make_pair(ny,nx));
                arr[ny][nx] = arr[y][x] + 1;
            }
        }
    }
    printf("%d\n", arr[n-1][m-1]);
    return 0;
}
