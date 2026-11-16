//
// Created by 5600G on 2026-11-16.
//
#include <bits/stdc++.h>
using namespace std;

// 최악의 경우: N = 20억, M = 1, 운행 시간 = 30분 -> 최대 600억 분 필요
#define max_n 60000000004
#define MAX_M 10004
using namespace std;

typedef long long ll; // 시간과 인원수가 최대 600억까지 커지므로 long long 필수

ll n, m;            // n: 아이들의 수(N), m: 놀이기구의 종류 수(M)
ll a[MAX_M];        // 각 놀이기구의 운행 시간(분)을 저장하는 배열
ll lo, hi = max_n;  // 이분 탐색 범위 (0분 ~ 600억 분)
ll ret, mid, temp;  // ret: N번째 아이가 탑승하는 정확한 시각, temp: 누적 탑승 인원수

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool check(ll mid)
{
    temp = m;

    for (ll i = 0; i<m; i++)
        temp += (mid) / a[i];

    return temp >= n;
}

int main()
{
    fastIO();
    cin >> n >> m;

    for (ll i = 0; i<m; i++)
        cin >> a[i];

    while (lo <= hi)
    {
        ll mid = (lo + hi) >> 1;
        if (check(mid))
        {
            ret = mid;
            hi = mid - 1;
        } else lo = mid + 1;
    }

    temp = m;
    for (ll i =0; i<m; i++)
        temp += (ret - 1) / a[i];

    for (ll i = 0; i<m; i++)
    {
        if (ret % a[i] == 0) temp++;
        if (temp == n)
        {
            cout << i + 1 << '\n';
            break;
        }
    }

    return 0;
}
