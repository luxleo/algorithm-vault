/** P5 @see https://www.acmicpc.net/problem/14003
 * LIS의 역추적 하는 문제.
 * lower_bound 함수의 반환값은 포인터이다. 이 값을 잘 활용한다.
 * pair<int,int> 의 배열을 선언하는 방법.
 *
 */
#include <bits/stdc++.h>
using namespace std;

int n, lis[1000004], len, num;
pair<int, int> ans[1000004];
stack<int> stk;
const int INF = 1e9 + 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fill(lis, lis + 1000004, INF);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        auto lowerPos = lower_bound(lis, lis + len, num);
        int _pos = lowerPos - lis;
        if (*lowerPos == INF) len++; // 길이가 새로 추가된 것이다.
        *lowerPos = num; // 덮어쓴다.
        ans[i].first = _pos;
        ans[i].second = num;
    }
    cout << len << "\n";
    for (int i = n - 1; i >= 0; i--) {
        if (ans[i].first == len - 1) {
            stk.push(ans[i].second);
            len--;
        }
    }
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << "\n";
    return 0;
}
