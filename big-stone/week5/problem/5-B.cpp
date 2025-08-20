//
// Created by 이동한 on 2025. 8. 19..
//
/**
 * G4
 * [9935](https://www.acmicpc.net/problem/9935)
 * 해법은 두가지로 제시 하였다.
 *
 * 첫번째는 string을 의 끝 부분을 폭파열 문자열 길이 만큼 잘라서
 * 폭파열 문자와 비교하여 같은 경우 제거하는 방법이다.
 *
 * 두번째는 스택을 이용하여 뒤집어 꺼내어 비교하는 방법이다.
 *
 * 의외였던 것은 두번째 방법이 첫번째에 비하여 2배 가량 빠르다는 것이다.
 */
#include <bits/stdc++.h>
using namespace std;
string dat, T, ret;

void using_erase();

void using_stack();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> dat >> T;

    // using_erase();
    using_stack();
}

void using_erase() {
    for (char a: dat) {
        ret += a;
        if (ret.size() >= T.size() &&
            ret.substr(ret.size() - T.size(), T.size()) == T
        ) {
            ret.erase(ret.size() - T.size(), T.size());
        }
    }
    if (ret.empty()) {
        cout << "FRULA" << endl;
        return;
    }
    cout << ret << '\n';
}

void using_stack() {
    stack<char> st;
    for (char a: dat) {
        st.push(a);
        if (st.size() >= T.size() &&
            st.top() == T[T.size() - 1]
        ) {
            string temp = "";
            for (int i = 0; i < T.size(); i++) {
                temp += st.top();
                st.pop();
            }
            reverse(temp.begin(), temp.end());
            if (temp != T) {
                // 다시 넣어주자.
                for (char cc: temp) {
                    st.push(cc);
                }
            }
        }
    }

    if (st.empty()) {
        cout << "FRULA" << endl;
        return;
    }
    string ans = "";
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}
