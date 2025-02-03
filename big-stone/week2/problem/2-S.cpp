//
// Created by 이동한 on 2025. 1. 23..
//
#include <bits/stdc++.h>
using namespace std;

/* memset vs fill
1. memset은 -1, 0으로 채울 거 아니면 쓰지 말자. 아니면 빠르게 채워야 할 때나 쓰자.
2. fill은 느리지만 안전하다.
3. 정말 많은 테스트 케이스가 있는 거 아니면 fill 쓰자.
@see https://0xffffffff.tistory.com/32
 */

/**
문제
해커 김지민은 잘 알려진 어느 회사를 해킹하려고 한다.
이 회사는 N개의 컴퓨터로 이루어져 있다. 김지민은 귀찮기 때문에,
한 번의 해킹으로 여러 개의 컴퓨터를 해킹 할 수 있는 컴퓨터를 해킹하려고 한다.
이 회사의 컴퓨터는 신뢰하는 관계와, 신뢰하지 않는 관계로 이루어져 있는데,
A가 B를 신뢰하는 경우에는 B를 해킹하면, A도 해킹할 수 있다는 소리다.
이 회사의 컴퓨터의 신뢰하는 관계가 주어졌을 때,
한 번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에, N과 M이 들어온다.
N은 10,000보다 작거나 같은 자연수,
M은 100,000보다 작거나 같은 자연수이다.
둘째 줄부터 M개의 줄에 신뢰하는 관계가 A B와 같은 형식으로 들어오며,
"A가 B를 신뢰한다"를 의미한다.
컴퓨터는 1번부터 N번까지 번호가 하나씩 매겨져 있다.

출력
첫째 줄에, 김지민이 한 번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호를 오름차순으로 출력한다.

예제 입력 1
5 4
3 1
3 2
4 3
5 3
예제 출력 1
1 2
 * @see https://www.acmicpc.net/problem/1325
 */
vector<int> v[10001];
int dp[10001],vst[10001], n,m,a,b,ans;

// (0) 분할 정복의 냄새가 솔솔 난다. sum up 되는 구조를 잘 기억하자.
int dfs(int sNode) {
    vst[sNode] = 1;
    int ret = 1;
    for (int node : v[sNode]) {
        if (vst[node]) continue;
        ret += dfs(node); // sum up되는 구간.
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        v[b].push_back(a);
    }
    for (int i =1; i<=n; i++) {
        memset(vst, 0, sizeof(vst)); // 초기화를 우아하게
        dp[i] = dfs(i);
        ans = max(ans,dp[i]);
    }
    for (int i=1; i<=n; i++) if (ans == dp[i]) cout << i << " ";
    return 0;
}
