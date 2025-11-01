//
// Created by 이동한 on 2025. 11. 1..
//

/** @see https://www.acmicpc.net/problem/2098 G1
 *  비트마스킹 + dp
 *  간선간 이동 비용이 비대칭이라서 순열로 풀이 해야할거 같지만
 *  dp가 갱신되면서 자동으로 갱신되기때문에 조합으로 풀이 가능하다 -> 비트 마스킹 이용가능하다(조합의 n수가 31미만이므로)
 * @return
 */

#include <bits/stdc++.h>
#define MAX_N 16
using namespace std;

const int INF = 987654321;
int N, dp[MAX_N][1 << MAX_N], dist[MAX_N][MAX_N];

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

// top-down 방식으로 갱신한다.
int tsp(int here, int vst) {
    // 만일 모든 지점을 방문했는데 출발 지점으로 돌아가는 경로가 없으면 무한으로 갱신
    if (vst == (1 << N) - 1) return dist[here][0] ? dist[here][0] : INF;
    int &ret = dp[here][vst];
    if (ret != -1) return ret; // 이미 메모이제이션 되어있으면 값 리턴
    ret = INF;
    for (int i = 0; i < N; i++) {
        if (vst & (1 << i)) continue; // 이미 방문한 노드이면 패스
        if (dist[here][i] == 0) continue; // 갈 수 없는 경로인 경우 패스
        // 현재 노드에서 다음 노드로 간 경우를 포함하여 갱신 fibo의 다음 수열 처럼
        ret = min(ret, tsp(i, vst | (1 << i)) + dist[here][i]);
    }
    return ret;
}

int main() {
    fastIO();
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> dist[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << tsp(0, 1) << "\n";
    return 0;
}
