//
// Created by 이동한 on 2025. 1. 13..
//
#include <bits/stdc++.h>
using namespace std;

/**
 * 문제 링크
 * @see: https://www.acmicpc.net/problem/1213
 */
string s,ret;
char mid;
int flag, cnt[26];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> s;
    for (char c : s) cnt[c-'A']++;
    for (int i ='Z'; i>='A'; i--) {
        int idx = i-'A';
        if (cnt[idx]) {
            if (cnt[idx]&1) { // (1) 'num & 1' 연산을 통해서 홀수 판정한다.
                mid = char(i); flag++;
                cnt[idx]--;
            }
            if (flag > 1) {
                cout << "I'm Sorry Hansoo\n";
                return 0;
            }
            for (int j = 0; j<cnt[idx]; j+=2) {
                //(2) 앞, 뒤로 문자열을 붙여준다.
                ret = char(i) + ret;
                ret+= char(i);
            }
        }
    }
    if (mid) ret.insert(ret.begin() + ret.size()/2, mid); // (3) string.insert(pointer, target) 으로 끼워넣기
    cout << ret << '\n';
    return 0;
}
