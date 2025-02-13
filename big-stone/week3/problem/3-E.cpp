//
// Created by 이동한 on 2025. 2. 10..
//
#include <bits/stdc++.h>
using namespace std;

/**
 *
 * @see https://www.acmicpc.net/problem/12869
 */
int dat[3], vst[61][61][61],N;
int diff[6][3] = {
    {9,3,1},
    {9,1,3},
    {3,9,1},
    {3,1,9},
    {1,9,3},
    {1,3,9}
};
struct Pos {
    int a,b,c;
};
int solve(int a, int b, int c) {
    vst[a][b][c] = 1;
    queue<Pos> q;
    q.push({a,b,c}); // (0) struct의 경우 q.emplace(a,b,c) 꼴로 안되더라.
    while (!q.empty()) {
        a = q.front().a;
        b = q.front().b;
        c = q.front().c;
        q.pop(); // (1) 꼭 비워주자
        if (vst[0][0][0]) break;
        for (int i =0; i< 6; i++) {
            int na = max(0,a - diff[i][0]);
            int nb = max(0,b - diff[i][1]);
            int nc = max(0,c - diff[i][2]);
            if (vst[na][nb][nc]) continue;
            vst[na][nb][nc] = vst[a][b][c] +1;
            q.push({na,nb,nc});
        }
    }
    return vst[0][0][0] -1;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> dat[i];
    }
    cout << solve(dat[0],dat[1],dat[2]) << "\n";
    return 0;
}
