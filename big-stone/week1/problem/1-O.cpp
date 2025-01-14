//
// Created by 이동한 on 2025. 1. 14..
//
#include <bits/stdc++.h>
using namespace std;
int n;

/**
 * @see https://www.acmicpc.net/problem/4375
문제
2와 5로 나누어 떨어지지 않는 정수 n(1 ≤ n ≤ 10000)가 주어졌을 때, 각 자릿수가 모두 1로만 이루어진 n의 배수를 찾는 프로그램을 작성하시오.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있고, n이 주어진다.

출력
각 자릿수가 모두 1로만 이루어진 n의 배수 중 가장 작은 수의 자리수를 출력한다.

예제 입력 1     예제 출력 1
3             3
7             6
9901          12
 */
int main() {
    while (scanf("%d", &n) != EOF) { // (1) 무한히 입력이 주어질때 받는 방법.
        int cnt =1, ret = 1;
        while (true) {
            if (cnt % n == 0) {
                cout << ret << "\n";
                break;
            }
            cnt = ( cnt * 10 + 1) % n; // 모듈료 연산 특징
            ret++;
        }
    }
    return 0;
}
