//
// Created by 이동한 on 2025. 1. 23..
//
#include <bits/stdc++.h>
using namespace std;
int N,M, arr[102][102], visited[102][102],iterCnt, cheeseCnt;
int dy[] = {-1,1,0,0}; int dx[] = {0,0,-1,1};
bool flag = false;
vector<pair<int,int>> v;
void dfs(int y, int x) {
    visited[y][x] = 1;
    if (arr[y][x] == 1) {
        v.push_back(make_pair(y, x));
        return;
    }
    for (int i =0; i<4; i++) {
        int ny = y+ dy[i];
        int nx = x+dx[i];
        // 경계 조건 잘 정해주는게 굉장히 중요하다 nx<=0 때문에 계속해서 오류났다.
        if (nx <0 || ny <0 || nx>=M || ny>=N || visited[ny][nx] ) continue;
        dfs(ny,nx);
    }
    return;
}
/**
*입력으로 사각형 모양의 판의 크기와 한 조각의 치즈가 판 위에 주어졌을 때,
*공기 중에서 치즈가 모두 녹아 없어지는 데 걸리는 시간과 모두 녹기 한 시간 전에
*남아있는 치즈조각이 놓여 있는 칸의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에는 사각형 모양 판의 세로와 가로의 길이가 양의 정수로 주어진다.
세로와 가로의 길이는 최대 100이다. 판의 각 가로줄의 모양이 윗 줄부터 차례로
둘째 줄부터 마지막 줄까지 주어진다.
치즈가 없는 칸은 0, 치즈가 있는 칸은 1로 주어지며 각 숫자 사이에는 빈칸이 하나씩 있다.

출력
첫째 줄에는 치즈가 모두 녹아서 없어지는 데 걸리는 시간을 출력하고,
둘째 줄에는 모두 녹기 한 시간 전에 남아있는 치즈조각이 놓여 있는 칸의 개수를 출력한다.

예제 입력 1
13 12
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 1 0 0 0
0 1 1 1 0 0 0 1 1 0 0 0
0 1 1 1 1 1 1 0 0 0 0 0
0 1 1 1 1 1 0 1 1 0 0 0
0 1 1 1 1 0 0 1 1 0 0 0
0 0 1 1 0 0 0 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0

예제 출력 1
3
5
 * @see https://www.acmicpc.net/problem/2636
 */
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i =0; i< N; i++) {
        for (int j = 0; j<M; j++) {
            cin >> arr[i][j];
        }
    }
    while (true) {
        fill(&visited[0][0], &visited[0][0] + 102 * 102,0);
        v.clear(); // 입력을 반복하는 경우 초기화 해주어야할 변수가 무엇인지 생각해보기.
        flag = true;
        dfs(0,0);
        cheeseCnt = v.size();
        // 재귀를 하는 도중에 데이터를 바꾸어 버리면 탐색 조건이 변경되어 온전히 탐색하지 못한다.
        // 따라서 탐색 조건에 따라 탐색이 끝난후에 상태를 업데이트 해주어야한다.
        for (auto pos : v) {
            arr[pos.first][pos.second] = 0;
        }
        iterCnt++;
        for (int i =0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (arr[i][j] == 1) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) break;
    }
    cout << iterCnt << "\n" << cheeseCnt << "\n";
    return 0;
}
