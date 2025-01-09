//
// Created by 이동한 on 2025. 1. 9..
//
#include <bits/stdc++.h>
using namespace std;

/**
 * 키포인트는 문자 -> 숫자, 숫자 -> 문자이다.
 * @see https://www.acmicpc.net/problem/1159
 */
int cnt[26], queryNum;
string buff,answer;
int main() {
    cin >> queryNum;
    for (int i = 0; i < queryNum; i++) {
        cin >> buff;
        cnt[buff[0] - 'a']++; // (1) 문자를 숫자로
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > 4) answer += i + 'a'; // (2) 숫자를 문자로
    }
    if (answer.size())cout << answer << endl;
    else cout << "PREDAJA" << endl;
    return 0;
}
