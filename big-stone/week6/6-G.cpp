//
// Created by 이동한 on 2025. 10. 1..
//
/** S3 @see https://www.acmicpc.net/problem/1072
 * 정수 단위 승률을 높이기 위한 최소 게임의 상한선 hi를 정하는 것이 관건이었다.
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x, y, ret = -1, mid;

int main() {
    cin >> x >> y;
    ll z = y * 100 / x;
    ll lo = 0, hi = 1e9;
    while (lo <= hi) {
        mid = (lo + hi) >> 1;
        if ((y + mid) * 100 / (x + mid) > z) {
            hi = mid - 1;
            ret = mid;
        } else lo = mid + 1;
    }
    cout << ret << endl;
    return 0;
}
