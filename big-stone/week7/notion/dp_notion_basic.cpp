//
// Created by 5600G on 2025-10-23.
//

#include <bits/stdc++.h>
using namespace std;

int n,m, dp[101][2][31], b[101];
int go(int idx,int tree, int cnt)
{
    if (cnt < 0) return -1e9;
    if (idx == n) return 0;
    int &ret = dp[idx][tree][cnt];

    if (ret != -1) return ret;
    return ret = max(go(idx+1, tree ^ 1 ,cnt-1), go(idx+1, tree, cnt)) + (tree == b[idx] - 1);
}

int main()
{
    memset(dp, -1, sizeof(dp)); // 1. dp배열 초기화
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> b[i];
    cout << max(go(0,0,m), go(0,1,m)) << "\n";
    return 0;
}
