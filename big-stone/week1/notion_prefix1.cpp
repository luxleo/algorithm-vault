//
// Created by 이동한 on 2025. 1. 8..
//
#include <bits/stdc++.h>
using namespace std;

int numbers[100], rangeStart, rangeEnd, prefixSum[100], dataSize ,queryNumber;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> dataSize >> queryNumber;

    // i-1 부터 조회 하므로 0이 아닌 1 부터 시작해준다 (한칸씩 밀려서 써준다.)
    for(int i = 1; i <= dataSize; i++) {
        cin >> numbers[i];
        prefixSum[i] = prefixSum[i - 1] + numbers[i];
    }
    for (int i=0; i < queryNumber; i++) {
        cin >> rangeStart >> rangeEnd;
        cout << prefixSum[rangeEnd] - prefixSum[rangeStart - 1] << "\n";
    }
    return 0;
}
