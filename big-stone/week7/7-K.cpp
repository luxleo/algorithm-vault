//
// Created by 이동한 on 2025. 12. 27..
//

/** G2 @see https://www.acmicpc.net/problem/1513
 * DP를 이용한 경우의 수 구하는 문제이다.
 */
#include <bits/stdc++.h>
using namespace std;
int n, m, c, a[51][51], dp[51][51][51][51];
int y, x;
const int mod = 1000007;


int go(int y, int x, int cnt, int prev) {
    if (y > n || x > m) return 0; // 맵의 범위 벗어나면 연산하지 않는다.
    if (y == n && x == m) {
        // 학원에 도착한 경우
        if (a[y][x] == 0 && cnt == 0) return 1; // 학원과 오락실의 위치가 중복 되지 않은 경우
        if (a[y][x] > prev && cnt == 1) return 1; // 학원과 오락실의 위치가 중복인 경우
        return 0; // 위 둘의 경우가 아니면 문제의 조건에 맞지 않으므로 카운트 하지 않는다.
    }
    int &ret = dp[y][x][cnt][prev];
    if (ret != -1) return ret; // 이미 계산된 경우
    ret = 0;
    if (a[y][x] == 0) {
        // 현재 위치가 오락기가 아닌 경우
        ret = (go(y + 1, x, cnt, prev) + go(y, x + 1, cnt, prev)) % mod;
    } else if (a[y][x] > prev) {
        // 현재 위치가 오락기인 경우 문제의 조건에 맞게 이전보다 오락기 번호가 높아야한다.
        ret = (go(y + 1, x, cnt - 1, a[y][x]) + go(y, x + 1, cnt - 1, a[y][x])) % mod;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof dp); // 초기화 조건은 답의 범위 밖으로 정한다 이때 0인 경우가 있으므로 -1
    cin >> n >> m >> c;
    for (int i = 1; i <= c; i++) {
        cin >> y >> x;
        a[y][x] = i;
    }

    for (int i = 0; i <= c; i++) cout << go(1, 1, i, 0) << " ";
    return 0;
}
