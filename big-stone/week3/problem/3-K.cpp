//
// Created by 이동한 on 2025. 2. 18..
//
/** flood fill로 풀이하는 문제이다.
문제
두 마리의 백조가 호수에서 살고 있었다.
그렇지만 두 마리는 호수를 덮고 있는 빙판으로 만나지 못한다.
호수는 행이 R개, 열이 C개인 직사각형 모양이다. 어떤 칸은 얼음으로 덮여있다.
호수는 차례로 녹는데, 매일 물 공간과 접촉한 모든 빙판 공간은 녹는다.
두 개의 공간이 접촉하려면 가로나 세로로
닿아 있는 것만 (대각선은 고려하지 않는다) 생각한다.
아래에는 세 가지 예가 있다.
...XXXXXX..XX.XXX ....XXXX.......XX .....XX..........
....XXXXXXXXX.XXX .....XXXX..X..... ......X..........
...XXXXXXXXXXXX.. ....XXX..XXXX.... .....X.....X.....
..XXXXX..XXXXXX.. ...XXX....XXXX... ....X......XX....
.XXXXXX..XXXXXX.. ..XXXX....XXXX... ...XX......XX....
XXXXXXX...XXXX... ..XXXX.....XX.... ....X............
..XXXXX...XXX.... ....XX.....X..... .................
....XXXXX.XXX.... .....XX....X..... .................
      처음               첫째 날             둘째 날
백조는 오직 물 공간에서 세로나 가로로만(대각선은 제외한다) 움직일 수 있다.
며칠이 지나야 백조들이 만날 수 있는 지 계산하는 프로그램을 작성하시오.

입력
입력의 첫째 줄에는 R과 C가 주어진다. 단, 1 ≤ R, C ≤ 1500.
다음 R개의 줄에는 각각 길이 C의 문자열이 하나씩 주어진다.
'.'은 물 공간, 'X'는 빙판 공간, 'L'은 백조가 있는 공간으로 나타낸다.

출력
첫째 줄에 문제에서 주어진 걸리는 날을 출력한다.

예제 입력 2
4 11
..XXX...X..
.X.XXX...L.
....XXX..X.
X.L..XXX...
예제 출력 2
2
 *
 * @see
 */
#include <bits/stdc++.h>
using namespace std;
const int max_n = 1501;
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};
char arr[max_n][max_n];
int vst_s[max_n][max_n], vst[max_n][max_n];
queue<pair<int,int>> sq,sq_temp, wq,wq_temp;
int R,C, sX,sY,day;
int y,x;
string iBuff;

// 큐를 빠르게 비워주는 방법
void qClear(queue<pair<int,int>> &q) {
    queue<pair<int,int>> empty;
    swap(q,empty);
}
// 방문배열을 이용하므로 방문하는 지도에서 '.'인 경우 'L'로 바꿀 필요가 없다.
bool move_swan() {
    while (sq.size()) {
        tie(y,x) = sq.front(); sq.pop();
        for (int i =0; i<4; i++) {
            int ny = y+ dy[i];
            int nx = x+ dx[i];
            if (ny < 0 || ny >=R || nx < 0 || nx >=C || vst_s[ny][nx]) continue;
            vst_s[ny][nx] = 1;
            if (arr[ny][nx] == 'L') return true;
            else if (arr[ny][nx] == '.') sq.emplace(ny,nx);
            else sq_temp.emplace(ny,nx); // flood fill 의 핵심 로직으로 임시 큐에 새로 시작할 레이어의 좌표 저장
        }
    }
    return false;
}
void move_water() {
    while (wq.size()) {
        tie(y,x) = wq.front(); wq.pop();
        for (int i =0; i<4; i++) {
            int ny = y+dy[i];
            int nx = x+dx[i];
            if (ny<0 || ny >=R || nx < 0 || nx >=C || vst[ny][nx]) continue;
            if (arr[ny][nx] == 'X') {
                vst[ny][nx] = 1;
                arr[ny][nx] = '.';
                wq_temp.emplace(ny,nx); // flood fill 의 핵심로직 : 임시 큐에 새로 시작할 지점 저장
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    for (int i =0; i<R; i++) {
        cin >> iBuff;
        for (int j=0; j<C; j++) {
            arr[i][j] = iBuff[j];
            if (arr[i][j] == 'L') {sX = j; sY = i;} // 백조 한마리를 기준으로 할 것이기 때문에 큐에 넣지 않고 위치만 할당한다.
            if (arr[i][j] == '.' || arr[i][j] == 'L') {
                vst[i][j] =1;
                wq.emplace(i,j);
            }
        }
    }
    // 마지막으로 확인된 백조를 기준으로 진행한다.
    sq.emplace(sY,sX);
    vst_s[sY][sX] = 1;
    while (true) {
        if (move_swan()) break;
        move_water();
        wq = wq_temp;
        sq = sq_temp;
        qClear(wq_temp);
        qClear(sq_temp);
        day++;
    }
    cout << day << "\n";
    return 0;
}
