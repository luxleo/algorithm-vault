//
// Created by 이동한 on 2025. 4. 10..
//
/** 단순 구현 문제임. S5
문제
피카츄는 "pi", "ka", "chu"를 발음할 수 있다.
따라서, 피카츄는 이 세 음절을 합친 단어만
발음할 수 있다. 예를 들면, "pikapi"와 "pikachu"가 있다.

문자열 S가 주어졌을 때, 피카츄가 발음할 수 있는
문자열인지 아닌지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 문자열 S가 주어진다. 문자열은 알파벳
소문자로 이루어진 문자열이며, 길이는 5000을 넘지 않는다.

출력
문자열 S가 "pi", "ka", "chu"를 이어 붙여서
만들 수 있으면 "YES"를 아니면 "NO"를 출력한다.

예제 입력 1
pikapi
예제 출력 1
YES
예제 입력 2
pipikachu
예제 출력 2
YES
예제 입력 3
pikaqiu
예제 출력 3
NO
 * @see https://www.acmicpc.net/problem/14405
 */
#include <bits/stdc++.h>
using namespace std;

string s;
int sSize;
string pi="pi", ka="ka", chu="chu";
int idx;
bool go() {
    if (s[idx] == 'p') {
        if (idx + 1 < sSize && s[idx+1] == 'i') {
            idx+=2;
            return true;
        }
    } else if (s[idx] == 'k') {
        if (idx + 1 < sSize && s[idx+1] == 'a') {
            idx+=2;
            return true;
        }
    } else if (s[idx] == 'c') {
        if (idx + 2 < sSize && s[idx+1] == 'h' && s[idx+2] == 'u') {
            idx+=3;
            return true;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    sSize = s.length();
    while (idx < s.size()) {
        if (!go()) {
            cout << "NO" << "\n";
            return 0;
        }
    }
    if (idx != s.size()) cout << "NO" << "\n";
    cout << "YES" << "\n";
    return 0;
}
