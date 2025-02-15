/** flood fill + 탐색 배열 줄이기(홀,짝)
문제
수빈이는 동생과 숨바꼭질을 하고 있다.
수빈이는 현재 점 N(0 ≤ N ≤ 500,000)에 있고,
동생은 점 K(0 ≤ K ≤ 500,000)에 있다.
수빈이는 걷거나 순간이동을 할 수 있다. 만약,
수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다.
순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.
동생은 항상 걷기만 한다. 동생은 항상 매 초마다 이동을 하며,
이동은 가속이 붙는다. 동생이 이동하는 거리는 이전에 이동한 거리보다 1을 더한 만큼 이동한다.
즉, 동생의 처음 위치는 K, 1초가 지난 후 위치는 K+1, 2초가 지난 후 위치는 K+1+2,
3초가 지난 후의 위치는 K+1+2+3이다.
수빈이와 동생의 위치가 주어졌을 때,
수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지
구하는 프로그램을 작성하시오.
동생을 찾는 위치는 정수 좌표이어야 하고,
수빈이가 0보다 작은 좌표로, 50만보다 큰 좌표로 이동하는 것은 불가능하다.

입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
수빈이가 동생을 찾을 수 없거나, 찾는 위치가 500,000을 넘는 경우에는 -1을 출력한다.

예제 입력 1
5 17
예제 출력 1
2
예제 입력 2
17 5
예제 출력 2
4
 * @see https://www.acmicpc.net/problem/17071
 */
#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 500000;
int vst[2][MAX_N + 4],n,k,ok,turn = 1;
int x;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    if (n == k) {
        cout << 0 << "\n";
        return 0;
    }
    queue<int> q;
    vst[0][n] = 1;
    q.push(n);
    int qSize=0; // flood fill을 위해서 필요하다 turn을 레이어 단위로 증가 시켜줘야하기 때문이다.
    while (true) {
        k += turn;
        if (k>MAX_N) break;
        if (vst[turn%2][k]) {
            // 홀, 짝 단위로 방문한 이력이 있다면 +1, -1 반복해서 그자리로 올 수 있기 때문에
            ok = true;
            break;
        }
        qSize = q.size(); // 레이어 단위로 turn 증가 처리하기 위해서 필요하다
        for (int i =0; i<qSize; i++) {
            x = q.front(); q.pop();
            for (int nx : {x + 1, x-1 , x*2}) {
                if (nx <0 || nx > MAX_N || vst[turn%2][nx]) continue;
                vst[turn%2][nx] = vst[(turn+1)%2][x] +1; // 홀 -> 짝, 짝 -> 홀 단위로 계산해준다.
                if (nx == k) {
                    ok = true;
                    break;
                }
                q.push(nx);
            }
            if (ok) break;
        }
        if (ok) break;
        turn++;
    }
    if (ok) cout << turn << "\n";
    else cout << -1 << "\n";
    return 0;
}

// 17 5
// vst[0][17] = 1
//