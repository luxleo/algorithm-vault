//
// Created by 이동한 on 2025. 3. 10..
//
/** 비트마스킹을 이용한 경우의 수
문제
식재료 N개 중에서 몇 개를 선택해서 이들의 영양분
(단백질, 탄수화물, 지방, 비타민)이 일정 이상이 되어야 한다.
아래 표에 제시된 6가지의 식재료 중에서 몇 개를 선택해서
이들의 영양분의 각각 합이 최소 100, 70, 90, 10가 되도록
하는 경우를 생각해보자. 이 경우 모든 재료를 선택하면 쉽게 해결되지만,
우리는 조건을 만족시키면서도 비용이 최소가 되는 선택을 하려고 한다.

재료	단백질	지방	탄수화물	비타민	가격
1	30	55	10	8	100
2	60	10	10	2	70
3	10	80	50	0	50
4	40	30	30	8	60
5	60	10	70	2	120
6	20	70	50	4	40
예를 들어, 식재료 1, 3, 5를 선택하면 영양분은 100, 145, 130, 10으로
조건을 만족하지만 가격은 270이 된다. 대신 2, 3, 4를 선택하면
영양분의 합은 110, 130, 90, 10, 비용은 180이 되므로,
앞의 방법보다는 더 나은 선택이 된다.

입력으로 식재료 표가 주어졌을 때, 최저 영양소 기준을
만족하는 최소 비용의 식재료 집합을 찾아야 한다.

입력
첫 줄에 식재료의 개수
$N$이 주어진다.

다음 줄에는 단백질, 지방, 탄수화물, 비타민의 최소 영양성분을 나타내는 정수
$mp$,
$mf$,
$ms$,
$mv$가 주어진다.

이어지는
$N$개의 각 줄에는
$i$번째 식재료의 단백질, 지방, 탄수화물, 비타민과 가격이 5개의 정수
$p_i$,
$f_i$,
$s_i$,
$v_i$,
$c_i$와 같이 주어진다. 식재료의 번호는 1부터 시작한다.

출력
첫 번째 줄에 최소 비용을 출력하고, 두 번째 줄에 조건을 만족하는
최소 비용 식재료의 번호를 공백으로 구분해 오름차순으로 한 줄에
출력한다. 같은 비용의 집합이 하나 이상이면 사전 순으로 가장 빠른 것을 출력한다.

조건을 만족하는 답이 없다면 -1을 출력하고, 둘째 줄에 아무것도 출력하지 않는다.

제한
  
$3 \le N \le 15$ 
  
$0 \le mp, mf, ms, mv \le 500$ 
  
$mp + mf + ms + mv > 0$ 
  
$0 \le p_i, f_i, s_i, v_i, c_i \le 500$ 
예제 입력 1
6
100 70 90 10
30 55 10 8 100
60 10 10 2 70
10 80 50 0 50
40 30 30 8 60
60 10 70 2 120
20 70 50 4 4
예제 출력 1
134
2 4 6
 * @see https://www.acmicpc.net/problem/19942
 */
#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n,mp,mf,ms,mv,sum;
int b, c, d, e, ret = INF;
struct A { // 구조체로 여러 필드를 가지는 입력 받기.
    int mp,mf,ms,mv, cost;
} a[16];
map<int,vector<vector<int>>> ret_v; // 해당 비용(key) 에 해당하는 가능한 조합(value == vector<vector<int>>)
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for (int i =0; i<n; i++) {
        cin >> a[i].mp >> a[i].mf >> a[i].ms >> a[i].mv >> a[i].cost;
    }
    // 비트마스킹으로 가능한 조합
    for (int i=0; i<(1<<n); i++) {
        b=c=d=e=sum=0;
        vector<int> v;
        for (int j=0; j<n; j++) {
            // 현재 선택에 j가 포함되는지 1010은 1000 (4번째 요소)를 포함
            if (i & (1 << j)) {
                b+= a[j].mp;
                c+= a[j].mf;
                d+= a[j].ms;
                e+= a[j].mv;
                sum+= a[j].cost;
                v.emplace_back(j+1);
            }
        }
        if (b>=mp && c >= mf && d >=ms && e >= mv) {
            if (ret >= sum) {
                ret = sum;
                ret_v[ret].emplace_back(v);
            }
        }
    }
    if (ret == INF) cout << -1 << "\n";
    else {
        // 가능한 조합중 가장 적은 것
        sort(ret_v[ret].begin(), ret_v[ret].end());
        cout << ret << "\n";
        for (int node : ret_v[ret][0]) cout << node << " ";
        cout << "\n";
    }
    return 0;
}
