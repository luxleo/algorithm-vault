//
// Created by 5600G on 2026-07-08.
//
#include <bits/stdc++.h>
using namespace std;

int a[1001], n,c;
map<int, int> mp_freq, mp_idx;
vector<pair<int, int >> v;

bool cmp(pair<int, int> a, pair<int, int> b) // pair<나온 빈도수, 숫자>
{
    if (a.first == b.first) return mp_idx[a.second] < mp_idx[b.second]; // 최초 나온 순서 더 큰게 크도록
    return a.first > b.first; // 나온 빈도수 큰게 더 작도록
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> c;
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
        mp_freq[a[i]]++;
        if (mp_freq[a[i]] == 1) mp_idx[a[i]] = i;
    }

    for (auto it: mp_freq)
    {
        v.emplace_back(it.second, it.first);
    }
    sort(v.begin(), v.end(), cmp);
    for (auto it: v)
    {
        for (int i = 0; i< it.first; i++)
        {
            cout << it.second << ' ';
        }
    }
    return 0;
}
