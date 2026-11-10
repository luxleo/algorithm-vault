//
// Created by 5600G on 2026-08-03.
//
#include <bits/stdc++.h>
using namespace std;

int n;
string ret, s;
vector<string> v;

void proc()
{
    while (true)
    {
        if (ret.size() && ret.front() == '0') ret.erase(ret.begin());
        else break;
    }
    if (ret.size() == 0) v.push_back("0");
    ret = "";
}

bool cmp(string a, string b)
{
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> s;
        ret = "";
        for (int j=0; j<s.size(); j++)
        {
            if (s[j] < 65) ret += s[j];
            else if (ret.size()) proc();
        }
        if (ret.size()) proc();
    }
    sort(v.begin(), v.end(), cmp);
    for (string el: v) cout << el << "\n";
    return 0;
}
