//
// Created by 이동한 on 2025. 1. 16..
//
#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int N, arr[101][101],x,y,nx,ny,ret=0;
bool visited[101][101];
void bfs(int iy, int ix,int target) {
    queue<pair<int,int>> q;
    q.push(make_pair(iy, ix));
    visited[iy][ix] = true;
    while (!q.empty()) {
        tie(y,x) = q.front(); q.pop();
        for (int i= 0; i<4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (nx>=0 && nx< N && ny>=0  && ny<N
                && arr[ny][nx] > target
                && visited[ny][nx] == false) {
                visited[ny][nx] = true;
                q.push(make_pair(ny, nx));
            }
        }
    }
}

/**
*문제
* 이제 위와 같은 지역에 많은 비가 내려서 높이가 4 이하인 모든 지점이 물에 잠겼다고 하자. 이 경우에 물에 잠기는 지점을 회색으로 표시하면 다음과 같다.

6	8	2	6	2
3	2	3	4	6
6	7	3	3	2
7	2	5	3	6
8	9	5	2	7
물에 잠기지 않는 안전한 영역이라 함은 물에 잠기지 않는 지점들이 위, 아래, 오른쪽 혹은 왼쪽으로 인접해 있으며 그 크기가 최대인 영역을 말한다.
위의 경우에서 물에 잠기지 않는 안전한 영역은 5개가 된다(꼭짓점으로만 붙어 있는 두 지점은 인접하지 않는다고 취급한다).
또한 위와 같은 지역에서 높이가 6이하인 지점을 모두 잠기게 만드는 많은 비가 내리면 물에 잠기지 않는 안전한 영역은 아래 그림에서와 같이 네 개가 됨을 확인할 수 있다.

6	8	2	6	2
3	2	3	4	6
6	7	3	3	2
7	2	5	3	6
8	9	5	2	7
이와 같이 장마철에 내리는 비의 양에 따라서 물에 잠기지 않는 안전한 영역의 개수는 다르게 된다. 위의 예와 같은 지역에서 내리는 비의 양에 따른
모든 경우를 다 조사해 보면 물에 잠기지 않는 안전한 영역의 개수 중에서 최대인 경우는 5임을 알 수 있다.
어떤 지역의 높이 정보가 주어졌을 때, 장마철에 물에 잠기지 않는 안전한 영역의 최대 개수를 계산하는 프로그램을 작성하시오.

입력
첫째 줄에는 어떤 지역을 나타내는 2차원 배열의 행과 열의 개수를 나타내는 수 N이 입력된다. N은 2 이상 100 이하의 정수이다.
둘째 줄부터 N개의 각 줄에는 2차원 배열의 첫 번째 행부터 N번째 행까지 순서대로 한 행씩 높이 정보가 입력된다.
각 줄에는 각 행의 첫 번째 열부터 N번째 열까지 N개의 높이 정보를 나타내는 자연수가 빈 칸을 사이에 두고 입력된다. 높이는 1이상 100 이하의 정수이다.

출력
첫째 줄에 장마철에 물에 잠기지 않는 안전한 영역의 최대 개수를 출력한다.

예제 입력 1
5
6 8 2 6 2
3 2 3 4 6
6 7 3 3 2
7 2 5 3 6
8 9 5 2 7
예제 출력 1
5
 * @see https://www.acmicpc.net/problem/2468
 * !!!반대로 생각하기 -> 물을 채워야한다고 생각했으나 채워지는 높이 보다 높은 지역을 찾는 connected Component 문제이다.
 */
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i= 0; i<N; i++) {
        for (int j= 0; j<N; j++) {
            cin >> arr[i][j];
        }
    }
    for (int h = 0; h<=100; h++) {
        int cnt = 0;
        fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
        for (int i= 0; i<N; i++) {
            for (int j= 0; j<N; j++) {
                if (arr[i][j] > h && visited[i][j] == false) {
                    cnt++;
                    bfs(i, j, h);
                }
            }
        }
        ret = max(ret, cnt);
    }
    cout << ret << "\n";
    return 0;
}
