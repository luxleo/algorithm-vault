//
// Created by 이동한 on 2026. 1. 5..
//
/** @see https://www.acmicpc.net/problem/16235
 * 구현 문제였다.
 * vector<int> A[i][j]로 한칸에 연속된 나무들을 표현한 것이 참신한 문제.
 * 문제의 조건을 springSummer, autumn, winter로 나누어 구현했다.
 */
#include <bits/stdc++.h>
using namespace std;
int n, m, k, A[11][11], H[11][11];
vector<int> a[11][11]; // 나무는 한 칸에 복수개 있을 수 있으므로 vector 자료형 사용함.

// 한 칸을 기준으로 둘러싼 8칸 좌표
const int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

void springSummer() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j].size() == 0) continue;
            int dead_tree = 0;
            // 가장 어린 나무부터 처리될 수 있도록 정렬한다
            sort(a[i][j].begin(), a[i][j].end()); // 다차원 배열 정렬하는법
            vector<int> temp;
            for (int tree: a[i][j]) {
                if (H[i][j] >= tree) {
                    H[i][j] -= tree;
                    temp.push_back(tree + 1); // 한 살 더 먹더록
                } else {
                    // 양분이 적으면 나무는 죽고 그 나이의 반만큼 양분 증가
                    dead_tree += tree / 2;
                }
            }
            a[i][j] = temp;
            H[i][j] += dead_tree;
        }
    }
}

void autumn() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j].size() == 0) continue;
            for (int tree: a[i][j]) {
                if (tree % 5 == 0) {
                    for (int dir = 0; dir < 8; dir++) {
                        int ny = i + dy[dir];
                        int nx = j + dx[dir];
                        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                        a[ny][nx].push_back(1);
                    }
                }
            }
        }
    }
}

void winter() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            H[i][j] += A[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    // 양분 배열 문제에 맞게 초기화
    fill(&H[0][0], &H[0][0] + 11 * 11, 5);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> A[i][j];
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        a[--x][--y].push_back(z);
    }

    for (int i = 0; i < k; i++) {
        springSummer();
        autumn();
        winter();
    }
    int ret = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ret += a[i][j].size(); // 칸의 나무 모두 더해주기
    cout << ret << "\n";
    return 0;
}
