//
// Created by 이동한 on 2025. 1. 9..
//
/**
 * 재귀 함수의 조건
 * 1. 기저사례 확인
 * 2. 큰 문제를 작은 문제로 분할 하여 해결할때 사용한다.
 * 3. 반복문으로 해결가능하다면 반복문으로 하는게 적합하다.
 */
#include <bits/stdc++.h>
using namespace std;

int fibo(int n) {
    if (n == 0 || n == 1 || n == 2) {
        return 1;
    }
    return fibo(n - 1) + fibo(n - 2);
}

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}
int main() {
    cout << "fibo number: " << " ";
    int fiboNumber;
    cin >> fiboNumber;

    cout << "fibo of " << fiboNumber << "=" << fibo(fiboNumber) << endl;
    return 0;
}
