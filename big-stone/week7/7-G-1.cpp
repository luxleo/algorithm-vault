//
// Created by 5600G on 2026-11-20.
//
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 10001;
int n,k,a[MAXN],temp;

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main()
{
    fastIO();
    cin >> n >> k;
    fill(a, a+MAXN, INF);
    a[0] = 0;

    for (int i=0; i<n; i++)
    {
        cin >> temp;
        for (int j=temp; j<=k; j++)
            a[j] = min(a[j], a[j-temp] + 1);
    }

    if (a[k] == INF)
        cout << -1 << '\n';
    else
        cout << a[k] << '\n';
    return 0;
}
