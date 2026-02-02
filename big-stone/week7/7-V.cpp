//
// Created by 5600G on 2026-02-02.
//
/** @see https://www.acmicpc.net/problem/14863
 * 전형적인 냅색 문제
 * 최대값을 찾을때 최소로 두고 갱신, 최소를 찾을때 최대로 두고 갱신
 * 상태 그래프 확장 ( 역순으로 갱신도 가능)
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k, dp[101][100001];
struct B
{
    int _time, cost;
};
B a[101], b[101];

ll go(int here, int _time)
{
    if (here == n) return 0; // 모든 구간을 순회한 경우로 종료한다.
    ll &ret = dp[here][_time];
    if (ret) return ret;
    ret = -1e9; // 최대값 구할 떄 초기화는 최솟값으로
    // 상태 그래프 확장하기 (걸어가거나, 자전거로 가거나)
    if (_time - a[here]._time >=0) ret = max(ret, go(here + 1, _time - a[here]._time) + a[here].cost);
    if (_time - b[here]._time >=0) ret = max(ret, go(here+1, _time - b[here]._time) + b[here].cost);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i]._time >> a[i].cost >> b[i]._time >> b[i].cost;
    cout << go(0, k) << "\n"; // 역순으로 갱신한다.
    return 0;
}
