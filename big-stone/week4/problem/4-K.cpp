//
// Created by 이동한 on 2025. 4. 2..
//
#include <bits/stdc++.h>
using namespace std;
int N,V,E;
int s,e;
int cnt;
const int MAX_NODE = 1004;
int vst[MAX_NODE];
vector<int> mp[MAX_NODE];

void dfs(int here) {
    vst[here] = 1;
    for (int next : mp[here]) {
        if (!vst[next]) dfs(next);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    while (N--) {
        for (int i=0; i< MAX_NODE; i++)
            mp[i].clear(); // vector 초기화
        fill(vst,vst+MAX_NODE, 0);
        cnt=0;
        cin >> V;
        cin >> E;
        for (int i=0; i<E; i++) {
            cin >> s >> e;
            mp[s].emplace_back(e);
            mp[e].emplace_back(s);
        }
        for (int i=1; i<=V; i++) {
            if (!vst[i]) {
                dfs(i);
                cnt++;
            }
        }
        if (E == V-1 && cnt == 1) cout << "tree" << "\n";
        else cout << "graph" << "\n";
    }
}
