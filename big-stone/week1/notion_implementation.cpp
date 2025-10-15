//
// Created by 5600G on 2025-10-14.
//
/** 구현은 특정한 분야에서 몇가지 테크닉을 요구한다.
 * 문자열: 뒤집기(부분뒤집기), 부분배열(substr), 덧붙이기 (str1 + str2)
 * 숫자: 배열정렬 (with sort)
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // 문자열
    // 뒤집기(부분 뒤집기)
    string word = "hello";
    // 부분배열 출력
    cout << word.substr(0,3) << endl;
    const double target = 1.2345;
    cout << fixed << setprecision(3) << target << endl;
    return 0;
}
