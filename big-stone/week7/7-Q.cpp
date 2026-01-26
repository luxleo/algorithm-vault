//
// Created by 5600G on 2026-01-26.
//
/** @see https://www.acmicpc.net/problem/1344
 *  에라토스테네스의 체로 소수 구하기,
 *  dp 이용하여 빠른 반환(memoization) 하기
 *  확률 
 */
#include <bits/stdc++.h>
using namespace std;

const int span_num = 18;
double a,b,dp[20][20][20];
bool isPrime[20];

void era()
{
    // 에라토스테네스의 체를 이용하여 소수들을 초기화 해준다.
    fill(isPrime, isPrime+20, 1);
    isPrime[0] = 0; isPrime[1] = 0;
    for (int i=2; i<20; i++)
    {
        for (int j=i*i; j<20; j+=i) isPrime[j] = 0;
    }
}

double go(int idx, int x, int y)
{
    if (idx == span_num) return isPrime[x] || isPrime[y] ? 1.0 : 0.0; // 둘 중 하나의 팀이라도 골 넣은 횟수가 소수인경우 1, 아니면 0 반환
    double &ret = dp[idx][x][y];
    if (ret > -0.5) return ret; // 부동 소수점의 경우 오차가 존재하므로 -1.0 이 아니라 그 근처의 값으로 판단해준다.

    // 확률의 곱셈 법칙과 덧셈 법칙으로 확률 계산을 해준다.
    ret = 0.0;
    ret += go(idx+1, x+1, y) * a*(1-b); // 현재 상태에서 a만 골을 넣을 경우
    ret += go(idx + 1, x, y+1) * b*(1-a);
    ret += go(idx + 1, x+1, y+1) * a*b;
    ret += go(idx + 1, x, y) * (1-a)*(1-b);
    return ret;
}

int main()
{
    scanf("%lf %lf", &a, &b);
    a/=100; b/=100; // 확률 계산의 편의를 위해 100으로 나눈다.
    era();
    memset(dp, -1, sizeof(dp));
    printf("%.6lf", go(0,0,0));
    return 0;
}
