//
// Created by 5600G on 2026-11-16.
//
#include <bits/stdc++.h>
using namespace std;

int T,A,B,temp;
vector<int> v;

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(int target)
{
    int lo = 0, hi = v.size() - 1;
    int ret = 0;
    while (lo<=hi)
    {
        int mid = (lo + hi) >> 1;
        if (v[mid] == temp)
        {
            ret = 1;
            break;
        } else if (v[mid] > target)
        {
            hi = mid - 1;
        } else
        {
            lo = mid + 1;
        }
    }

    cout << ret << '\n';
}

int main()
{
    fastIO();
    cin >> T;

    while (T--)
    {
        v.clear();
        cin >> A;
        for (int i=0; i<A; i++)
        {
            cin >> temp;
            v.push_back(temp);
        }
        sort(v.begin(),v.end());

        cin >> B;
        for (int i=0; i<B; i++)
        {
            cin >> temp;
            solve(temp);
        }
    }
    return 0;
}
