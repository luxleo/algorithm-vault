//
// Created by 이동한 on 2025. 2. 8..
//
#include <bits/stdc++.h>
using namespace std;

/**
문제
지훈이는 미로에서 일을 한다. 지훈이를 미로에서 탈출하도록 도와주자!
미로에서의 지훈이의 위치와 불이 붙은 위치를 감안해서 지훈이가 불에
타기전에 탈출할 수 있는지의 여부, 그리고 얼마나 빨리 탈출할 수 있는지를 결정해야한다.

지훈이와 불은 매 분마다 한칸씩 수평또는 수직으로(비스듬하게 이동하지 않는다) 이동한다.
불은 각 지점에서 네 방향으로 확산된다.
지훈이는 미로의 가장자리에 접한 공간에서 탈출할 수 있다.
지훈이와 불은 벽이 있는 공간은 통과하지 못한다.

입력
입력의 첫째 줄에는 공백으로 구분된 두 정수 R과 C가 주어진다.
단, 1 ≤ R, C ≤ 1000 이다. R은 미로 행의 개수, C는 열의 개수이다.
다음 입력으로 R줄동안 각각의 미로 행이 주어진다.
각각의 문자들은 다음을 뜻한다.

#: 벽
.: 지나갈 수 있는 공간
J: 지훈이의 미로에서의 초기위치 (지나갈 수 있는 공간)
F: 불이 난 공간
J는 입력에서 하나만 주어진다.

출력
지훈이가 불이 도달하기 전에 미로를 탈출 할 수 없는 경우 IMPOSSIBLE 을 출력한다.
지훈이가 미로를 탈출할 수 있는 경우에는 가장 빠른 탈출시간을 출력한다.

예제 입력 1
4 4
####
#JF#
#..#
#..#
예제 출력 1
3
 * @see https://www.acmicpc.net/problem/4179
 * 가중치가 1인 경로 탐색 => bfs로 해결가능 !!
 * 문제 해결 전략 : 불을 먼저 다 돌리고 지훈이를 돌린다 이떄 2가지를 염두에둔다.
 *
 * 1. 지훈이 방문 시간이 불 방문 시간보다 적어야함
 * 2. 예외 케이스를 고려하여 (불이 모든 좌표에 없는 경우) 방문 배열 초기화를 INF로 해야한다.
 */
const int INF = 98765432; // (1) 중요한것은 예외 케이스 카운트 능력이다.
int R,C,jvst[1001][1001], fvst[1001][1001];
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};
int fx,fy,jx,jy;
int ans = -1;
queue<pair<int,int>> jq,fq;
char temp;

void fbfs() {
    while (!fq.empty()) {
        tie(fy,fx) = fq.front(); fq.pop();
        for (int i = 0; i<4; i++) {
            int ny = fy + dy[i];
            int nx = fx + dx[i];
            if (ny< 0 || nx <0 || ny>=R || nx>=C || fvst[ny][nx] != INF) continue;
            fvst[ny][nx] = fvst[fy][fx] + 1;
            fq.emplace(ny,nx);
        }
    }
}

void jbfs() {
    while (!jq.empty()) {
        tie(jy,jx) = jq.front(); jq.pop();
        if (jy == 0 || jy == R-1 || jx == 0 || jx ==C-1) {
            ans = jvst[jy][jx];
            return;
        }
        for (int i = 0; i<4; i++) {
            int ny = jy + dy[i];
            int nx = jx + dx[i];

            if (ny< 0 || nx <0 || ny>=R || nx>=C || jvst[ny][nx]) continue;
            if (jvst[jy][jx] + 1 >= fvst[ny][nx]) continue; //(0) 지훈이는 불보다 빨리 도착시킨다.
            jvst[ny][nx] = jvst[jy][jx] + 1;
            jq.emplace(ny,nx);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    fill(&fvst[0][0], &fvst[0][0] + 1001 * 1001, INF); // (1) 이렇게 처리 해주지 않으면 안된다.
    for (int i=0; i<R; i++) {
        for (int j= 0; j<C; j++) {
            cin >> temp;
            if (temp == '#') {
                jvst[i][j] = 1;
                fvst[i][j] = 1;
            } else if (temp == 'J') {
                jq.emplace(i,j);
                jvst[i][j] = 1;
            } else if (temp == 'F') {
                fq.emplace(i,j);
                fvst[i][j] = 1;
            }
        }
    }

    fbfs();
    jbfs();
    if (ans == -1) cout << "IMPOSSIBLE" << "\n";
    else cout << ans << "\n";
    return 0;
}
