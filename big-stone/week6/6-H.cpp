//
// Created by 이동한 on 2025. 10. 1..
//
/** S4 @see https://www.acmicpc.net/problem/2776
 * cout << << "\n" 무조건 이거로 해야한다. endl 으로 하면 타임에러 난다.
 */
#include <bits/stdc++.h>
using namespace std;
const int MAX_LEN = 1000001;
int t, n, m, f[MAX_LEN], temp;

int go(int target) {
    int lo = 0, hi = n - 1;
    int mid;
    while (lo <= hi) {
        mid = (lo + hi) >> 1;
        if (f[mid] > target) {
            hi = mid - 1;
        } else if (f[mid] == target) return 1;
        else lo = mid + 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> f[i];
        }
        sort(f, f + n);
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> temp;
            cout << go(temp) << "\n";
        }
    }
    return 0;
}
