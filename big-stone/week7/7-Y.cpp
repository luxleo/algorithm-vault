//
// Created by 5600G on 2026-02-03.
//
/** @see https://www.acmicpc.net/problem/3687
 * 그리디 + 다이내믹 프로그래밍
 * 다이내믹 프로그래밍은 최소값 수열을 찾을 때만 사용한다.
 */
#include <bits/stdc++.h>
using namespace std;

const string MAX_VAL = "11111111111111111111111111111111111111111111111111111"; // 최솟값 갱신을 위한 최댓값 초기화
int t, n, dat[]= {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}; // 0-9 까지의 숫자를 만드는데 필요한 성냥개비 수
string dp[101];

// 그리디를 활용하여 가장 만드는 수가 적은 큰 수 부터 채워준다.
string findMax(int here)
{
    string ret = "";
    if (here & 1) // 문제 제약 조건에 2 이상이 있으므로 홀수인 경우 무조건 3이상이다.
    {
        ret += '7';
        here -= 3;
    }
    while (here)
    {
        ret += '1';
        here -= 2;
    }
    return ret;
}

string find_min_str(string a, string b)
{
    if (a.size() == b.size()) return (a < b ? a : b); // "108" , "180" -> "180" return
    if (a.size() < b.size()) return a; // 사이즈 작은 경우 작은 수 반환
    return b;
}

string findMin(int here)
{
    if (here == 0) return "";
    string &ret = dp[here];
    if (ret != MAX_VAL) return ret; // 이미 탐문한 경우 얼리리턴
    for (int i=0; i<=9; i++)
    {
        if (here - dat[i] <0) continue;
        if (here == n && i == 0) continue; // 첫 자리가 0이면 패스한다.
        ret = find_min_str(ret, to_string(i) + findMin(here - dat[i]));
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> n;
        fill(dp, dp+101, MAX_VAL); // 최소값 찾기 위한 최대값 초기화
        cout << findMin(n) << " " << findMax(n) << "\n";
    }
    return 0;
}
