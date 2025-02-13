//
// Created by 이동한 on 2025. 2. 13..
//
/** 경로를 구하는 문제 -> prev[now] = past; 형식으로 저장
문제
수빈이는 동생과 숨바꼭질을 하고 있다.
수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고,
동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다.
만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다.
순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때,
수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력
첫째 줄에 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
둘째 줄에 어떻게 이동해야 하는지 공백으로 구분해 출력한다.

예제 입력 1
5 17
예제 출력 1
4
5 10 9 18 17
 * @see https://www.acmicpc.net/problem/13913
 */
#include <bits/stdc++.h>
using namespace std;
const int MAX = 200000;
int n,k,here,vst[MAX +1], hist[MAX + 1];
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    if ( n == k) {
        cout << 0 << "\n" << n << "\n";
        return 0;
    }
    queue<int> q;
    vst[n] = 1;
    q.push(n);
    while (!q.empty()){
        here = q.front(); q.pop();
        for (int next : {here - 1, here + 1, here*2}) {
            if (next < 0 || next >= MAX) continue;
            if (!vst[next]) {
                vst[next] = vst[here] + 1;
                hist[next] = here; // 포인터 식으로 경로 역추적 가능하도록 설정
                q.push(next);
            }
        }
    }

    cout << vst[k] -1 << "\n";

    //(1) for 문의 한계 조건과 갱신 조건의 유연한 적용(단순 증가만 일어나는 것은 아니다.)
    for (int i = k; i != n; i = hist[i]) {
        // hist[k]부터 역추적 하며 경로 만들기
        v.push_back(i);
    }
    v.push_back(n);
    //도착점부터 삽입하기에 뒤집어 줘야한다.
    reverse(v.begin(),v.end());
    for (int node : v) {
        cout << node << " ";
    }
    cout << "\n";
    return 0;
}
