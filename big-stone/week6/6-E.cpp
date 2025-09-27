//
// Created by 이동한 on 2025. 9. 27..
//
/** S4 @see https://www.acmicpc.net/problem/1269
 * 카운팅 스탈 맵 또는 배열 : 카운팅 할 때는 배열이나 맵 이용
 */
#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;
int n, m, temp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        mp[temp]++;
    }

    for (int i = 0; i < m; i++) {
        cin >> temp;
        mp[temp]++;
    }
    int ret = 0;
    // 맵 원소 순회는 iter로 하자.
    for (auto it: mp) {
        if (it.second == 1) ret++;
    }
    cout << ret << endl;
    return 0;
}
