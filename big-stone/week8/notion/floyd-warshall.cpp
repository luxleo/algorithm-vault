//
// Created by 이동한 on 2026. 2. 9..
//

/** 플로이드 워셜 알고리즘
 *  모든 정점에서 모든 정점까지의 최단 경로를 구하는 문제이다.
 *  음수 가중치가 있는 그래프에도 사용될 수 있다.
 *  하지만 음수사이클이 있는 경우에는 사용할 수 없다.
 *  모든 노드쌍 (i,j)에 대하여 k노드를 경유했을 때의 최단거리를 구하여 갱신하는 방식으로 진행한다.
 *  dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); 로 갱신한다.
 *
 *  O(V**3) 의 시간 복잡도로 갱신한다. 따라서 최다 노드 수는 400으로 제한된다.
 */
#include <iostream>
using namespace std;

const int INF = 1e9; // 초기값으로 무한이다.
const int MAX_N = 204;
int dist[MAX_N][MAX_N];

int main() {
    int num_node, num_edge;
    cin >> num_node >> num_edge;

    // 배열 초기화
    memset(dist, INF, sizeof(dist));
    // 시작점, 끝점이 같으면 거리는 0이다.
    for (int i = 0; i < num_node; i++) {
        for (int j = 0; j < num_node; j++) {
            if (i == j) dist[i][j] = 0;
        }
    }

    for (int i = 0; i < num_edge; i++) {
        int s, e, w; // 시작점, 끝점, 가중치
        cin >> s >> e >> w;
        dist[s][e] = min(dist[s][e], w);
    }

    // O(V**3) 의 시간 복잡도로 갱신한다.
    for (int i = 1; i <= num_node; i++) {
        for (int k = 1; k <= num_node; k++) {
            for (int j = 1; j <= num_node; j++) {
                // 만일 경유 경로가 가중치가 있으면 갱신한다.
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // 출력
    for (int i = 1; i <= num_node; i++) {
        for (int j = 1; j <= num_node; j++) {
            if (dist[i][j] == INF) cout << i << " " << j << "INF" << "\n";
            else cout << i << " " << j << " " << dist[i][j] << "\n";
        }
    }
    return 0;
}
