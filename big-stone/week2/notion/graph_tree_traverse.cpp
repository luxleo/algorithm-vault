//
// Created by 5600G on 2025-10-16.
//
/**
 * 이진트리라 가정하고 탐사를 실행한다.
 */
#include <bits/stdc++.h>
using namespace std;
const int n = 21;
int vst[n];
vector<int> adj[n];

void preorder(int from)
{
    if (!vst[from])
    {
        cout << from << " ";
        vst[from] = 1;
        if (adj[from].size() == 1) preorder(adj[from][0]);
        else if (adj[from].size() == 2)
        {
            preorder(adj[from][0]);
            preorder(adj[from][1]);
        }
    }
}

void postorder(int from)
{
    // 아직 탐사하지 않은 노드일때만 실행한다.
    if (!vst[from])
    {
        if (adj[from].size() == 1) postorder(adj[from][0]);
        else if (adj[from].size() == 2)
        {
            postorder(adj[from][0]);
            postorder(adj[from][1]);
        }
        cout << from << " ";
        vst[from] = 1;
    }
}

void inorder(int from)
{
    if (!vst[from])
    {
        if (adj[from].size() == 1)
        {
            inorder(adj[from][0]);
            cout << from << " ";
            vst[from] = 1;
        } else if (adj[from].size() == 2)
        {
            inorder(adj[from][0]);
            cout << from << " ";
            vst[from] = 1;
            inorder(adj[from][1]);
        } else
        {
            cout << from << " ";
            vst[from] = 1;
        }
    }
}

int main()
{
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);
    int root = 1;
    cout << "preorder\n";
    preorder(root);
    memset(vst, 0, sizeof(vst));
    cout << "\n inorder\n";
    inorder(root);
    memset(vst, 0, sizeof(vst));
    cout << "\n postorder\n";
    postorder(root);
    return 0;
}
