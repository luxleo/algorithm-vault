//
// Created by 이동한 on 2025. 10. 6..
//

/** S2 @see https://www.acmicpc.net/problem/14627
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s, c, a[1000000], mid, ret, sum;

bool check(int target) {
    int cnt = 0;
    for (int i = 0; i < s; i++) {
        cnt += a[i] / target;
        if (cnt >= c) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s >> c;
    for (int i = 0; i < s; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + s);
    ll lo = 1, hi = a[s - 1];
    while (lo <= hi) {
        mid = (lo + hi) >> 1;
        if (check(mid)) {
            lo = mid + 1;
            ret = mid;
        } else hi = mid - 1;
    }
    cout << sum - ret * c << "\n";
    return 0;
}
