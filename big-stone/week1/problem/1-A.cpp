//
// Created by 이동한 on 2025. 1. 8..
//
#include <bits/stdc++.h>
using namespace std;
/**
 * 문제 링크
 * @see https://www.acmicpc.net/problem/2309
 */
int main() {
    int data[9];
    int sum = 0;
    for (int & i : data) {
        cin >> i;
        sum += i;
    }

    sort(data,data+9);
    int target = sum - 100;
    pair<int, int> answerIdx;

    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (data[i] + data[j] == target) {
                answerIdx = make_pair(i, j);
                break;
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        if (i != answerIdx.first && i != answerIdx.second) {
            cout << data[i] << "\n";
        }
    }
}
