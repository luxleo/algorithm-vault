//
// Created by 이동한 on 2025. 3. 13..
//
/**
문제
백준시의 시장 최백준은 지난 몇 년간 게리맨더링을 통해서
자신의 당에게 유리하게 선거구를 획정했다.
견제할 권력이 없어진 최백준은 권력을 매우 부당하게 행사했고,
심지어는 시의 이름도 백준시로 변경했다. 이번 선거에서는
최대한 공평하게 선거구를 획정하려고 한다.
백준시는 N개의 구역으로 나누어져 있고,
구역은 1번부터 N번까지 번호가 매겨져 있다.
구역을 두 개의 선거구로 나눠야 하고, 각 구역은 두 선거구
중 하나에 포함되어야 한다. 선거구는 구역을 적어도 하나 포함해야
하고, 한 선거구에 포함되어 있는 구역은 모두 연결되어 있어야 한다.
구역 A에서 인접한 구역을 통해서 구역 B로 갈 수 있을 때,
두 구역은 연결되어 있다고 한다. 중간에 통하는 인접한
구역은 0개 이상이어야 하고, 모두 같은 선거구에 포함된 구역이어야 한다.

아래 그림은 6개의 구역이 있는 것이고, 인접한
구역은 선으로 연결되어 있다.
아래는 백준시를 두 선거구로 나눈 4가지 방법이며,
가능한 방법과 불가능한 방법에 대한 예시이다.

가능한 방법
[1, 3, 4]와 [2, 5, 6]으로 나누어져 있다.

가능한 방법
[1, 2, 3, 4, 6]과 [5]로 나누어져 있다.

불가능한 방법
[1, 2, 3, 4]와 [5, 6]으로 나누어져 있는데,
5와 6이 연결되어 있지 않다.

불가능한 방법
각 선거구는 적어도 하나의 구역을 포함해야 한다.

공평하게 선거구를 나누기 위해 두 선거구에 포함된
인구의 차이를 최소로 하려고 한다. 백준시의 정보가
주어졌을 때, 인구 차이의 최솟값을 구해보자.

입력
첫째 줄에 구역의 개수 N이 주어진다. 둘째 줄에 구역의
인구가 1번 구역부터 N번 구역까지 순서대로 주어진다.
인구는 공백으로 구분되어져 있다.

셋째 줄부터 N개의 줄에 각 구역과 인접한 구역의 정보가 주어진다.
각 정보의 첫 번째 정수는 그 구역과 인접한 구역의 수이고,
이후 인접한 구역의 번호가 주어진다. 모든 값은 정수로 구분되어져 있다.
구역 A가 구역 B와 인접하면 구역 B도 구역 A와 인접하다.
인접한 구역이 없을 수도 있다.

출력
첫째 줄에 백준시를 두 선거구로 나누었을 때, 두 선거구의
인구 차이의 최솟값을 출력한다. 두 선거구로 나눌 수 없는
경우에는 -1을 출력한다.

제한
2 ≤ N ≤ 10
1 ≤ 구역의 인구 수 ≤ 100
예제 입력 1
6
5 2 3 4 1 2
2 2 4
4 1 3 6 5
2 4 2
2 1 3
1 2
1 2
예제 출력 1
1
 * @see https://www.acmicpc.net/problem/17471
 */
#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, a[11], m, temp, ret=INF, comp[11], visited[11];
vector<int> adj[11];
pair<int, int> dfs(int here, int value) {
    visited[here] = 1;
    pair<int,int> ret = {1, a[here]};
    for (int next : adj[here]) {
        if (comp[next] != value) continue;
        if (visited[next]) continue;
        pair<int,int> _temp = dfs(next,value);
        // 참조하여 연산하면 그대로 갱신된다.(ret)
        ret.first += _temp.first;
        ret.second += _temp.second;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    // 노드 번호를 바로 이용할 수 있도록 index + 1해준다.
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i =1; i<=n; i++) {
        cin >> m;
        for (int j=0; j<m; j++) {
            // 양방향 연결 해준다.
            cin >> temp;
            adj[i].emplace_back(temp);
            adj[temp].emplace_back(i);
        }
    }
    // 모두 0인 경우를 제외하기 위해서 1부터 시작, 모두 1인 경우를 제외하기 위해 (1<<n) -1 == 11111-1 == 11110
    for (int i=1; i< (1 << n) -1; i++) {
        fill(comp, comp + 11, 0);
        fill(visited, visited+11,0);
        int idx1 = -1, idx0 = -1;
        for (int j=0; j<n; j++) {
            if (i & (1 << j)) { // 1인 경우를 찾아서 매칭한다.
                comp[j+1] =1; // 현재 1로 세팅된 인덱스 저장
                idx1 = j+1; // connected component는 어느 지점에서 시작해도 상관없으므로 현재 인덱스로 갱신
            } else idx0 = j+1;
        }
        pair<int,int> comp0 = dfs(idx0,0);
        pair<int,int> comp1 = dfs(idx1, 1);
        if (comp0.first + comp1.first == n ) ret = min(ret, abs(comp0.second - comp1.second));
    }
    cout << (ret == INF ? -1 : ret) << "\n";
    return 0;
}
