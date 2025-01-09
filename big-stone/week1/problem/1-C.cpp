#include <bits/stdc++.h>
using namespace std;
int timeSpan[101];
int A, B, C, ans=0;
int calcCost(int carNumber) {
    if (carNumber == 1) return A;
    if (carNumber == 2) return B * 2;
    if (carNumber == 3) return C * 3;
    return 0;
}

/**
 * @see https://www.acmicpc.net/problem/2979
 * 후기 : 시간 이상 이하를 구하는 문제 였는데 어려운 문제는 아니었으나 흥믹마 있었다.
 */
int main() {
    cin >> A >> B >> C;
    for (int i=0; i<3; i++) {
        int startTime, endTime;
        cin >> startTime >> endTime;
        for (int j=startTime; j<endTime; j++) timeSpan[j]++;
    }
    for (int carNumber : timeSpan) ans += calcCost(carNumber);
    cout << ans << endl;
    return 0;
}