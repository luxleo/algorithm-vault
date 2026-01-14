//
// Created by 이동한 on 2026. 1. 14..
//
#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX; // 최솟값 갱신은 경계값의 최대값을 사용
int a[101][101], ret = INF, n = 10;
map<int, int> mp;
/** @see https://www.acmicpc.net/problem/17136
 * 백트래킹 + 그리디(사이즈가 큰 종이부터 처리) 가 포함되어있었다.
 * dfs의 jump를 어떻게 구현하는지에 대한 고민이 필요했다.
 *
 * Square tiling 문제였다
 */
void draw(int y, int x, int _size, int val) {
    for (int i = y; i < y + _size; i++)
        for (int j = x; j < x + _size; j++)
            a[i][j] = val;
}

bool coverable(int y, int x, int _size) {
    if (y + _size > n || x + _size > n) return false; // 맵 벗어나면 오류
    for (int i = y; i < y + _size; i++)
        for (int j = x; j < x + _size; j++)
            if (a[i][j] == 0)return false;
    return true;
}

void dfs(int y, int x, int cnt) {
    if (cnt >= ret) return;
    if (x == n) {
        // 백트래킹 종료 조건으로 행을 따라 끝점까지 이동한 경우이다.
        dfs(y + 1, 0, cnt);
        return;
    }
    if (y == n) {
        // 모든 칸을 다 순회한 경우
        ret = min(ret, cnt);
        return;
    }
    if (a[y][x] == 0) {
        dfs(y, x + 1, cnt);
        return;
    }
    for (int _num = 5; _num > 0; _num--) {
        if (mp[_num] == 5) continue; // 해당 종이를 다 썼다면 다음 종이로 넘어간다.
        if (coverable(y, x, _num)) {
            mp[_num]++;
            draw(y, x, _num, 0); // 0으로 만들어 색종이로 덮음 처리
            dfs(y, x + _num, cnt + 1); // 갱신할때 행방향으로만 해주는 아이디어.
            draw(y, x, _num, 1); // 1로 다시 원복
            mp[_num]--;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    dfs(0, 0, 0);
    cout << (ret == INF ? -1 : ret);
    return 0;
}
