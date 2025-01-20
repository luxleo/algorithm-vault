//
// Created by 이동한 on 2025. 1. 20..
//
#include <bits/stdc++.h>
using namespace std;

/**
*그러나 남규는 O(N!)이 왜 큰지도 잘 모른다. 그래서 현우는 더더욱 경악을 금치 못하고,
*N!이 얼마나 큰지 대략적으로나마 알려주기 위해,
*자연수 N이 주어지면 N!의 오른쪽 끝에 있는 0의 개수를 알려주기로 하였다.
그러나 현우는 경악을 금치 못하여 지금 코딩을 할 수 없는 상황이다.
여러분이 현우를 대신하여 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어지고, 이어서 T개의 줄에 정수 N이 주어진다(1 <= N <= 1000000000).

출력
각 줄마다 N!의 오른쪽 끝에 있는 0의 개수를 출력한다.

예제 입력 1
6
3
60
100
1024
23456
8735373

예제 출력 1
0
14
24
253
5861
2183837
 * @see
 */
int n,cur,temp,twoCnt,fiveCnt;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> cur;
        fiveCnt = 0; twoCnt = 0;
        // for (int j =2; j<=cur; j*=2) {
        //     twoCnt += cur/j;
        // }
        for (int j=5; j<=cur; j*=5) { // 이와 같이 for 문을 갱신하는 변수를 스코프 내에서 자유롭게 다루어준다.
            fiveCnt+=cur/j;
        }
        // cout << min(twoCnt, fiveCnt) << "\n";
        cout << fiveCnt << "\n";
    }
    return 0;
}
