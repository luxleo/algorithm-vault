//
// Created by 이동한 on 2025. 1. 16..
//
#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 101;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int arr[MAX_SIZE][MAX_SIZE], n,m,k,xd,yd,xu,yu;
vector<int> v;

void bfs(int ix, int iy) {
    int x,y,nx,ny, ret=1;
    queue<pair<int, int >> q;
    q.push(make_pair(iy,ix));
    arr[iy][ix] = 1;
    while (!q.empty()) {
        tie(y,x) = q.front(); q.pop();
        for (int i=0; i<4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (nx>=0 && nx<n && ny >= 0 && ny<m
                && arr[ny][nx] == 0) {
                arr[ny][nx] = arr[y][x] + 1;
                ret++; //(0) bfs는 인접 사각형들을 동시적으로 업데이트 하므로, 루프를 돌떄마다 영역 갯수를 업데이트 해주어야한다.
                q.push(make_pair(ny,nx));
            }
        }
    }
    v.push_back(ret);
}

/**
 * 영역 전체 갯수 문제는 bfs로 접근이 어렵다 (동시에 업데이트 되기 때문)
 * 따라서 dfs가 편할것임.
 * @see https://www.acmicpc.net/problem/2583
 */
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> m >> n >> k;
    for (int i=0; i< k; i++) {
        cin >> xd >>yd >> xu >> yu; // (1) 이 영역 그리는 부분이 어려웠음 -> 직사각형은 좌표 두 개(대각선 좌표)로 구현 가능하다.
        for (int x= xd; x< xu; x++ ) {
            for (int y= yd; y< yu; y++) {
                arr[y][x] =-1;
            }
        }
    }
    for (int y = 0; y<m; y++) {
        for (int x = 0; x<n; x++) {
            if (arr[y][x] == 0) bfs(x,y);
        }
    }

    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for (int el : v) {
        cout << el << " ";
    }

    return 0;
}
