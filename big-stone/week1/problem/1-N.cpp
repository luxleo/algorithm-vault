//
// Created by 이동한 on 2025. 1. 14..
//
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a,b,c,ret;

ll mul(ll x, ll t) {
    if (t == 1) return x %c;
    ll temp = mul(x, t >> 1) % c;
    if (t & 1) return (temp * temp)%c * a % c;
    return (temp * temp) %c;
}

/**
 * mod 연산은 덧셈과 곱셈에 대하여 분배법칙이 성립한다.
 * @see https://www.acmicpc.net/problem/1629

문제
자연수 A를 B번 곱한 수를 알고 싶다. 단 구하려는 수가 매우 커질 수 있으므로 이를 C로 나눈 나머지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 A, B, C가 빈 칸을 사이에 두고 순서대로 주어진다. A, B, C는 모두 2,147,483,647 이하의 자연수이다.

출력
첫째 줄에 A를 B번 곱한 수를 C로 나눈 나머지를 출력한다.

예제 입력 1     예제 출력 1
10 11 12      4
 */
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b >> c;
    cout << mul(a, b) % c << "\n";
    return 0;
}
