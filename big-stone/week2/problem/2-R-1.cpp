//
// Created by 5600G on 2026-11-09.
//
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 51;
int n,r,temp,root;

vector<int> tree[MAX_N];

int dfs(int here)
{
    int ret = 0, child = 0;
    for (int node : tree[here])
    {
        if (node == r) continue; // 타깃 노드이면 dfs 진행하지 않는다 이는 곧 삭제를 의미한다
        ret += dfs(node); // 리프노드의 모든 수를 합하여 반환하게 된다.
        child++; // 자식 노드 카운트 해준다. 이는 자식 노드가 있으므로 리프노드에 들어가지 않음을 의미한다
    }
    if (child==0) return 1; // 리프노드 이므로 1을 반환한다.
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i=0; i<n; i++)
    {
        cin >> temp;
        if (temp == -1)
        {
            root = i;
            continue;
        }
        tree[temp].emplace_back(i); // 부모노드에 자식 노드 삽입
    }

    cin >> r; // 지울 노드 입력

    if (r== root)
    {
        cout << 0 << "\n"; // 루트 노드 삭제 하면 트리자체가 삭제되므로 리프노드 없음
        return 0;
    }

    cout << dfs(r) << "\n";
    return 0;
}
