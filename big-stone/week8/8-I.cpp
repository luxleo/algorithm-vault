//
// Created by 이동한 on 2026. 2. 8..
//
/** @see https://www.acmicpc.net/problem/1280
 * 나무의 위치가 뒤죽박죽 이더라도 직사각형 히스토그램으로 거리를 구하는 구조를 생각하면 편했다.
 * 현재 나무보다 위치가 작은 나무 들의 합 + 큰 나무들의 합으로 쪼개서 생각한다.
 * 모듈러 연산으로 거리 좁혀주기
 */
#include <bits/stdc++.h>
#define max_n 200004
#define ll long long
const ll mod = 1e9 + 7;
using namespace std;
ll ret = 1;
vector<ll> tree_cnt(max_n, 0), tree_cord(max_n, 0);

void update(vector<ll> &tree, int idx, ll val) {
    while (idx < tree.size()) {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

ll sum(vector<ll> &tree, int index) {
    ll result = 0;
    while (index > 0) {
        result += tree[index];
        index -= (index & -index);
    }
    return result;
}

ll query_sum(vector<ll> &tree, int s, int e) {
    if (s > e)return 0;
    return sum(tree, e) - sum(tree, s - 1);
}

int main() {
    int n, pos;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> pos;
        pos++; // 나무위치는 0보다 커야하므로 1을 더해준다.
        if (i != 1) {
            // 현재 나무위치 보다 작은 나무들로부터 거리의 합 (현재 pos 기준 - 작은 나무위치 pos) * ( 작은 나무위치의 수)
            ll left = pos * query_sum(tree_cnt, 1, pos - 1) - query_sum(tree_cord, 1, pos - 1);
            // 현재 나무위치 보다 큰 나무들로부터 거리의 합
            ll right = query_sum(tree_cord, pos + 1, max_n) - pos * query_sum(tree_cnt, pos + 1, max_n);
            ret *= (left + right) % mod;
            ret %= mod;
        }
        update(tree_cnt, pos, 1);
        update(tree_cord, pos, pos);
    }
    cout << ret << "\n";
}

