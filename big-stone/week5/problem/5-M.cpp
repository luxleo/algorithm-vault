//
// Created by 이동한 on 2025. 8. 31..
//
/** G1 [12100](https://www.acmicpc.net/problem/12100)
 * 1. 배열의 회전을 이용하여 대칭을 통해 모든 방향의 이동로직을 작성하지 않아도 된다.
 * 2. 배열 회전 또는 갱신 할때 temp 임시 배열을 두고 변형후 복사하는 방식으로 변형한다.
 */
#include <bits/stdc++.h>
using namespace std;
int n, ret;

struct Board {
    int mp[24][24];

    void rotate90() {
        int temp[24][24];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // 배열 90도 회전.
                temp[i][j] = mp[n - j - 1][i];
            }
        }
        memcpy(mp, temp, sizeof(mp));
    }

    void move() {
        int temp[24][24];
        for (int i = 0; i < n; i++) {
            int curIdx = -1, check = 0;
            for (int j = 0; j < n; j++) {
                if (mp[i][j] == 0) continue;
                if (check && temp[i][curIdx] == mp[i][j]) {
                    temp[i][curIdx] *= 2;
                    check = 0;
                } else {
                    temp[i][++curIdx] = mp[i][j];
                    check = 1;
                }
            }

            for (curIdx++; curIdx < n; curIdx++) temp[i][curIdx] = 0;
        }
        memcpy(mp, temp, sizeof(mp));
    }

    void calc_max() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ret = max(ret, mp[i][j]);
            }
        }
    }
};

void solve(Board c, int here) {
    if (here == 5) {
        c.calc_max();
        return;
    }
    for (int i = 0; i < 4; i++) {
        Board temp = c;
        temp.move();
        solve(temp, here + 1);
        c.rotate90();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    Board c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c.mp[i][j];
        }
    }
    solve(c, 0);
    cout << ret << endl;
    return 0;
}


