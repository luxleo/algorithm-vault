//
// Created by 5600G on 2026-11-16.
//
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1001;

int N, lis[MAXN],temp,len;

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main()
{
    fastIO();
    cin >> N;
    for (int i=0; i<N; i++)
    {
        cin >> temp;
        // 탐색 범위는 [lis, lis+len) 이다
        auto pos =lower_bound(lis,lis+len, temp);
        if (*pos == 0) len++;
        *pos = temp;
    }

    cout << len << '\n';
    return 0;
}
