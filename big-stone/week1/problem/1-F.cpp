//
// Created by 이동한 on 2025. 1. 9..
//
#include <bits/stdc++.h>
using namespace std;

int cnt[101],length;
string str,answer;

/**
 * 1. 대문자 A 아스키 코드 = 65, 소문자 a = 97
 * 2. getline(cin, string) 로 뛰어쓰기가 있는 경우 받는다.
 * 3. string의 경우 배열처럼 바로 수정이 가능하다.
 * @see https://www.acmicpc.net/problem/11655
 */
int main() {
    getline(cin,str); // (1)
    for (int i = 0; i< str.length(); i++) {
        char cur = str[i];
        if (cur >= 65 && cur < 91) {
            if (cur + 13 >= 91) str[i] -=13;
            else str[i] +=13;
        } else if (cur >=97 && cur < 123) {
            if (cur + 13 > 122 ) str[i] -= 13;
            else str[i] +=13;
        }
    }
    cout << str << endl;
    return 0;
}
