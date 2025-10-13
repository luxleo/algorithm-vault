//
// Created by 이동한 on 2025. 10. 13..
//
/** G4 @see https://www.acmicpc.net/problem/14002
 * 증가하는 수열을 실제로 출력해야할 때 사용하는 알고리즘이 달라진다.
 * 핵심은 prev_list[i] 에 이전에 해당하는 idx 인 j를 할당하여 링크리스트 형식으로 만들어준다.
 * 해당 문제는 증가하는 부분수열을 구하는 개념이므로 외워야한다.
 */
#include <bits/stdc++.h>
using namespace std;
int n, dat[1001], cnt[1001], prev_list[1001], ret = 1, idx;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void go(int idx) {
    if (idx == -1) return;
    go(prev_list[idx]);
    cout << dat[idx] << " ";
}

int main() {
    fastIO();
    cin >> n;
    fill(prev_list, prev_list + 1001, -1);
    fill(cnt, cnt + 1001, 1);
    for (int i = 0; i < n; i++) {
        cin >> dat[i];
        for (int j = 0; j < i; j++) {
            if (dat[j] < dat[i] && cnt[i] < cnt[j] + 1) {
                cnt[i] = cnt[j] + 1;
                prev_list[i] = j;
                // idx를 갱신해야하므로 ret = max(ret, cnt[i])로 갱신하지 않고 if이용
                if (ret < cnt[i]) {
                    ret = cnt[i];
                    idx = i; // 가장 마지막에 시작할 idx 갱신
                }
            }
        }
    }
    cout << ret << "\n";
    go(idx);
    return 0;
}
