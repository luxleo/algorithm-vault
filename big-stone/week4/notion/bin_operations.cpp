//
// Created by 이동한 on 2025. 2. 24..
//
#include <iostream>
using namespace std;

void ops_and_or() {
    int a=9; // 1001(2)
    int b=8; // 1000(2)
    cout << (a&b) << "\n"; // 1000(2) == 8
    cout << (a|b) << "\n"; // 1001(2) == 9
}
int main() {
    ops_and_or();
    return 0;
}
