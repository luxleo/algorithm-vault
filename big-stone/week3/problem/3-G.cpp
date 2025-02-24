/** bfs는 단순히 격자형태의 그래프에서 4방향으로만 뻗어가는 것이 아니다.
 * 테스트 케이스의 예외적인 케이스도 잘 고려하자.
 * 트리 모양(루트노드에서 뻗어가는)의 그래프에서의 BFS!!!
문제
수빈이는 동생과 숨바꼭질을 하고 있다.
수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고,
동생은 점 K(0 ≤ K ≤ 100,000)에 있다.
수빈이는 걷거나 순간이동을 할 수 있다. 만약,
수빈이의 위치가 X일 때 걷는다면 1초 후에
X-1 또는 X+1로 이동하게 된다.
순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때,
수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 그리고,
가장 빠른 시간으로 찾는 방법이 몇 가지 인지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력
첫째 줄에 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
둘째 줄에는 가장 빠른 시간으로 수빈이가 동생을 찾는 방법의 수를 출력한다.

예제 입력 1
5 17
예제 출력 1
4
2
 *
 * @see https://www.acmicpc.net/problem/12851
 */
#include <bits/stdc++.h>
using namespace std;
const int MAX = 200000; // (0) 100000이하의 노드에서만 *2 연산 시행하도록 허용
int n,k, vst[MAX+1],now,next;
long long cnt[MAX+1];

int main() {
    cin >> n >> k;
    if (n == k) {
        cout << 0 << "\n" << 1 << "\n";
        return 0;
    }
    queue<int> q;
    vst[n] = 1;//(0) 제일 처음 갱신되는 경로 수가 1이 되어야한다. 0으로 초기화 하면 계속 0이된다.
    cnt[n] = 1;
    q.push(n);
    while (!q.empty()) {
        now = q.front(); q.pop();
        for (int next : {now - 1, now+1, now *2}) {
            if (next < 0 || next > MAX) continue;
            // 최초로 방문 하는 경우 : 직전 방문 길이 + 1을 할당하고, 노드까지
            // 도달하는 방법도 갱신해준다.
            if (!vst[next]) {
                vst[next] = vst[now] +1;
                cnt[next] += cnt[now]; // (0)경로 갱신은 더한다.
                q.push(next);
            } else if (vst[next] == vst[now] + 1) {
                // 다른 경로를 통해서 현재노드 까지 최소로 도달한 경우
                // 또 다른 경우의 수를 더해준다.
                cnt[next] += cnt[now];
            }
        }
    }
    cout << vst[k] - 1 << "\n" << cnt[k] << "\n";
    return 0;
}
