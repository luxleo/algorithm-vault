//
// Created by 5600G on 2026-11-17.
//
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7 + 1;
int n, a[MAXN],x, lo ,hi,ret;

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main()
{
    fastIO();
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> x;

    sort(a, a+n);
    lo = 0, hi = n-1;

    while (lo<hi)
    {
        int sum = a[lo] + a[hi];
        if (sum == x)
        {
            hi--;
            ret++;
        } else if (sum > x) hi--;
        else lo++;
    }

    cout << ret << '\n';

    return 0;
}