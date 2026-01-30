//
// Created by 5600G on 2026-01-30.
//

/** @see https://www.acmicpc.net/problem/1450
 * 냅색문제, 전형적인 상태공간탐색트리이다.
 * N의 범위가 30이기 때문에 2**30 (약 10억) 을 시간내에 처리하기 위해서 meet-in-the-middle로 처리한다
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,C, dat[31],ret;
vector<ll> v1,v2;

void go(int here, int limit, vector<ll> &v, ll sum)
{
    if (sum > C) return; // 무게 초과하면 가지치기
    if (here > limit)
    { // 지정 구간 넘어가면 반환.
        v.emplace_back(sum);
        return;
    }
    go(here + 1, limit, v, sum + dat[here]); // 현재 물건을 가방에 넣기
    go(here + 1, limit, v, sum); // 가방에 안 넣기
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> C;
    for (int i=0; i<N; i++) cin >> dat[i];

    // 구간을 반으로 나눠서 처리 (meet-in-the-middle)
    go(0, N/2 - 1, v1, 0);
    go(N/2, N-1, v2, 0);

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    // v1에서 값이 b일때 v2 의 값 a 중 a+b <= C 인 경우를 찾는다.
    for (int b : v1)
    {
        // v2의 값(a) 중 a+b=<C 를 만족하는 인덱스를 이진탐색(upper_bound)를 통해 찾는다.
        // 인덱스는 탐색 값 보다 큰 인덱스를 반환하기 때문에 - 시작위치 인덱스를 해주면 갯수가 바로 나온다.
        if (C-b >= 0) ret += upper_bound(v2.begin(), v2.end(), C-b) - v2.begin();
    }
    cout << ret << "\n";
    return 0;
}
