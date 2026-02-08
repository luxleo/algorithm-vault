//
// Created by 이동한 on 2026. 2. 8..
//
/** @see https://www.acmicpc.net/problem/3653
 * 펜윅트리와 top-header 포인터 이용하여 push_front 구현하기 (-1 업데이트와 +1 업데이트 번갈아 가면서)
 */
#include <bits/stdc++.h>
using namespace std;
const int max_tree_size = 200002;

int t, n, m, tree[max_tree_size], here;
map<int, int> mp;

void update(int idx, int val) {
    while (idx < max_tree_size) {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int sum(int idx) {
    int ret = 0;
    while (idx > 0) {
        ret += tree[idx];
        idx -= (idx & -idx);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        memset(tree, 0, sizeof(tree));
        mp.clear();

        int update_idx = 100001; // top-pointer위치
        // push_front 구현 하기 위해 미리 update_idx 만큼 옮겨준다.
        for (int i = 1; i <= n; i++) {
            update(i + update_idx, 1); // update_idx 만큼 띄어서 카운트 배열 생성
            mp[i] = i + update_idx; // i 번째 DVD의 현재 위치
        }

        for (int i = 0; i < m; i++) {
            cin >> here;
            int idx = mp[here];

            cout << sum(idx) - 1 << (i == m - 1 ? "" : " ");; // 보려는 DVD 앞의 DVD 바로 출력
            update(idx, -1); // 한 칸씩 당기기 위해서 -1 해준다. 즉 DVD 현재 위치에서 제거 하고 제일 앞으로 이동
            --update_idx; // 제일 앞의 포인터 한 칸 이동
            update(update_idx, 1);
            mp[here] = update_idx; // 본 DVD 위치를 제일 앞으로 이동
        }
        cout << "\n";
    }
}
