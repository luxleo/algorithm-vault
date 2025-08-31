//
// Created by 이동한 on 2025. 8. 31..
//
/** S1 [14889](https://www.acmicpc.net/problem/14889)
 * for문을 이용하여 순열 구현하기 + 비트마스킹을 이용한 조합 구하기
 * 또한 최솟값을 구하기 위해서는 최대 부터 갱신,
 * 최대값을 구하기 위해서는 최소부터 출발하여 갱신
 */
#include <bits/stdc++.h>
using namespace std;
int N, arr[104][104];
const int INF = 987654321;
int ret = INF;

int go(vector<int> &a, vector<int> &b) {
    pair<int, int> ret;

    // 순열을 작성해준다. (N/2)*(N/2)이다.
    // 이유는 N/2 가 인수로 넘어오는 a,b 길이의 최대길이 이므로.
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++) {
            ret.first += arr[a[i]][a[j]];
            ret.second += arr[b[i]][b[j]];
        }
    }
    return abs(ret.first - ret.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < (1 << N); i++) {
        if (__builtin_popcount(i) != N / 2) continue;
        // TODO: __builtin_popcount(i) ㅅㅏ용하지 않고 비트 연산 이용하여 카운트하기
        vector<int> start, link;
        // 조합을 비트마스킹을 이용하여 구하는 경우
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) start.emplace_back(j);
            else link.emplace_back(j);
        }
        // 현재의 조합으로 최소값 갱신시도.
        ret = min(ret, go(start, link));
    }
    cout << ret << endl;
    return 0;
}
