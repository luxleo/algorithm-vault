//
// Created by 이동한 on 2025. 9. 27..
//
/** S3 @see https://www.acmicpc.net/problem/7795
 *  배열에서 x값 미만의 개수가 몇 개고 => upper_bound, lower_bound 생각해야한다.
 *  sort 이용하여 array, vector를 정렬하는 방법을 익힐것
 */
#include <iterator>
#include <bits/stdc++.h>
using namespace std;

int a[20004], b[20004], n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 0;
    cin >> t;
    while (t--) {
        int ret = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        sort(a, a + n);
        sort(b, b + m);
        for (int i = 0; i < n; i++) {
            // lower_bound를 실행하면 작은 원소 + 1 을 반환한다.
            auto pos = lower_bound(b, b + m, a[i]); // 포인터를 반환한다.
            ret += (int) (pos - b); // 작은 원소 + 1을 반환하므로 a-b+1을 할 필요없다.
        }
        cout << ret << endl;
    }

    return 0;
}
