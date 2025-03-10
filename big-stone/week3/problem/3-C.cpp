//
// Created by 이동한 on 2025. 2. 6..
//
#include <bits/stdc++.h>
using namespace std;

/** GPT 코드이다. 일반적으로 dfs 보다 bfs가 성능이 좋지만 지역변수를 많이 생성하기 때문에 성능 저하가 심하게 일어났다.
문제
N×N크기의 땅이 있고, 땅은 1×1개의 칸으로 나누어져 있다.
각각의 땅에는 나라가 하나씩 존재하며, r행 c열에 있는 나라에는 A[r][c]명이 살고 있다.
인접한 나라 사이에는 국경선이 존재한다. 모든 나라는 1×1 크기이기 때문에, 모든 국경선은 정사각형 형태이다.
오늘부터 인구 이동이 시작되는 날이다.
인구 이동은 하루 동안 다음과 같이 진행되고, 더 이상 아래 방법에 의해 인구 이동이 없을 때까지 지속된다.
국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라면, 두 나라가 공유하는 국경선을 오늘 하루 동안 연다.
위의 조건에 의해 열어야하는 국경선이 모두 열렸다면, 인구 이동을 시작한다.
국경선이 열려있어 인접한 칸만을 이용해 이동할 수 있으면, 그 나라를 오늘 하루 동안은 연합이라고 한다.
연합을 이루고 있는 각 칸의 인구수는 (연합의 인구수) / (연합을 이루고 있는 칸의 개수)가 된다. 편의상 소수점은 버린다.
연합을 해체하고, 모든 국경선을 닫는다.
각 나라의 인구수가 주어졌을 때, 인구 이동이 며칠 동안 발생하는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N, L, R이 주어진다. (1 ≤ N ≤ 50, 1 ≤ L ≤ R ≤ 100)
둘째 줄부터 N개의 줄에 각 나라의 인구수가 주어진다.
r행 c열에 주어지는 정수는 A[r][c]의 값이다. (0 ≤ A[r][c] ≤ 100)
인구 이동이 발생하는 일수가 2,000번 보다 작거나 같은 입력만 주어진다.

출력
인구 이동이 며칠 동안 발생하는지 첫째 줄에 출력한다.

예제 입력 1
2 20 50
50 30
20 40
예제 출력 1
1

@see https://www.acmicpc.net/problem/16234
 */
int visited[54][54], a[54][54], n, l, r, sum, cnt,cy,cx,nx,ny;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
queue<pair<int, int>> q; // (0) bfs와 관련된 변수를 전역화 하여 스택에서 불필요한 변수 생성을 막는다.
vector<pair<int, int>> alliance;
void bfs(int y, int x) {
    alliance.clear();
    q.emplace(y, x); // 복사 객체를 안만들어서 성능 좋아진다.
    alliance.emplace_back(y,x);
    visited[y][x] = 1;
    sum = a[y][x];

    while (!q.empty()) {
        cy = q.front().first;
        cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            ny = cy + dy[i];
            nx = cx + dx[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[ny][nx]) continue;

            int diff = abs(a[ny][nx] - a[cy][cx]);
            if (diff >= l && diff <= r) {
                visited[ny][nx] = 1;
                q.emplace(ny, nx);
                alliance.emplace_back(ny, nx);
                sum += a[ny][nx];
            }
        }
    }

    if (!alliance.empty()) {
        int new_population = sum / alliance.size();
        for (auto &country : alliance) {
            a[country.first][country.second] = new_population;
        }
    }
}

int main() {
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    bool moved;
    while (true) {
        moved = false;
        memset(visited,0,sizeof(visited));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    sum = 0;
                    bfs(i, j);
                    if (sum > a[i][j]) moved = true; // If an alliance was formed
                }
            }
        }

        if (!moved) break;
        cnt++;
    }

    cout << cnt << "\n";
    return 0;
}