//
// Created by 이동한 on 2025. 1. 23..
//
#include <bits/stdc++.h>
using namespace std;

/**
*크기가 N인 수열 A = A1, A2, ..., AN이 있다.
*수열의 각 원소 Ai에 대해서 오큰수 NGE(i)를 구하려고 한다.
*Ai의 오큰수는 오른쪽에 있으면서 Ai보다 큰 수 중에서 가장 왼쪽에 있는 수를 의미한다.
*그러한 수가 없는 경우에 오큰수는 -1이다.
예를 들어, A = [3, 5, 2, 7]인 경우
NGE(1) = 5, NGE(2) = 7, NGE(3) = 7, NGE(4) = -1이다.
A = [9, 5, 4, 8]인 경우에는
NGE(1) = -1, NGE(2) = 8, NGE(3) = 8, NGE(4) = -1이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다.
둘째 줄에 수열 A의 원소 A1, A2, ..., AN (1 ≤ Ai ≤ 1,000,000)이 주어진다.

출력
총 N개의 수 NGE(1), NGE(2), ..., NGE(N)을 공백으로 구분해 출력한다.

예제 입력 1
4
3 5 2 7
예제 출력 1
5 7 7 -1
 * @see https://www.acmicpc.net/problem/17298
 */
int h[1000001],ret[1000001],n; // (0) h (height) 배열을 정의 해줌으로 pair(index, height)를 스택에 넣을 필요 없다.
stack<int> st;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    memset(ret, -1, sizeof(ret)); // (1) 초기에 스택에 남은 원소들을 비워주는 처리를 했는데 이렇게 하면 더 효율적이다.
    for (int i=0; i<n; i++) {
        cin >> h[i];
        // while 문으로
        while (st.size() && h[st.top()] < h[i]) { // (2) st.top()확인 하기 전에 항상 empty 체크 해주기
            ret[st.top()] = h[i];
            st.pop();
        }
        st.push(i);
    }
    for (int i = 0; i<n; i++) cout << ret[i] << " ";
    return 0;
}
