//
// Created by 이동한 on 2026. 2. 7..
//
/** @see https://www.acmicpc.net/problem/17623
 * dp의 의미를 정하는게 중요했다.
 * dp의 초기값을 지정할 수 있는 경우 (이 문제의 경우 dp[1], dp[2], dp[3] 이었음 지정해야한다.
 * check로 수로 이루어진 문자열 비교 유의하라.
 * dp 갱신 조건은 여러가지 일 수 있다.
 */
#include <bits/stdc++.h>
using namespace std;
int t, n;
string dp[1001]; // dp[idx] 괄호수 idx에 해당하는 가장 작은 괄호수
map<char, char> mp;
char a[6] = {'(', ')', '{', '}', '[', ']'};

bool check(string left, string right) {
    if (left == "" && right == "") return false;
    if (left == "") return true;
    if (left.size() == right.size()) return right < left;
    return right.size() < left.size();
}

int main() {
    // 맵초기화
    for (int i = 0; i < 6; i++) mp[i + '1'] = a[i];
    dp[1] = "12"; // () 가 가장 작은 괄호수
    dp[2] = "34"; // {}
    dp[3] = "56"; // []
    for (int i = 1; i <= 1000; i++) {
        // nesting 시킬 수 있으면 시킨다.
        if (i % 2 == 0 && check(dp[i], '1' + dp[i / 2] + '2')) dp[i] = '1' + dp[i / 2] + '2'; // (x)가 더 작을 때
        if (i % 3 == 0 && check(dp[i], '3' + dp[i / 3] + '4')) dp[i] = '3' + dp[i / 3] + '4'; // {x}가 더 작을떄
        if (i % 5 == 0 && check(dp[i], '5' + dp[i / 5] + '6')) dp[i] = '5' + dp[i / 5] + '6'; // [x] 가 더 작을때

        // 나란히 열거 시킨다.
        for (int j = 1; j <= i; j++)
            if (check(dp[i], dp[j] + dp[i - j])) dp[i] = dp[j] + dp[i - j];
    }
    cin >> t;
    while (t--) {
        cin >> n;
        for (char c: dp[n]) cout << mp[c];
        cout << "\n";
    }
    return 0;
}
