//
// Created by 5600G on 2026-02-03.
//
/** @see https://www.acmicpc.net/problem/1480
 * bitwise 로 조합을 dp 에 담아 계산한다.
 * 진입점을 모든 시작 노드로 넓혀 진행하는 케이스
 */
#include <bits/stdc++.h>
using namespace std;
int n,m,c, dat[14], dp[21][1 << 14][21];

int go(int here, int jwelBit, int capacity)
{
    if (here == m) return 0; // 가능한 가방을 넘어섰으면 컷
    int &ret = dp[here][jwelBit][capacity];
    if (ret) return ret;
    ret = max(ret, go(here + 1, jwelBit, c)); // 현재 가방 채우지 않고 계속해서 넘겨준다. (진입점을 모든 가방에서 시작하도록)
    for (int i=0; i<n; i++)
    {
        bool isJwelPicked = (1<<i) & jwelBit;
        bool pickable = (capacity - dat[i]) >=0;
        // 갱신할 때 현재 보석을 가방에 담았으므로 갱신되어 돌아온 값에 + 1 을 해주어야 한다.
        if (pickable && !isJwelPicked) ret = max(ret, go(here, jwelBit | (1<<i), capacity - dat[i]) + 1); // here 가방에 현재 인덱스 보석을 담고 dp 진행
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> c;
    for (int i=0; i<n; i++) cin >> dat[i];
    cout << go(0, 0, c) << "\n";
    return 0;
}
