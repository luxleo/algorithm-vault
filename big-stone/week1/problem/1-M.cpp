//
// Created by 이동한 on 2025. 1. 14..
//
/**
 * 짝짓기나 폭발!! 일때는 스택을 떠올리자.
 * @see https://www.acmicpc.net/problem/3986
 *
문제
평석이는 단어 위로 아치형 곡선을 그어 같은 글자끼리(A는 A끼리, B는 B끼리) 쌍을 짓기로 하였다.
만약 선끼리 교차하지 않으면서 각 글자를 정확히 한 개의 다른
위치에 있는 같은 글자와 짝 지을수 있다면, 그 단어는 '좋은 단어'이다. 평석이가 '좋은 단어' 개수를 세는 것을 도와주자.

입력
첫째 줄에 단어의 수 N이 주어진다. (1 ≤ N ≤ 100)
다음 N개 줄에는 A와 B로만 이루어진 단어가 한 줄에 하나씩 주어진다.
단어의 길이는 2와 100,000사이이며, 모든 단어 길이의 합은 1,000,000을 넘지 않는다.

출력
첫째 줄에 좋은 단어의 수를 출력한다.

예제 입력 1     예제 출력 1
3             2
ABAB
AABB
ABBA
 */
#include <bits/stdc++.h>
using namespace std;

int n,ret;
string s;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    ret = 0;
    while (n--) {
        cin >> s;
        stack<char> st;
        for (char c : s) {
            if (!st.empty() && st.top() == c) st.pop(); // (1) 짝 지어지는 경우
            else st.push(c);
        }
        if (st.empty()) ret += 1; // 모두 짝지어진 경우
    }
    cout << ret << "\n";
    return 0;
}
