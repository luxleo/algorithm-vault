//
// Created by 이동한 on 2025. 8. 29..
//
/** G4[17144](https://www.acmicpc.net/problem/17144)
 */
#include <bits/stdc++.h>
using namespace std;
int r, c, t, mp[54][54], tmp[54][54], ret;
vector<pair<int, int> > v1, v2;
int dy1[] = {0, -1, 0, 1};
int dx1[] = {1, 0, -1, 0};
int dy2[] = {0, 1, 0, -1};
int dx2[] = {1, 0, -1, 0};

/**
 * trail을 따라 미세먼지를 이동시킨다.
 * @param v : trail이다 위의 경우 반시계 아래의 공청기의 경우 시계 방향
 */
void purge(vector<pair<int, int> > &v) {
    for (int i = v.size() - 1; i > 0; i--) {
        mp[v[i].first][v[i].second] = mp[v[i - 1].first][v[i - 1].second];
    }
    mp[v[0].first][v[0].second] = 0;
}

/**
 * 퍼저나가는 중심지에서 사방으로 중심지의 값에 5를 나눈 값만큼 퍼뜨린다.
 * 이떄 퍼져나갈수 있는 조건은 공청기가 없고 mp안의 범위에 있는 점들이다.
 * tmp 배열에 감소 값을 두는 이유는 인접한 경우 정확히 업데이트 되지 않기 때문이다.
 */
void spread() {
    fill(&tmp[0][0], &tmp[0][0] + 54 * 54, 0); // 임시 배열 초기화
    queue<pair<int, int> > q;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mp[i][j] != -1 && mp[i][j] > 0) {
                q.emplace(i, j);
            }
        }
    }
    while (!q.empty()) {
        int y, x;
        tie(y, x) = q.front();
        q.pop();
        int diff = mp[y][x] / 5;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy1[i];
            int nx = x + dx1[i];
            // if (ny >= 0 && ny < r && nx >= 0 && nx < c && mp[ny][nx] != -1) {
            //     tmp[ny][nx] += diff;
            //     mp[ny][nx] -= diff;
            // }
            if (ny < 0 || ny >= r || nx < 0 || nx >= c || mp[ny][nx] == -1) continue;
            tmp[ny][nx] += diff;
            mp[y][x] -= diff; // 출발지에서만 감소해줘야함 이거 때문에 계속 틀림
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            mp[i][j] += tmp[i][j]; // 임시배열의 값을 종심지에 덮어써준다.
        }
    }
}

vector<pair<int, int> > getTrail(int iy, int ix, const int dy[], const int dx[]) {
    vector<pair<int, int> > v;
    int y = iy, x = ix;
    int idx = 0;
    while (true) {
        int ny = y + dy[idx];
        int nx = x + dx[idx];
        if (ny == iy && nx == ix) break;
        if (ny < 0 || ny >= r || nx >= c || nx < 0) {
            // 바람이 꺾이는 모서리 부분에 도달한 경우 방향을 꺾어준다.
            idx++;
            ny = y + dy[idx];
            nx = x + dx[idx];
        }
        if (ny == iy && nx == ix) break;
        y = ny;
        x = nx;
        v.emplace_back(ny, nx);
    }
    return v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> r >> c >> t;
    bool isFirst = true;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == -1) {
                // 공청기 자리인 경우 미세먼지의 이동경로를 기록한다.
                // 이떄 이동경로는 위: 시계반대 방향, 아래: 시계방향이다.
                if (isFirst) {
                    // 처음으로 공청기를 마주한경우, 즉 위 부분의 공청기이다.
                    v1 = getTrail(i, j, dy1, dx1);
                    isFirst = false;
                } else {
                    v2 = getTrail(i, j, dy2, dx2);
                }
            }
        }
    }
    while (t--) {
        spread();
        purge(v1);
        purge(v2);
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mp[i][j] != -1) {
                ret += mp[i][j];
            }
        }
    }
    cout << ret << endl;
    return 0;
}
