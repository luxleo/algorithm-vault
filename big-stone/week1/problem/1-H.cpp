//
// Created by 이동한 on 2025. 1. 12..
//
/**
 * 누적합을 이용하는 로직 작성하기
 * 문제 링크
 * @see: https://www.acmicpc.net/problem/2559
 */
#include <bits/stdc++.h>
using namespace std;
int n,k, temp, psum[100001], ret=-10000000;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k; // (1) 분열된 데이터 입력 받는 법
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        psum[i] = psum[i-1] + temp;
    }
    for (int i=k; i<= n; i++) {
        ret = max(ret, psum[i]-psum[i-k]); //(2) max 함수 사용하는 방법
    }
    cout << ret << "\n";
    return 0;
}
