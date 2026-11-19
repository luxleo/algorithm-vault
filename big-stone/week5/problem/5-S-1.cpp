//
// Created by 5600G on 2026-11-18.
//
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int N,a[12], p,minu,mult,divi, ret1 = -INF, ret2 = INF;

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

/**
 * @brief index번째 숫자까지 계산이 끝난 상태에서, 다음 연산자를 하나씩 끼워 넣는 DFS 재귀 함수
 * @param index 현재까지 계산에 반영된 마지막 숫자의 인덱스 (0 ~ n-1)
 * @param cur   현재까지 앞에서부터 순서대로 계산된 누적 값
 * @param plus, minus, mul, div 각각 남아 있는 연산자의 개수
 */
void go(int here, int acc, int plus, int minus, int multiple, int division)
{
    if (here == N-1)
    {
        ret1 = max(ret1, acc);
        ret2 = min(ret2, acc);
        return;
    }

    // 남아 있는 연산자(> 0)가 있다면 하나를 소모(-1)하고 다음 숫자(a[index + 1])와 계산하여 재귀 호출
    if (plus > 0) go(here+1, acc+a[here+1], plus-1, minus, multiple, division);
    if (minus > 0) go(here+1, acc-a[here+1], plus, minus-1, multiple, division);
    if (multiple > 0) go(here+1, acc*a[here+1], plus, minus, multiple-1, division);
    if (division > 0) go(here+1, acc/a[here+1], plus, minus, multiple, division-1);
}

int main()
{
    fastIO();
    cin >> N;
    for (int i=0; i<N; i++)
        cin >> a[i];

    cin >> p >> minu >> mult >> divi;

    go(0, a[0], p, minu, mult, divi);

    cout << ret1 << '\n' << ret2 << '\n';
    return 0;
}
