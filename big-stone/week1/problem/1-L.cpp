//
// Created by 이동한 on 2025. 1. 13..
//
#include <bits/stdc++.h>
using namespace std;

int n,m,cnt,arr[15001];

void combi_loop() {
    int ret =0;
    //(0) 반복문으로 조합 만들기
    for (int i= 0; i< n-1; i++) {
        for (int j = i+1; j<n; j++) {
            if (arr[i] + arr[j] == m) ret++;
        }
    }
    cout << ret << endl;
}
void combi(int idx, vector<int> &v) { // (1)vector는 &v 로 넘겨준다.
    if (v.size() == 2) {
        if (arr[v[0]] + arr[v[1]] == m) cnt++;
        return;
    }

    //(2) 재귀로 조합 만드는 방법 : 원복
    for (int i= idx + 1; i<n; i++) {
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
}

/**
 * 문제 링크
 * @see: https://www.acmicpc.net/problem/1940
 */
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<int> v;
    combi(-1, v);
    cout << cnt << "\n";

    return 0;
}
