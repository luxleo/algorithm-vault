//
// Created by 이동한 on 2025. 1. 20..
//
#include <bits/stdc++.h>
using namespace std;

/**
 *
 * @see https://www.acmicpc.net/problem/4659
 */
bool flag,has_vowel;
string s;
int prevChar, lcnt, vcnt;
bool isVowel(int c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

/** 풀이에 필요한 조건들을 상정하고 갱신해 나가는 과정에서 배울게 많았다. + char -> int
*
*회사 FnordCom은 그런 패스워드 생성기를 만들려고 계획중이다.
*당신은 그 회사 품질 관리 부서의 직원으로 생성기를 테스트해보고 생성되는 패스워드의 품질을 평가하여야 한다.
*높은 품질을 가진 비밀번호의 조건은 다음과 같다.
모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
이 규칙은 완벽하지 않다;우리에게 친숙하거나 발음이 쉬운 단어 중에서도 품질이 낮게 평가되는 경우가 많이 있다.

입력
입력은 여러개의 테스트 케이스로 이루어져 있다.

각 테스트 케이스는 한 줄로 이루어져 있으며, 각 줄에 테스트할 패스워드가 주어진다.
마지막 테스트 케이스는 end이며, 패스워드는 한글자 이상 20글자 이하의 문자열이다. 또한 패스워드는 대문자를 포함하지 않는다.

출력
각 테스트 케이스를 '예제 출력'의 형태에 기반하여 품질을 평가하여라.

예제 입력 1     예제 출력 1
a               <a> is acceptable.
tv              <tv> is not acceptable.
ptoui           <ptoui> is not acceptable.
bontres         <bontres> is not acceptable.
zoggax          <zoggax> is not acceptable.
 * @see https://www.acmicpc.net/problem/4659
 */
int main() {
    while (true) {
        cin >> s;
        if (s == "end") break;
        flag = false;
        has_vowel = false;
        prevChar = -1; // char -> int 로 비교(ASCII)
        lcnt = 0;
        vcnt = 0;
        for (int i= 0; i<s.size(); i++) {
            int cur = s[i];
            if (isVowel(cur)) {
                lcnt = 0;
                vcnt++;
                has_vowel = true;
            }else {
                lcnt++;
                vcnt = 0;
            }
            if (vcnt ==3 || lcnt == 3) flag = true;
            if (i > 0 && (prevChar == cur) && (cur != 'e' && cur != 'o')) flag=true;
            prevChar = cur;
        }
        if (!has_vowel) flag = true;
        if (flag) cout << "<" << s << ">" << " is not acceptable.\n"; // (3) 출력 방식이 틀려서 틀려버렸다. 주의하자
        else cout << "<" << s << ">" << " is acceptable.\n";
    }
    return 0;
}
