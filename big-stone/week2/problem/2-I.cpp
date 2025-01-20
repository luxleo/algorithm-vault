//
// Created by 이동한 on 2025. 1. 20..
//
#include <bits/stdc++.h>
using namespace std;

/** 숫자가 100 자리라는 것에서 long long 또는 int로는 접근할 수 없음을 알아야한다.
 *
*글자가 N줄있다. 상근이는 여기서 숫자를 모두 찾은 뒤, 이 숫자를 비내림차순으로 정리해야한다.
*숫자의 앞에 0이 있는 경우에는 정리하면서 생략할 수 있다.
글자를 살펴보다가 숫자가 나오는 경우에는, 가능한 가장 큰 숫자를 찾아야 한다.
즉, 모든 숫자의 앞과 뒤에 문자가 있거나, 줄의 시작 또는 끝이어야 한다.
예를 들어, 01a2b3456cde478에서 숫자를 찾으면 1, 2, 3456, 478이다.
선생님이 준 종이의 내용이 주어졌을 때, 상근이의 숙제를 대신하는 프로그램을 작성하시오.

입력
첫째 줄에 종이의 줄의 개수 N이 주어진다. (1 ≤ N ≤ 100)
다음 N개의 줄에는 각 줄의 내용이 주어진다. 각 줄은 최대 100글자이고,
항상 알파벳 소문자와 숫자로만 이루어져 있다.

출력
종이에서 찾은 숫자의 개수를 M이라고 하면, 출력은 M줄로 이루어져야 한다. 각 줄에는 종이에서 찾은 숫자를 하나씩 출력해야 한다. 이때, 비내림차순으로 출력해야 한다. 비내림차순은 내림차순의 반대인 경우인데, 다음 수가 앞의 수보다 크거나 같은 경우를 말한다.

예제 입력 1     예제 출력 1
2             1
lo3za4        3
01            4
 * @see https://www.acmicpc.net/problem/2870
 */
int n;
string s,ret;
vector<string> v;
void work() {
    while (true) {
        if (ret.size() && ret.front() == '0') ret.erase(ret.begin());
        else break;
    }
    if (ret.empty()) v.push_back("0");
    else v.push_back(ret);
    ret = ""; // 초기화 해주지 않으면 안된다. 루프는 한번 초기화 한후에 s를 비우지 못하므로
}
bool cmp(string a, string b) {
    if (a.size() == b.size()) return a < b; // size가 같으면 ascii 로 변환하여 한자리씩 자동으로 비교해준다.
    return a.size() < b.size();
}
int main() {
    cin >> n;
    for (int i =0; i< n; i++) {
        cin >> s;
        ret = "";
        for (int j = 0; j<s.size(); j++) {
            if (s[j] < 65) ret += s[j];
            else if (ret.size()) work();
        }
        if (ret.size()) work(); // 빠져 나와서 남은 버퍼 비워주기
    }
    sort(v.begin(), v.end(),cmp);
    for (string el : v) cout << el << "\n";
    return 0;
}