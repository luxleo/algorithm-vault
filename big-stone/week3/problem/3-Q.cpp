//
// Created by 이동한 on 2025. 2. 23..
//
/**
문제
한수는 캠프를 마치고 집에 돌아가려 한다.
한수는 현재 왼쪽 아래점에 있고 집은 오른쪽 위에 있다.
그리고 한수는 집에 돌아가는 방법이 다양하다.
단, 한수는 똑똑하여 한번 지나친 곳을 다시 방문하지는 않는다.

      cdef  ...f  ..ef  ..gh  cdeh  cdej  ...f
      bT..  .T.e  .Td.  .Tfe  bTfg  bTfi  .Tde
      a...  abcd  abc.  abcd  a...  a.gh  abc.
거리 :  6     6     6     8     8    10    6
위 예제는 한수가 집에 돌아갈 수 있는 모든 경우를 나타낸 것이다.
T로 표시된 부분은 가지 못하는 부분이다. 문제는 R x C 맵에 못가는
부분이 주어지고 거리 K가 주어지면 한수가 집까지도
도착하는 경우 중 거리가 K인 가짓수를 구하는 것이다.

입력
첫 줄에 정수
R(1 ≤ R ≤ 5), C(1 ≤ C ≤ 5), K(1 ≤ K ≤ R×C)가
공백으로 구분되어 주어진다. 두 번째부터 R+1번째 줄까지는 R×C
맵의 정보를 나타내는 '.'과 'T'로
구성된 길이가 C인 문자열이 주어진다.

출력
첫 줄에 거리가 K인 가짓수를 출력한다.

예제 입력 1
3 4 6
....
.T..
....
예제 출력 1
4
 * @see https://www.acmicpc.net/problem/1189
 */
#include <bits/stdc++.h>
using namespace std;
int R,C,K;
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};
char arr[6][6];
int vst[6][6];
string s;

int go(int y, int x) {
    if (y == 0 && x == C-1) {
        // 종료조건이고 최단거리 경로인 경우 + 1 반환
        if (vst[y][x] == K) return 1;
        return 0;
    }
    int ret = 0;
    // 그래프 분기 처리 bfs로 구현시 어려움이 있음.
    for (int i=0; i<4; i++) {
        // ny,nx 를 전역변수로 설정하면 맨마지막으로 호출된 go를 기준으로
        // 갱신 되므로 '-문제라인' 이 제대로 작동하지 않는다.
        int ny = y+dy[i];
        int nx = x+dx[i];
        if (ny<0 || ny>=R || nx < 0 || nx>=C || vst[ny][nx]) continue;
        vst[ny][nx] = vst[y][x] + 1;
        ret+=go(ny,nx);
        vst[ny][nx] = 0; // -문제라인
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C >> K;
    for (int i=0; i<R;i++) {
        cin >> s; // 연속한 문자열 받는 방법.
        for (int j =0; j<C; j++) {
            arr[i][j] = s[j];
            if (arr[i][j] == 'T') vst[i][j] = 1;
        }
    }
    vst[R-1][0] = 1;
    cout << go(R-1,0) << "\n";
    return 0;
}
