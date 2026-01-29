//
// Created by 5600G on 2026-01-29.
//

/** @see https://www.acmicpc.net/problem/5557
 * dp로 경우의 수 구하는 문제 였다.
 * 경우의 수를 구하는 방식은 그래프의 현재 노드에서 가능한 경우의 수만큼 다음 노드로 확장한다.
 * 메모이제이션을 이용하여 현재 노드를 return 해주면 그 하위의 모든 경우의수가 합산된 채로 return 된다.
 *
 * 경우의 수를 가지치기 할때는 return 0을 해준다.
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; // 2^63-1 을 담을 수 있는 범위는 long long 이다 int 는 2^31-1
ll dp[101][21], N;
int dat[101];

ll go(int here, int acc)
{
    if (acc <0 || acc > 20) return 0; // 고려하지 않는 경우의 수 가지치기
    ll &ret = dp[here][acc];
    if (ret) return ret; // 경우의 수에서 하위 가지들의 값이 합산된 현재 노드를 바로 반환한다.
    if (here == N-2)
    {
        if (acc == dat[N-1]) return 1;
        return 0;
    }
    // 다음노드로 가능한 경우의 수만큼 확장
    ret += go(here + 1, acc + dat[here+1]);
    ret += go(here + 1, acc - dat[here + 1]);
    return ret;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i=0; i<N; i++) cin >> dat[i];
    cout << go(0,dat[0]) << "\n";
    return 0;
}
