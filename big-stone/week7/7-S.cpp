//
// Created by 5600G on 2026-01-28.
//
/** @see https://www.acmicpc.net/problem/1509
 * dp 배열이 한번에 여러개 사용 될 수도 있다. (dp,dp2)
 * 분할의 갱신 조건이 현재까지의 문자열이 팰린드롬인 경우를 떠올려야했다.
 * 메모이제이션 문제 였다.
 */
#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
string s;
int dp[2501][2501], dp2[2501];

int go(int idx)
{
    if (idx == s.size()) return 0; // 문자열 초과하였으면 팰린드롬이 하나도 없는거.
    if (dp2[idx] != INF) return dp2[idx]; // 이미 계산하였으면 반환 (메모이제이션
    int &ret = dp2[idx];
    for (int step = 1; idx + step <=s.size(); step++)
    {
        // 현재 위치 부터 step까지가 펠린드롬인 경우 잘라주고 다음 덩어리를 계산한다. (자르면 펠린드롬이 나오므로 + 1 해준다).
        if (dp[idx][step]) ret = min(ret, 1 + go(idx+step));
    }
    return ret;
}

int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    for (int i=0; i<s.size(); i++) dp[i][1] = 1;
    for (int i=0; i<s.size()-1; i++)
    {
        if (s[i] == s[i+1]) dp[i][2] = 1;
    }
    // 팰린드롬 길이가 3이상인 경우
    // _size 설정이 좀 까다로운데 시작점을 포함한 길이 이므로 전체 길이와 같아도 된다.
    for (int _size=3; _size<=s.size(); _size++)
        for (int i=0; i+_size<=s.size(); i++)
        {
            // 양끝 문자가 같고 사이가 펠린드롬이면 펠린드롬이다.
            if (s[i] == s[i+_size-1] && dp[i+1][_size-2]) dp[i][_size] = 1;
        }
    fill(dp2,dp2+2501,INF);
    cout << go(0) << "\n";
    return 0;
}
