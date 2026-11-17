//
// Created by 5600G on 2026-11-17.
//
#include <bits/stdc++.h>
using namespace std;

string S;           // 원본 문자열 (길이 최대 1,000,000)
string T;           // 폭발 문자열 (길이 최대 36)
string ret;         // 폭발이 모두 끝난 뒤 남은 문자를 담을 결과 문자열
stack<char> stk;    // 문자를 순서대로 쌓으며 폭발 여부를 검사할 스택

int main() {
    // 입출력 속도 향상 (문자열 길이가 100만이므로 권장)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. 원본 문자열(S)과 폭발 문자열(T) 입력
    cin >> S >> T;

    // 2. 원본 문자열의 문자를 왼쪽부터 하나씩 스택에 삽입
    for(char a : S){
        stk.push(a);

        // [폭발 검사 조건]
        // 스택 크기가 폭발 문자열 이상이고, 방금 넣은 문자가 폭발 문자열의 '끝 글자'와 같다면 검사 시작
        if(stk.size() >= T.size() && stk.top() == T[T.size() - 1]){
            string ss = "";

            // 폭발 문자열의 길이만큼 스택의 위에서 글자를 꺼내 임시 문자열 ss에 저장
            for(char i : T){
                ss += stk.top();
                stk.pop();
            }

            // 스택에서 꺼낸 글자는 역순이므로 원래 순서대로 뒤집음
            reverse(ss.begin(), ss.end());

            // 폭발 문자열(T)과 일치하지 않는다면 폭발이 아니므로 꺼냈던 글자들을 다시 스택에 복구
            // (일치한다면 다시 넣지 않고 그대로 버림으로써 '폭발' 처리 완료)
            if(T != ss){
                for(char i : ss){ // (원본 코드의 int i도 char로 암시적 변환되어 동일하게 동작)
                    stk.push(i);
                }
            }
        }
    }

    // 3. 모든 탐색 종료 후 스택이 비어있다면 모든 문자가 폭발한 것이므로 "FRULA" 출력
    if(stk.size() == 0){
        cout << "FRULA\n";
    }
    // 남은 문자가 있다면 스택에서 모두 꺼낸 뒤 순서를 뒤집어 출력
    else {
        while(stk.size()){
            ret += stk.top();
            stk.pop();
        }
        reverse(ret.begin(), ret.end());
        cout << ret << "\n";
    }
    return 0;
}