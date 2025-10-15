#include <bits/stdc++.h>
using namespace std;

const int n = 6;
vector<int> adj[n];
int vst[n];

// check first and then call dfs
void dfs_first(int from)
{
    cout << from << " ";
    vst[from] = 1;
    for ( int i : adj[from])
    {
        if (!vst[i]) dfs_first(i);
    }
    cout << "end of traversing from " << from << "\n";
}

// call fisrt check later
void dfs_second(int from)
{
    if (vst[from]) return;
    vst[from] = 1;
    cout << from << " ";
    for (int i: adj[from])
    {
        dfs_second(i);
    }
    cout << "end of traversing from " << from << "\n";
}

int main()
{
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[4].push_back(2);
    adj[2].push_back(5);
    cout << "DFS first\n";
    dfs_first(1);
    cout << "DFS second\n";
    memset(vst,0,sizeof(vst));
    dfs_second(1);
    return 0;
}