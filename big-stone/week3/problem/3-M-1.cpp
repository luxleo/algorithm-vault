//
// Created by 5600G on 2026-11-11.
//
#include <bits/stdc++.h>
using namespace std;

int K, vst[11];
string mx = "", mn = "";
char a[10];

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

bool check(char x, char y, char op)
{
    if (op == '<') return x < y;
    if (op == '>') return x > y;
    return false;
}

// 누적 문자열 합을 concat 해야한다
void dfs(int here, vector<char> &v)
{
    if (here == K)
    {
        string s = "";
        for (int i = 0; i < v.size(); i++)
            s = s + v[i];
        if (mx == "" || s > mx) mx = s;
        if (mn == "" || s < mn) mn = s;
        return;
    }

    for (int i = 0; i < 10; i++)
    {
        if (vst[i]) continue;
        char next_val = i + '0';
        if (check(v.back(), next_val, a[here]))
        {
            vst[i] = 1;
            v.push_back(next_val);
            dfs(here + 1, v);
            v.pop_back();
            vst[i] = 0;
        }
    }
}

int main()
{
    fastIO();
    cin >> K;

    for (int i = 0; i < K; i++)
        cin >> a[i];

    vector<char> v;

    for (int i = 0; i < 10; i++)
    {
        vst[i] = 1;
        v.emplace_back(i + '0');
        dfs(0, v);
        v.pop_back();
        vst[i] = 0;
    }

    cout << mx << '\n' << mn << '\n';

    return 0;
}
