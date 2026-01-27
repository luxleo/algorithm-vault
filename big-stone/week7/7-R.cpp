//
// Created by 5600G on 2026-01-27.
//
/** @see https://www.acmicpc.net/problem/10942
 * dp는 early return, 점화식으로 계산 비용 줄이기 등에 이용된다.
 *  이번 문제는 점화식 관계에 집중된 문제였다.
 *  dp 가 갱신되는 방식은 각 항의 구간에 따라 달라질 수도 있음을 보인 문제.
 */
#include <bits/stdc++.h>
using namespace std;
const int max_N = 2001;
int n, m, from, to, dp[max_N][max_N], dat[max_N];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++) cin >> dat[i + 1];

    // dp 갱신
    for (int i=1; i<=n; i++) dp[i][i] = 1; // from, to 가 같으면 항상 팰린드롬
    for (int i=1; i<n; i++)
        // from, to 가 하나 차이 날 때 data[from] == data[to] 이면 팰린드롬
        if (dat[i] == dat[i+1]) dp[i][i+1] = 1;

    // 점화식 파트이다. n(i) == if(a[i]==a[j] and dp[i+1][j-1]])
    // 즉 껍질항이 펠린드롬이고 dp 속이 펠린드롬이면 해당항도 팰린드롬
    for (int _size = 2; _size < n; _size++)
        for (int i = 1; i + _size <=n; i++)
            if (dat[i] == dat[i+_size] && dp[i+1][i+ _size - 1])
                dp[i][i+_size] = 1;


    cin >> m;
    while (m--)
    {
        cin >> from >> to;
        cout << dp[from][to] << '\n';
    }

    return 0;
}
