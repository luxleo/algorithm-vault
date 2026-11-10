//
// Created by 이동한 on 2026. 11. 10..
//
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX_N = 100001, MAX_POS = 100000;
int N, K, vst[MAX_N], ret, flag;
map<int, int> mp;
vector<int> track;

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

void dfs(int here, int cnt) {
    if (here == K) {
        mp[cnt]++;
        ret = min(ret, cnt);
        return;
    }

    for (int i = 0; i < 3; i++) {
        int next = move(i, here);
        if (next < 0 || next > MAX_POS) continue;
        if (vst[next]) continue;
        vst[next] = 1;
        dfs(next, cnt++);
        vst[next] = 0;
    }
}

void dfs_track(int here, int cnt, vector<int> &prev) {
    if (flag) return; // 탐색 완료 되었으면 종료한다
    if (cnt == ret) {
        flag = 1;
        track = prev;
        return;
    }
    for (int i = 0; i < 3; i++) {
        int next = move(i, here);
        if (next < 0 || next > MAX_POS) continue;
        if (vst[next]) continue;
        vst[next] = 1;
        prev.emplace_back(next);
        dfs_track(next, cnt++, prev);
        prev.pop_back();
        vst[next] = 0;
    }
}

int main() {
    fastIO();
    cin >> N >> K;

    // dfs 한 번 돌려서 최소 거리 찾는다
    dfs(N, 0);

    // dfs 두 번 돌려서 vector에 담고 최소 거리랑 같으면 배열 반환하고 종료
    memset(vst, 0, sizeof(vst));
    vector<int> prev;
    prev.emplace_back(N);
    dfs_track(N, 0, prev);

    cout << ret << '\n';
    for (int node: track)
        cout << node << " ";
    cout << '\n';
    return 0;
}
