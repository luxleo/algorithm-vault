//
// Created by 이동한 on 2025. 1. 23..
//
#include <bits/stdc++.h>
using namespace std;
int N,root,parent,target;
vector<int> v[51];
/**
 *
 * @see https://www.acmicpc.net/problem/1068
 */
// 아래 dfs 코드가 해결되지 않는 이유는 target node의 parent가 딱하나의 자식을 가지는 경우를
// 해결하지 못한다.
int dfs(int from) {
    if (v[from].empty()) return 1;
    int ret = 0;
    for (int node : v[from]) {
        ret +=dfs(node);
    }
    return ret;
}
int go (int from) {
    int child = 0;
    int ret = 0;
    for (int node : v[from]) {
        if (node == target) continue;
        ret += go(node);
        child++;
    }
    if (child == 0) return 1;
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i< N; i++) {
        cin >> parent;
        if (parent == -1) root = i;
        else v[parent].push_back(i);
    }
    cin >> target;
    if (root == target) {
        cout << 0 << "\n";
        return 0;
    }
    cout << dfs(root) - dfs(target) << "\n";
    return 0;
}
