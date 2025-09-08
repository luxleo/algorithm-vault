//
// Created by 이동한 on 2025. 9. 8..
//
/** S1 (https://www.acmicpc.net/problem/14888)
 * 백트래킹 문제 / 최대, 최소 범위 정하기
 * 최대정할때 : 가능한 최소 범위에서 갱신을 처리해 나간다.
 * 최소 정할때: 가능한 최대 범위에서 갱신을 처리한다.
 */
#include <bits/stdc++.h>
using namespace std;
int N, a[14], ops[4];
pair<int, int> ret = {-1000000001, 1000000001};

void go(int index, int cur, int pls, int ms, int ml, int div) {
    if (index == N - 1) {
        // 종료조건으로 갱신한다.
        ret.first = max(ret.first, cur);
        ret.second = min(ret.second, cur);
        return;
    }
    if (pls) go(index + 1, cur + a[index + 1], pls - 1, ms, ml, div);
    if (ms) go(index + 1, cur - a[index + 1], pls, ms - 1, ml, div);
    if (ml) go(index + 1, cur * a[index + 1], pls, ms, ml - 1, div);
    if (div) go(index + 1, cur / a[index + 1], pls, ms, ml, div - 1);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int &op: ops) cin >> op; // 크기가 정해진 배열에 원소 받는 방법.
    go(0, a[0], ops[0], ops[1], ops[2], ops[3]);
    cout << ret.first << "\n" << ret.second << endl;
    return 0;
}
