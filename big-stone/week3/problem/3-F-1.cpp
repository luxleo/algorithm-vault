//
// Created by 5600G on 2026-11-10.
//
#include <bits/stdc++.h>
using namespace std;

const int MIN = -1e9;
int n, ret = MIN;
string s;
vector<int> num;
vector<char> oper_ch;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int oper(char oper, int a, int b)
{
    if (oper == '+') return a + b;
    else if (oper == '-') return a - b;
    else return a * b;
}

void dfs(int here, int acc)
{
    if (here == num.size() - 1)
    {
        ret = max(ret, acc);
        return;
    }

    // 괄호없이 다음 수와 연산하는 경우
    dfs(here + 1, oper(oper_ch[here], acc, num[here + 1]));

    // 괄호를 다음 숫자와 다음 다음 숫자와 묶은 경우 (중첩 괄호를 피하기 위해서)
    if (here + 2 < num.size())
    {
        int temp = oper(oper_ch[here + 1], num[here+1], num[here+2]);
        acc = oper(oper_ch[here], acc, temp);
        dfs(here + 2, acc);
    }
}

int main()
{
    fastIO();
    cin >> n;
    cin >> s;
    for (int i=0; i<n; i++)
    {
        if (i%2 == 0) num.emplace_back(s[i] - '0');
        else oper_ch.emplace_back(s[i]);
    }

    dfs(0, num[0]);

    cout << ret << '\n';

    return 0;
}
