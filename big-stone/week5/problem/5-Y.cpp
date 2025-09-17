//
// Created by 이동한 on 2025. 9. 17..
//
/** G2 단순 구현 문제 (https://www.acmicpc.net/submit/17822)
 * 필요로직
 * 1. 배수에 해당하는 원판 회전시키기.
 * 2. 인접한 원소 지우는 로직
 * 3. 지우는 로직 처리후 평균기준으로 1만큼 가감 해주기
 *
 */
#include <bits/stdc++.h>
using namespace std;

int N, M, T;
int a[51][51], vst[51][51], ret;
int x, d, k, y;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void _rot(int y, int dir, int k) {
    vector<int> v;
    for (int i = 0; i < M; i++) v.emplace_back(a[y][i]);
    // 시계 방향회전
    if (dir == 1) rotate(v.begin(), v.begin() + k, v.end());
        // 반시계 회전
    else rotate(v.begin(), v.begin() + M - k, v.end());
    for (int i = 0; i < M; i++) a[y][i] = v[i]; // 회전한 원판으로 갱신
}

bool flag = 1;

void dfs(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = (x + dx[i] + M) % M;
        if (ny < 0 || ny >= N) continue;
        if (vst[ny][nx]) continue;
        if (a[ny][nx] == a[y][x]) {
            // 같은수면 0으로 만들어준다.
            vst[y][x] = vst[ny][nx] = 1;
            flag = 0;
            dfs(ny, nx);
        }
    }
}

bool findAdj() {
    flag = 1;
    memset(vst, 0, sizeof(vst));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] == 0) continue;
            if (vst[i][j]) continue;
            dfs(i, j);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (vst[i][j]) a[i][j] = 0; // 인접하면 0으로 만들어준다.
        }
    }
    return flag;
};

void processWithAverage() {
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j]) {
                sum += a[i][j];
                cnt++;
            }
        }
    }

    // 실수 나눗셈은 형변환 해주고 나누어 주어야한다. 그렇지 않으면 정수 나눗셈으로 나옴
    double avg = (double) sum / (double) cnt;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] == 0) continue;
            if (a[i][j] > avg) a[i][j]--;
            else if (a[i][j] < avg) a[i][j]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> T;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> a[i][j];
    }
    for (int i = 0; i < T; i++) {
        cin >> x >> d >> k;
        // X의 배수만 회전한다.
        for (int j = x - 1; j < N; j += x) _rot(j, d, k);
        if (findAdj()) processWithAverage();
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) ret += a[i][j];
    }
    cout << ret << endl;
    return 0;
}
