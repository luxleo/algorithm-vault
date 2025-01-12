//
// Created by 이동한 on 2025. 1. 12..
//
/**
 * string.find(target)
 * string.substr(closedStart,opendEnd)
 * string.substr(closedStart) -> end 생략시 문자열 끝까지.
 * @see https://www.acmicpc.net/problem/9996
 */
#include <bits/stdc++.h>
using namespace std;
int N;
string pattern,prefix,suffix,s;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    cin >> pattern;
    int pos = pattern.find('*');
    prefix = pattern.substr(0,pos);
    suffix = pattern.substr(pos+1);

    for (int i = 1; i <= N; i++) {
        cin >> s;
        // 반례 검증 로직. 이것을 생각할 수 있어야한다.
        if (s.size() < prefix.size() + suffix.size()) cout << "NE\n";
        else {
            if (s.substr(0,prefix.size()) == prefix
                && s.substr(s.size()-suffix.size()) == suffix) // substr을 끝에서 부터 적용하는 방법.
                cout << "DA\n";
            else cout << "NE\n";
        }
    }
    return 0;
}
