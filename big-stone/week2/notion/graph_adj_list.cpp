//
// Created by 5600G on 2025-10-15.
//
#include <bits/stdc++.h>
using namespace std;

const int V = 11;
vector<int> adj[V];
int vst[V];

void go(int from)
{
    vst[from] = 1;
    cout << from << " ";
    for (auto i : adj[from])
    {
        if (!vst[i]) go(i);
    }
}

int main()
{   adj[1].push_back(2); adj[1].push_back(3);
    adj[2].push_back(1); adj[3].push_back(4);
    adj[3].push_back(1); adj[4].push_back(3);

    for (int i=0; i<V; i++)
    {
        if (!vst[i] && !adj[i].empty()) go(i);
    }
    return 0;
}
