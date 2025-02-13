//
// Created by 이동한 on 2025. 2. 10..
//
#include <bits/stdc++.h>
using namespace std;

/**
 *
 * @see https://www.acmicpc.net/problem/16637
 */
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}
int n,ret = -987654321; // (0) 최대를 구할때 초기화는 '최소로' 해야한다.
vector<int> dat;
vector<char> operators;
string s;

int operate(char operand, int a, int b) {
    if (operand == '+') return a+b;
    else if (operand == '-') return a-b;
    else return a*b;
}

/** 이 함수 작성하는게 어렵다.
 * 누적수와 다음수 (idx+1)과 괄호처리 하거나, 다음수(idx+1)와 다다음수(idx+2)를 괄호처리하고 누적수와 처리한다.
 * @param idx 현재 참조하고 있는 숫자, 그리고 연산자의 인덱스
 * @param acc 현재 참조하고 있는 숫자까지의 누적합
 */
void solve(int idx, int acc) {
    if (idx == dat.size() - 1) {
        ret = max(ret, acc);
        return;
    }
    // 현재수와 다음수를 괄호처리
    solve(idx+1, operate(operators[idx],acc,dat[idx+1]));

    // 다음수와 다다음수를 괄호처리
    if (idx+2 <= dat.size()-1) {
        int temp = operate(operators[idx+1],dat[idx+1],dat[idx+2]);
        solve(idx+2, operate(operators[idx],acc,temp));
    }
}
int main() {
    fastIO();
    cin >> n;
    cin >> s;
    for (int i =0; i<n; i++) {
        if (i % 2) operators.push_back(s[i]);
        else dat.push_back(s[i] - '0'); // char to num 중요하다.
    }
    solve(0, dat[0]);
    cout << ret << "\n";
    return 0;
}
