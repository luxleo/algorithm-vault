//
// Created by 5600G on 2026-11-13.
//
#include <bits/stdc++.h>
using namespace std;

string a,b;

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

string string_add(string x, string y)
{
    int carry = 0; // 현재 자릿수의 덧셈 결과 및 다음 자리로 넘길 올림수(Carry)를 저장하는 변수
    string ret = ""; // 계산 결과를 일의 자리부터 거꾸로 쌓아둘 문자열

    while (x.size() || y.size() || carry)
    {
        if (!x.empty())
        {
            carry += x.back() - '0';
            x.pop_back();
        }
        if (!y.empty())
        {
            carry += y.back() - '0';
            y.pop_back();
        }
        // 현재 자릿수에 남을 숫자(sum % 10)를 다시 문자('0'~'9')로 바꿔 결과 문자열 뒤에 추가
        ret += (carry % 10) + '0';
        // 10 이상이 되어 다음 높은 자릿수로 올라갈 올림수(0 또는 1)만 남김
        carry /= 10;
    }
    // 일의 자리부터 거꾸로 이어 붙였으므로, 문자열 전체를 뒤집어 원래 순서로 복원
    reverse(ret.begin(), ret.end());
    return ret;
}

int main()
{
    fastIO();

    cin >> a >> b;
    cout << string_add(a,b) << '\n';
    return 0;
}
