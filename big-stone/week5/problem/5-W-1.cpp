//
// Created by 5600G on 2026-11-18.
//
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+1;
const int INF = 1e9;
int n,a[MAXN],sum,ret = -INF;
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
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
        sum += a[i];
        ret = max(ret, sum);
        if (sum < 0)
            sum = 0;
    }
    cout << ret << '\n';
    return 0;
}
