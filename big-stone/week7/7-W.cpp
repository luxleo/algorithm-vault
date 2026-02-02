//
// Created by 5600G on 2026-02-02.
//
/** @see https://www.acmicpc.net/problem/2342
 * dp의 구성을 어떻게 둘 것인가가 중요하다. dp[왼발위치][오른발위치][현재 처리 인덱스]
 */
#include <bits/stdc++.h>
using namespace std;
int dp[5][5][100001], n;
vector<int> v;

int diff(int from, int to)
{
    if(from == 0) return 2;
    //다시 누르면 1
    if(from == to) return 1;
    //반대일 경우
    if(abs(from - to) == 2) return 4; // 갱신 조건을 abs 이용하여 단순화 하였음
    //인접할 경우
    return 3;
}

int solve(int y, int x, int here)
{
    if (here == n) return 0;
    int &ret = dp[y][x][here];
    if (ret != -1) return ret;

    int left = solve(v[here], x, here + 1) + diff(y, v[here]); // 왼발을 움직인 경우
    int right = solve( y, v[here], here+1) + diff(x, v[here]); // 오른발 움직인 경우
    return ret = min(left, right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (true)
    {
        int step;
        cin >> step;
        if (step == 0) break;
        v.push_back(step);
    }
    memset(dp,-1, sizeof(dp));
    n = v.size();
    cout << solve(0,0,0) << "\n";
    return 0;
}
