//
// Created by 5600G on 2026-02-04.
//
/** @see https://www.acmicpc.net/problem/1315
 * dp 안에서 방문 배열 초기화가 중요했다.
 * dp 는 배열들의 인덱스를 의미에 따라 지정하는 것이 중요하다.
 */
#include <bits/stdc++.h>
using namespace std;
struct Game
{
    int STR, INT, PNT;
};
vector<Game> games;
const int MAX_STAT = 1001;
const int MAX_GAME = 101;
int n, dp[MAX_STAT][MAX_STAT]; // dp[STR][INT] 로 클리어 가능한 최대 게임수를 저장한다.
bool vst[MAX_GAME];

/**
 * 메서드 한번 실행으로 주어진 STR, INT 에서 모든 퀘스트를 순회 하므로 dp를 신뢰할 수 있다.
 * @param STR
 * @param INT
 * @return
 */
int go(int STR, int INT)
{
    int &ret = dp[STR][INT];
    if (ret != -1) return ret;
    ret = 0;
    int pnt = 0;
    vector<int> track;

    // 먼저 현재 스탯으로 깰 수 있는 퀘스트를 다 깬다.
    for (int i=0; i<n; i++)
    {
        if (games[i].STR <= STR || games[i].INT <= INT)
        {
            ret++; // 현재 스탯으로 클리어 가능한 모든 퀘스트를 세야하므로 vst 여부와 상관 없이 갱신한다.
            if (!vst[i]) // 방문 하지 않은 경우 포인트 획득 가능하다.
            {
                pnt += games[i].PNT;
                vst[i] = true;
                track.push_back(i);
            }
        }
    }

    // 깨고 나서 얻은 포인트를 분배 했을때 갈 수 있는 퀘스트 들중 최선의 것으로 dp를 한번 더 갱신 해준다.
    for (int i=0; i<=pnt; i++)
    {
        int nextStr = min(1000,STR + i);
        int nextInt = min(1000,INT + (pnt - i));
        ret = max(ret, go(nextStr, nextInt));
    }

    // 그래프 확장 방식으로 탐색하고 있으므로 탐색 끝나고 나면 원복 시켜준다.
    for (int game : track)
        vst[game] = false;
    return ret;
}

int main()
{   scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        int STR, INT, PNT;
        scanf("%d %d %d", &STR, &INT, &PNT);
        games.push_back({STR, INT, PNT});
    }
    memset(dp,-1, sizeof(dp)); // 스탯으로 클리어하지 못하는 경우가 있기 때문에 -1 로 초기화
    printf("%d\n", go(1,1));
    return 0;
}
