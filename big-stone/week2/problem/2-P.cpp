//
// Created by 이동한 on 2025. 1. 22..
//
#include <bits/stdc++.h>
using namespace std;

/** 전체 경우를 헤아려보기, 그 후 완탐을 생각해보기 이것이 첫번째이다.
 * 이 문제의 경우 최대 64C3의 조합의 경우를 가진다. 약 4000만 이므로 가능하다.

문제
인체에 치명적인 바이러스를 연구하던 연구소에서 바이러스가 유출되었다.
다행히 바이러스는 아직 퍼지지 않았고, 바이러스의 확산을 막기 위해서
연구소에 벽을 세우려고 한다.
연구소는 크기가 N×M인 직사각형으로 나타낼 수 있으며,
직사각형은 1×1 크기의 정사각형으로 나누어져 있다.
연구소는 빈 칸, 벽으로 이루어져 있으며, 벽은 칸 하나를 가득 차지한다.
일부 칸은 바이러스가 존재하며, 이 바이러스는 상하좌우로
인접한 빈 칸으로 모두 퍼져나갈 수 있다. 새로 세울 수 있는 벽의
개수는 3개이며, 꼭 3개를 세워야 한다.
예를 들어, 아래와 같이 연구소가 생긴 경우를 살펴보자.

2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
이때, 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 곳이다.
아무런 벽을 세우지 않는다면, 바이러스는 모든 빈 칸으로 퍼져나갈 수 있다.

2행 1열, 1행 2열, 4행 6열에 벽을 세운다면 지도의 모양은 아래와 같아지게 된다.

2 1 0 0 1 1 0
1 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 1 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
바이러스가 퍼진 뒤의 모습은 아래와 같아진다.

2 1 0 0 1 1 2
1 0 1 0 1 2 2
0 1 1 0 1 2 2
0 1 0 0 0 1 2
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
벽을 3개 세운 뒤, 바이러스가 퍼질 수 없는 곳을 안전 영역이라고 한다.
위의 지도에서 안전 영역의 크기는 27이다.
연구소의 지도가 주어졌을 때 얻을 수 있는 안전 영역 크기의 최댓값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 지도의 세로 크기 N과 가로 크기 M이 주어진다. (3 ≤ N, M ≤ 8)
둘째 줄부터 N개의 줄에 지도의 모양이 주어진다.
0은 빈 칸, 1은 벽, 2는 바이러스가 있는 위치이다.
2의 개수는 2보다 크거나 같고, 10보다 작거나 같은 자연수이다.
빈 칸의 개수는 3개 이상이다.

출력
첫째 줄에 얻을 수 있는 안전 영역의 최대 크기를 출력한다.
 * @see https://www.acmicpc.net/problem/14502
 */
int N,M, arr[8][8],ret;
const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,1,-1};
bool visited[8][8];
vector<pair<int,int>> virusPos, wallPos;
void dfs(int y, int x) {
    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y+dy[i];
        if (nx < 0 || ny < 0 || ny >= N || nx >= M || visited[ny][nx] || arr[ny][nx] == 1) continue;
        visited[ny][nx] = true;
        // arr[ny][nx] = 2; -> 이러면 구조가 변한다 방문 배열로만 처리해주어야한다.
        dfs(ny,nx);
    }
}
int solve() {
    // 조합의 경우 만큼 호출 되므로 항상 초기화 해주어야 한다.
    fill(&visited[0][0], &visited[0][0] + 8 * 8, false);
    int cnt = 0;
    for (auto pos : virusPos) {
        visited[pos.first][pos.second] = true;
        dfs(pos.first, pos.second);
    }
    for (int i =0; i<N; i++) {
        for (int j =0; j<M; j++) {
            if (arr[i][j] == 0 && !visited[i][j]) cnt++; // (문제에 할당된 배열 arr을 변경하는 것은 원복하지 않는이상 안된다.
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i< N; i++) {
        for (int j =0; j< M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) virusPos.push_back(make_pair(i,j));
            else if (arr[i][j] == 0) wallPos.push_back(make_pair(i,j));
        }
    }
    ret = 0;
    // 브루트 포스(조합)이용하여 가능한 벽의 위치를 선택하고 solve 시도
    // 조합은 3 depth 까지는 for 문으로 구한다.
    for (int i =0; i<wallPos.size(); i++) {
        for (int j =0; j<i; j++) {
            for (int k=0; k<j; k++) {
                arr[wallPos[i].first][wallPos[i].second] = 1;
                arr[wallPos[j].first][wallPos[j].second] = 1;
                arr[wallPos[k].first][wallPos[k].second] = 1;
                ret = max(ret, solve());
                arr[wallPos[i].first][wallPos[i].second] = 0;
                arr[wallPos[j].first][wallPos[j].second] = 0;
                arr[wallPos[k].first][wallPos[k].second] = 0;
            }
        }
    }
    cout << ret << "\n";
    return 0;
}
