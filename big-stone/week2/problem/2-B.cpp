//
// Created by 이동한 on 2025. 1. 15..
//
#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 51;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int iter,n,m,cnt,ret,arr[MAX_SIZE][MAX_SIZE],y,x,ny,nx;
void bfs(int ix, int iy) {
    queue<pair<int,int>> q;
    q.push(make_pair(ix,iy));
    while (!q.empty()) {
        tie(x,y) = q.front(); q.pop();
        for (int i=0;i<4;i++) {
            nx = x+dx[i];
            ny = y+dy[i];
            if (ny>=0 && ny<n && nx>=0 && nx<m // (1) 오버플로 조건 먼저 처리
                && arr[ny][nx]==1) {
                arr[ny][nx] = arr[y][x] + 1;
                q.push(make_pair(nx,ny));
            }
        }
    }
}

/**
* 한나가 배추를 재배하는 땅은 고르지 못해서 배추를 군데군데 심어 놓았다. 배추들이 모여있는 곳에는 배추흰지렁이가 한 마리만 있으면 되므로 서로 인접해있는 배추들이 몇 군데에 퍼져있는지 조사하면 총 몇 마리의 지렁이가 필요한지 알 수 있다. 예를 들어 배추밭이 아래와 같이 구성되어 있으면 최소 5마리의 배추흰지렁이가 필요하다. 0은 배추가 심어져 있지 않은 땅이고, 1은 배추가 심어져 있는 땅을 나타낸다.

1	1	0	0	0	0	0	0	0	0
0	1	0	0	0	0	0	0	0	0
0	0	0	0	1	0	0	0	0	0
0	0	0	0	1	0	0	0	0	0
0	0	1	1	0	0	0	1	1	1
0	0	0	0	1	0	0	1	1	1

입력
입력의 첫 줄에는 테스트 케이스의 개수 T가 주어진다. 그 다음 줄부터 각각의 테스트 케이스에 대해 첫째 줄에는 배추를 심은 배추밭의 가로길이 M(1 ≤ M ≤ 50)과 세로길이 N(1 ≤ N ≤ 50), 그리고 배추가 심어져 있는 위치의 개수 K(1 ≤ K ≤ 2500)이 주어진다. 그 다음 K줄에는 배추의 위치 X(0 ≤ X ≤ M-1), Y(0 ≤ Y ≤ N-1)가 주어진다. 두 배추의 위치가 같은 경우는 없다.

예제 입력 2         예제 출력 2
7                 6
9 9 9 9 9 9 9
9 2 1 2 1 2 9
9 1 8 7 8 1 9
9 2 7 9 7 2 9
9 1 8 7 8 1 9
9 2 1 2 1 2 9
9 9 9 9 9 9 9
 * @see https://www.acmicpc.net/problem/1012
 */
int main() {
    cin >> iter;
    while (iter--) {
        cin >> m >> n >> cnt;
        fill(&arr[0][0], &arr[0][0] + 51 * 51, 0); // (2) 항상 초기화를 잊지마라 !!!
        ret = 0;
        for (int i = 0; i < cnt; i++) {
            scanf("%d %d", &x,&y); // (1) scanf 잘 활용하기
            arr[y][x] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 1) {
                    ret++;
                    bfs(j,i);
                }
            }
        }
        cout << ret << "\n";
    }
    return 0;
}
