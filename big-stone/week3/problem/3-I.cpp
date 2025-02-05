//
// Created by 이동한 on 2025. 2. 5..
//
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 500000;
int N, K;

// BFS 탐색
int bfs() {
    queue<pair<int, int>> q;  // (현재 위치, 현재 시간)
    q.push({N, 0});
    while (!q.empty()) {
        int subin = q.front().first;
        int time = q.front().second;
        q.pop();

        // 동생의 현재 위치 계산
        int brother = K + (time * (time + 1)) / 2;
        if (brother > MAX) return -1;  // 동생이 범위를 벗어나면 찾을 수 없음
        if (subin == brother) return time;  // 수빈이가 동생을 찾으면 정답

        // 다음 이동 가능한 위치
        vector<int> next_positions;
        if (subin > brother)
            next_positions = {subin - 1,subin+1};
        else
            next_positions = {subin + 1, subin * 2};

        for (int next : next_positions) {
            if (next >= 0 && next <= MAX) {
                q.push({next, time + 1});
            }
        }
    }

    return -1;  // 찾을 수 없는 경우
}

int main() {
    cin >> N >> K;
    if (N == K) {
        cout << "0\n";  // 시작 위치와 동생 위치가 같으면 0초
        return 0;
    }
    cout << bfs() << "\n";
    return 0;
}