//
// Created by 5600G on 2025-10-16.
//
#include <bits/stdc++.h>
using namespace std;

const int n = 21;
int vst[n];
vector<int> adj[n];

void bfs(int from)
{
    queue<int> q;
    q.push(from);
    vst[from] = 1;

    while (q.size())
    {
        int next = q.front(); q.pop();
        cout << next << " ";
        for (int i : adj[next])
        {
            if (vst[i]) continue;
            q.push(i);
            vst[i] = 1;
        }
    }
}

/**
 *
 * @param from start index
 * @param target target to find
 */
void bfs_shortest_path(int from, int target)
{
    queue<int> q;
    vst[from] = 1;
    q.push(from);

    while (q.size())
    {
        int next = q.front(); q.pop();
        for (int i : adj[next])
        {
            if (!vst[next])
            {
                vst[next] = vst[from] + 1;
                q.push(i);
            }
            if (next == target)
            {
                cout << vst[next] << "\n";
                return;
            }
        }
    }
}

int main()
{
    adj[10].push_back(12);
    adj[10].push_back(14);
    adj[10].push_back(16);
    adj[12].push_back(18);
    adj[12].push_back(20);

    adj[20].push_back(22);
    adj[20].push_back(24);
    return 0;
}
