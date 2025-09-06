//
// Created by 이동한 on 2025. 9. 6..
//
/** G4 (https://www.acmicpc.net/problem/1911)
 * 라인스위핑 이었다.
 * 겹치는 구간을 하나로 합쳐진 것으로 다루면 되었기에 쉬운 문제였음
 *
 * 핵심 아이디어는 널빤지를 깔 위치 (idx) 와 현재 참조하는 물웅덩이의 위치에 따라
 * 널빤지 위치를 갱신하는데 있었음.
 *
 * 널빤지 갯수를 세이릴때 삼항연산자로 꼬투리 처리해주기
 */
#include <bits/stdc++.h>
using namespace std;

int n, l, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> l;
    vector<pair<int, int> > v(n);
    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    int idx = 0;
    int next = 0;
    for (int i = 0; i < n; i++) {
        if (idx > v[i].second) continue; // 널빤지 마지막 위치가 웅덩이 초과한 경우로 갱신할 필요가 없다.
        if (idx <= v[i].first) {
            // 웅덩이의 시작위치 보다 마지막 널빤지 위치가 뒤에 있으면 웅덩이 시작 위치 부터 깔아준다.
            next = (v[i].second - v[i].first) / l + ((v[i].second - v[i].first) % l ? 1 : 0);
            idx = v[i].first + next * l;
        } else {
            // 웅덩이 사이에 마지막 널빤지 위치가 있는 경우 그 위치를 기준으로 깔아준다.
            next = (v[i].second - idx) / l + ((v[i].second - idx) % l ? 1 : 0);
            idx += next * l;
        }
        ret += next;
    }
    cout << ret << endl;
    return 0;
}
