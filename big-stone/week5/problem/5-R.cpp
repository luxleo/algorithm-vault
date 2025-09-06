//
// Created by 이동한 on 2025. 9. 7..
//
/** G2 (https://www.acmicpc.net/problem/17825)
 * 구현 문제 였다. 관건은 윷놀이 판을 구현하는 것.
 * vector<int> v[n] 형식으로 인접연결 리스트 만드는 법.
 * 말 움직이는 로직 구현하는 법(move)이 까다로웠음
 */
#include <bits/stdc++.h>
using namespace std;

int rolls[11], n = 10;
vector<int> mp[54]; // 윷놀이 연결 맵
int v[104]; // 윷놀이 판의 점수, 종료 노드를 100으로 설정 해주었기 때문에 사이즈를 두배로 키움.
int horse[4]; // 말들의 위치

void add(int s, int e) {
    mp[s].emplace_back(e);
}

void initMap() {
    for (int i = 0; i <= 19; i++) add(i, i + 1);
    add(5, 21);
    add(21, 22);
    add(22, 23);
    add(23, 24);
    add(15, 29);
    add(29, 30);
    add(30, 31);
    add(31, 24);

    add(10, 27);
    add(27, 28);
    add(28, 24);
    add(24, 25);
    add(25, 26);
    add(26, 20);
    add(20, 100); // 종점

    v[1] = 2;
    v[2] = 4;
    v[3] = 6;
    v[4] = 8;
    v[5] = 10;
    v[6] = 12;
    v[7] = 14;
    v[8] = 16;
    v[9] = 18;
    v[10] = 20;
    v[11] = 22;
    v[12] = 24;
    v[13] = 26;
    v[14] = 28;
    v[15] = 30;
    v[16] = 32;
    v[17] = 34;
    v[18] = 36;
    v[19] = 38;
    v[20] = 40;
    v[21] = 13;
    v[22] = 16;
    v[23] = 19;
    v[24] = 25;
    v[27] = 22;
    v[28] = 24;
    v[25] = 30;
    v[26] = 35;
    v[29] = 28;
    v[30] = 27;
    v[31] = 26;
};

int move(int here, int moveCnt) {
    if (here == 100) return 100; // 종점인 경우 종료시킴.
    if (mp[here].size() >= 2) {
        // 파란 말판인 경우 파란 화살표로 이동
        here = mp[here][1];
        moveCnt--;
    }
    if (moveCnt) {
        // 주사위 눈이 남아있으면 계속 이동시킨다.
        queue<int> q;
        q.push(here);
        int there;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            there = mp[x][0];
            q.push(there);
            if (there == 100) break;
            moveCnt--;
            if (moveCnt == 0) break;
        }
        return there;
    }
    return here;
};

bool isHorse(int horse_idx, int idx) {
    if (horse_idx == 100) return false;
    for (int i = 0; i < 4; i++) {
        if (i == idx) continue;
        if (horse[i] == horse_idx) return true;
    }
    return false;
};

int go(int here) {
    if (here == n) return 0; // 주사위 10번 넘게 던지면 종료
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        int temp_idx = horse[i];
        int next_idx = move(temp_idx, rolls[here]);
        if (isHorse(next_idx, i)) continue;
        horse[i] = next_idx;
        ret = max(ret, go(here + 1) + v[next_idx]);
        horse[i] = temp_idx; // 원복으로 백트래킹 시킨다.
    }
    return ret;
}

int main() {
    for (int i = 0; i < n; i++) cin >> rolls[i];
    initMap();
    cout << go(0) << endl;
    return 0;
}
