//
// Created by 이동한 on 2026. 2. 8..
//
/** @see https://www.acmicpc.net/problem/17297
 * 피보나치 형식으로 갱신되는 dp는 dp를 이용하여
 * 전체 문자열을 이전 dp문자열로 연속해서 잘라냄으로써 간소화 할 수 있다.
 */
#include <bits/stdc++.h>
using namespace std;
const int max_fib = 39;
int M, dp[max_fib + 1] = {0, 5, 13}; // 0,1,2 길이 초기화 dp[idx] == index에 해당하는 피보나치 문자열 (공백이 있으므로 1씩 더해진다.)

string s = "Messi Gimossi";

int main() {
    cin >> M;
    M--; // M의 인덱스를 정해준다.
    for (int i = 3; i <= max_fib; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + 1; // 문자열 이을 때 공백으로 이어주므로 1더한다.
    }
    for (int i = max_fib; i >= 2; i--) {
        // M번째가 찾으려는 문자열 길이보다는 커서 잘라낼 수 있으면 잘라낸다.
        if (M >= dp[i]) M -= (dp[i] + 1); // 이어 붙일때 앞에 공백이 있으므로 left_trim을 위해 1을 더 빼준다.
    }
    if (M == 5 || M == -1) cout << "Messi Messi Gimossi" << "\n";
    else cout << s[M] << "\n";
    return 0;
}
