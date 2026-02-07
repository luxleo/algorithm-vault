//
// Created by 이동한 on 2026. 2. 7..
//
/** @see https://www.acmicpc.net/problem/1514
 * 완탐으로 탐색 하면 3(선택 가능한 한번에 돌릴 수 있는 회전 디스크 수) * 3 (돌리는 양) * 2 (돌리는 방향) = 18을 적용해야한다.
 * 따라서 완탐이 안되므로 dp를 떠올릴 수 있다.
 */
#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int N, cur[101], target[101], dp[101][10][10][10][2]; // dp[현재다이얼인덱스위치][현재다이얼값][다음다이얼값][다다음다이얼값]

int _mod(int x) {
    return x < 0 ? x + 10 : x % 10;
}

/**
 * @param here 현재다이얼 위치
 * @param x 첫번째 디스크 회전량
 * @param y 두번째 디스크 회전량
 * @param z 세번째 디스크 회전량
 * @param rot 회전 방향
 * @return
 */
int go(int here, int x, int y, int z, int rot) {
    if (here == N) return 0;
    int &ret = dp[here][x][y][z][rot];
    if (ret != -1) return ret;

    // 만일 현재 위치에서 돌린 디스크가 타겟과 일치하면 다음과 다다음을 앞으로 당겨서 시계방향 반시계 방향 회전 중 작은 값으로 갱신
    if (_mod(x + cur[here]) == _mod(target[here]))
        return ret = min(go(here + 1, y, z, 0, 0), go(here + 1, y, z, 0, 1));
    ret = INF;
    int _rot = rot ? 1 : -1; // 시계 반시계로 회전 정해주기
    // 1-3 칸 씩 회전
    for (int i = 1; i <= 3; i++) {
        ret = min(ret, 1 + go(here, _mod(x + i * _rot), y, z, rot)); // 현재 다이얼만 회전
        ret = min(ret, 1 + go(here, _mod(x + i * _rot), _mod(y + i * _rot), z, rot)); // 현재 + 다음 디스크 회전
        ret = min(ret, 1 + go(here, _mod(x + i * _rot), _mod(y + i * _rot), _mod(z + i * _rot), rot));
    }
    return ret;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%1d", &cur[i]); // 한개씩 입력 받음
    for (int i = 0; i < N; i++) scanf("%1d", &target[i]); // 한개씩 입력 받음

    memset(dp, -1, sizeof(dp));
    printf("%d\n", min(go(0, 0, 0, 0, 0), go(0, 0, 0, 0, 1)));
    return 0;
}
