//
// Created by 이동한 on 2025. 1. 9..
//
#include <bits/stdc++.h>
using namespace std;

/**
 * reverse() 함수를 이용하기 좋았다.
 * @see https://www.acmicpc.net/problem/10988
 */
string str;

int teacher_code() {
    string str,temp;
    cin >> str;
    temp = str;
    reverse(temp.begin(), temp.end());
    if (temp == str) cout << 0 << endl;
    else cout << 1 << endl;
    return 0;
}
int main() {
    cin >> str;
    int start =0;
    int end=str.size()-1;
    while (start < end) {
        if (str[start++] != str[end--]) {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
    return 0;
}