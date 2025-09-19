//
// Created by 이동한 on 2025. 9. 19..
//
/** G5 [https://www.acmicpc.net/problem/2170]
 * 라인 스위핑 이었으나 범위가 크므로 배열로 처리하지 않는다.
 * 대신 r,l 두 변수로 처리한다.
 */
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
P L[1000004]; // 페어 타입 커스텀 정의하여 배열로 선언
int n, from, to, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> from >> to;
        L[i] = P(from, to);
    }
    sort(L, L + n); // 필요한 길이 만큼만 정렬한다.
    int l = L[0].first, r = L[0].second;
    for (int i = 1; i < n; i++) {
        // 0은 갱신되었으므로 idx=1부터 시작
        if (L[i].first > r) {
            // 끊어진 경우 해당 선분으로부터 시작하도록 갱신
            ret += r - l;
            l = L[i].first;
            r = L[i].second;
        } else if (L[i].second > r && L[i].first <= r) {
            // 확장하는 조건일때 r만 갱신하여 확장
            r = L[i].second;
        }
    }
    ret += r - l; // 완료된 r,l 결과에 반영
    cout << ret << endl;
}
