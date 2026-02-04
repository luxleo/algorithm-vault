//
// Created by 5600G on 2026-02-04.
//
/** @see https://www.acmicpc.net/problem/2618
 * 다이내믹 프로그래밍을 활용한 백트래킹
 */
#include <bits/stdc++.h>
using namespace std;

struct Pos
{
    int y, x;
};
int N,W, dp[1001][1001], y,x;
Pos events[1003];

// 경찰차가 현재 위치에서 다음 위치로 움직이는 거리 계산
int moveDist(int from, int to)
{
    return abs(events[from].y - events[to].y) + abs(events[from].x - events[to].x);
}

// 경찰차는 항상 사건의 위치에 있다.
int getMinDist(int p1, int p2)
{
    int nextP = max(p1,p2)+1; // 다음 사건의 위치는 이미 갱신한 사건 다음 순서이다.
    if (nextP == W+2) return 0;
    if (dp[p1][p2]) return dp[p1][p2];

    int move1 = getMinDist(nextP, p2) + moveDist(p1, nextP);
    int move2 = getMinDist(p1, nextP) + moveDist(p2, nextP);
    return dp[p1][p2] = min(move1, move2);
}

void backTrack(int p1, int p2)
{
    int nextP = max(p1,p2) + 1;
    if (nextP == W+2) return;

    int move1 = getMinDist(nextP, p2) + moveDist(p1, nextP);
    int move2 = getMinDist(p1, nextP) + moveDist(p2, nextP);

    if (move1 < move2)
    {
        cout << 1 << "\n";
        backTrack(nextP, p2);
    } else
    {
        cout << 2 << "\n";
        backTrack(p1, nextP);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> W; //scanf("%d %d", &N, &W) 를 사용해서도 뛰어 쓰기로 주어진 결과 입력 받기 가능

    // 경찰차의 위치는 사건 발생 위치와 같으므로
    events[0] = {1,1};
    events[1] = {N,N};

    for (int i=2; i<W+2; i++)
    {
        cin >> events[i].y >> events[i].x;
    }

    cout << getMinDist(0,1) << "\n";
    backTrack(0, 1);
    return 0;
}
