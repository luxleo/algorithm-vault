//
// Created by 이동한 on 2025. 11. 2..
//

#include <bits/stdc++.h>
#define MAX_T 1001
#define MAX_STEP 34
#define MAX_TREE 2
using namespace std;

int T, W, a[MAX_T], dp[MAX_T][MAX_TREE][MAX_STEP];

int go(int idx, int tree, int cnt) {
    if (cnt < 0) return -1e9;
    if (idx == T) return 0;
    int &ret = dp[idx][tree][cnt];
    if (~ret) return ret;
    int acc = (tree == a[idx] - 1) ? 1 : 0;
    return ret = max(go(idx + 1, tree ^ 1, cnt - 1), go(idx + 1, tree, cnt)) + acc;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> T >> W;
    for (int i = 0; i < T; i++) {
        cin >> a[i];
    }
    cout << max(go(0, 0, W), go(0, 1, W - 1)) << "\n";
    return 0;
}
