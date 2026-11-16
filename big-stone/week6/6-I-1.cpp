//
// Created by 5600G on 2026-11-16.
//
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll S, C, ret, temp, sum;
vector<ll> v;

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main()
{
    fastIO();
    cin >> S >> C;

    for (int i = 0; i < S; i++)
    {
        cin >> temp;
        v.push_back(temp);
        sum += temp; // [추가] 전체 파 길이의 총합 누적
    }

    ll lo = 1, hi = 1e9; // [수정 1] 최소 길이는 mn이 아닌 1부터 시작
    while (lo <= hi)
    {
        ll cnt = 0; // [수정 3] 최대 10^15까지 커질 수 있으므로 long long 사용
        ll mid = (lo + hi) >> 1;
        for (int i = 0; i < S; i++)
            cnt += (v[i] / mid);

        if (cnt < C)
            hi = mid - 1;
        else
        {
            lo = mid + 1;
            ret = mid;
        }
    }

    // [수정 2] 전체 파 길이에서 실제 파닭 C개에 사용된 파의 양(ret * C)을 차감
    cout << sum - ret * C << '\n';
    return 0;
}