//
// Created by 이동한 on 2026. 11. 10..
//
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX_N = 500001;
int N, K, vst[MAX_N], ret;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int move(int idx, int here) {
    switch (idx) {
        case 0: return here - 1;
        case 1: return here + 1;
        case 2: return here * 2;
        default: return -1;
    }
}

/**
 *
 * @param here 수빈의 현재 위치
 * @param cnt 경과 시간 초
 * @param acc 초에 따른 이동거리 누적
 */
void dfs(int here, int cnt, int acc) {
    if (here == K + acc) {
        ret = min(ret, cnt);
        return;
    }

    for (int i = 0; i < 3; i++) {
        int next = move(i, here);
        if (next < 0 || next > MAX_N) continue;
        if (vst[next]) continue;
        vst[next] = 1;
        dfs(next, cnt + 1, acc + cnt + 1);
        vst[next] = 0;
    }
}

int main() {
    fastIO();
    cin >> N >> K;

    dfs(N, 0, 0);
    if (ret == INF) cout << -1 << '\n';
    else cout << ret << '\n';
    return 0;
}
