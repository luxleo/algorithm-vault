//
// Created by 이동한 on 2025. 11. 1..
//
/** @see https://www.acmicpc.net/problem/1103
 *
 */
#include <bits/stdc++.h>
#define MAX_N 51
using namespace std;

int N, M, dp[MAX_N][MAX_N];
string s;
char a[MAX_N][MAX_N];
bool vst[MAX_N][MAX_N];
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

/**
 *
 * @param y y cordination
 * @param x x cordination
 * @return check if point is fit into map
 */
bool in(int y, int x) {
    return y >= 0 && y < N && x >= 0 && x < M;
}

int go(int y, int x) {
    // 맵 안에 포함되지 않거나 구멍에 빠지면 0 반환
    if (!in(y, x) || a[y][x] == 'H') return 0;

    // 만일 이미 방문한 지점인 경우 계속해서 순회가 가능하므로 -1 반환
    if (vst[y][x] == 1) {
        cout << -1 << "\n";
        exit(0);
    }
    int &ret = dp[y][x];
    // 캐싱된 값이 있으면 반환 - dynamic programming
    if (ret) return ret;

    // 일종의 dfs 처럼 가능한 탐사의 경우의 수를 모두 탐색하기 위한 기법
    vst[y][x] = true;
    int step = (int) a[y][x] - '0';
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i] * step;
        int nx = x + dx[i] * step;
        ret = max(ret, 1 + go(ny, nx));
    }
    vst[y][x] = false;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < M; j++) {
            a[i][j] = s[j];
        }
    }
    cout << go(0, 0) << "\n";
    return 0;
}
