//
// Created by 이동한 on 2026. 2. 11..
//

/** @see https://www.acmicpc.net/problem/1613
 * 추이를 구현 하는 문제였다. : a -> b , b->c => a -> c
 * 이를 위해 플로이드 워셜을 이용하여 모든 정점을 거쳐가며 관계가 있는지 확인한다.
 */
#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 401;
int n, k, a, b, c, s, e, dist[MAX_N][MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        // a가 b 보다 먼저 일어났으면 -1
        dist[a][b] = -1;
        // b가 a 보다 먼저 일어났으면 1
        dist[b][a] = 1;
    }

    // 플로이드 워셜을 이용해 모든 정점을 거쳐가며 관계가 있는지 확인한다.
    // k: 거쳐가는 지점, 반드시 루프 최상위에 있어야한다.
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                // i -> k, k -> j => i -> j
                if (dist[i][k] == -1 && dist[k][j] == -1)
                    dist[i][j] = -1;
                if (dist[i][k] == 1 && dist[k][j] == 1)
                    dist[i][j] = 1;
            }
        }
    }

    int t = 0;
    cin >> t;
    while (t--) {
        cin >> s >> e;
        cout << dist[s][e] << "\n";
    }

    return 0;
}
