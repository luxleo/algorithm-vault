//
// Created by 5600G on 2026-11-13.
//
#include <bits/stdc++.h>
using namespace std;

int N;
string s;

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void sol1()
{
    cin >> N >> s;

    int left=0,right=0;

    int ret = 0;

    // [1단계] 왼쪽 -> 오른쪽 순방향 스캔
    // 닫는 괄호 ')'가 초과해서 끊어지는 경우를 걸러내며 최대 길이를 찾음
    for (int i=0; i<N; i++)
    {
        if (s[i] == '(') left++;
        else if (s[i] == ')') right++;
        // 여는 괄호와 닫는 괄호의 개수가 같아지면 완벽한 올바른 괄호 문자열!
        if (left == right) ret = max(ret, right + left);
        // 닫는 괄호가 더 많아지는 순간, 앞의 문자열은 절대 올바른 괄호가 될 수 없음
        if (left < right)
        {
            left = 0;
            right = 0;
        }
    }

    left = 0;
    right = 0;

    // [2단계] 오른쪽 -> 왼쪽 역방향 스캔
    // 순방향 스캔에서 놓친 "(()" 처럼 여는 괄호 '('가 남아서 못 찾은 구간을 보완
    for (int i=N-1; i>=0; i--)
    {
        if (s[i] == '(') left++;
        else if (s[i] == ')') right++;

        if (left == right) ret = max(ret, right + left);
        if (left > right)
        {
            left = 0;
            right = 0;
        }
    }

    cout << ret << '\n';
}

void sol2()
{
    const int MAX_N = 200001;
    int memo[MAX_N] = {}; // 각 위치의 괄호가 올바른 짝을 찾았는지 기록하는 배열 (1: 유효함, 0: 짝 없음)
    int ret = 0;
    stack<int> st;

    cin >> N >> s;

    for (int i=0; i<N; i++)
    {
        if (s[i] == '(') st.emplace(i);
        if (s[i] == ')')
        {
            if (!st.empty())
            {
                // 현재 닫는 괄호 위치(i)와 짝이 되는 여는 괄호 위치(stk.top()) 둘 다 유효함(1)으로 표시
                memo[st.top()] = memo[i] = 1;
                st.pop();
            }
        }
    }

    int cnt = 0;
    for (int i=0; i<N; i++)
    {
        if (memo[i] != 0)
        {
            cnt++;
            ret = max(ret, cnt);
        } else cnt = 0;
    }

    cout << ret << '\n';
}

int main()
{
    fastIO();
    // sol1();
    sol2();
    return 0;
}
