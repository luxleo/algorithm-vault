//
// Created by 이동한 on 2025. 8. 22..
//
/** [14469](https://www.acmicpc.net/problem/14469)
 *S4
 * 대표적인 라인스위핑 문제였다.
 * 겹치는 구간을 이어붙여 주기 위해  끝 지점을 밀어주어 갱신해주는게 포인트.
 * 무난하게 정렬을 이용하여 시간을 구하는 문제였다.
 */
#include <bits/stdc++.h>
using namespace std;

int N, a, b, ret;
vector<pair<int, int> > v;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v.emplace_back(a, b);
    }
    sort(v.begin(), v.end()); // a기준으로 오름차순 정렬후 이후 b기준으로 오름차순.
    for (pair<int, int> p: v) {
        ret = max(ret, p.first) + p.second;
    }
    cout << ret << endl;
    return 0;
}
