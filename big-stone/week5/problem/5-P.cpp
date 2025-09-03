//
// Created by 이동한 on 2025. 9. 4..
//
/** G5 https://www.acmicpc.net/problem/15662
 * rotate를 이용하여 돌아가는 식 구현.
 */
#include <bits/stdc++.h>
using namespace std;
int T, K;
string arr[1004];

/**
 * 연속적으로 회전하는 최저 인덱스를 찾는다.
*/
int findL(int pos) {
    for (int i = pos; i >= 1; i--) {
        if (arr[i][6] == arr[i - 1][2]) {
            return i;
        }
    }
    return 0;
};

/**
 * 연속적으로 회전하는 최대 인덱스를 찾는다.
 * @param pos
 * @return
 */
int findR(int pos) {
    for (int i = pos; i <= T - 2; i++) {
        if (arr[i][2] == arr[i + 1][6]) {
            return i;
        }
    }
    return T - 1;
}

void rot(int pos, int dir) {
    if (!dir) rotate(arr[pos].begin(), arr[pos].begin() + 1, arr[pos].end()); // 반시계 방향 회전
    else rotate(arr[pos].begin(), arr[pos].begin() + arr[pos].size() - 1, arr[pos].end());
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> arr[i];
    }
    cin >> K;
    int a, b;
    for (int i = 0; i < K; i++) {
        cin >> a >> b;
        a--;
        b = (b == -1 ? 0 : 1); // 로직 작성 편의를 위해서 매핑
        int l = findL(a);
        int r = findR(a);
        int cnt = 0;
        for (int i = a; i >= l; i--) {
            // 연속적으로 돌아가는 최저 인덱스까지 돌린다.
            rot(i, cnt % 2 == 0 ? b : !b); // cnt에 따라 이전 방향과 반대 방향으로 돌아간ㄷ.
            cnt++;
        }
        cnt = 1;
        for (int i = a + 1; i <= r; i++) {
            rot(i, cnt % 2 == 0 ? b : !b);
            cnt++;
        }
    }
    int ret = 0;
    for (int i = 0; i < T; i++) if (arr[i][0] == '1') ret++;
    cout << ret << endl;
    return 0;
}
