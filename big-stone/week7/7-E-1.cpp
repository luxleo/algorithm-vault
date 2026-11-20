//
// Created by 5600G on 2026-11-20.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 31;

ll n, dp[MAXN][MAXN], a[MAXN];

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

ll go(int whole, int part)
{
    if (whole == 0 && part == 0) return 1;

    ll &ret = dp[whole][part];
    if (ret) return ret;

    if (whole > 0) ret += go(whole - 1, part + 1);
    if (part > 0) ret += go(whole, part - 1);

    return ret;
}

int main()
{
    fastIO();
    while (true)
    {
        cin >> n;
        if (n == 0) break;
        cout << go(n,0) << '\n';
    }

    return 0;
}
