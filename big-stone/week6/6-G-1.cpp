//
// Created by 5600G on 2026-11-16.
//
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll X,Y,ret = -1,mid;

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main()
{
    fastIO();
    cin >> X >> Y;

    ll Z = (100 * Y) / X;
    ll lo = 0, hi = 1e9;

    while (lo <= hi)
    {
        mid = (lo + hi) >> 1;
        if ( (Y + mid) * 100 / (X + mid) > Z )
        {
            hi = mid - 1;
            ret = mid;
        } else
        {
            lo = mid + 1;
        }
    }

    cout << ret << '\n';

    return 0;
}
