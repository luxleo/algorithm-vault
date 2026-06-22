//
// Created by 5600G on 2026-03-12.
//
#include <bits/stdc++.h>
using namespace std;

vector<int> tree;

void update(int idx, int val)
{
    while (idx < tree.size())
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int sum(int idx)
{
    int ret = 0;
    while (idx >0)
    {
        ret += tree[idx];
        idx -= (idx & -idx);
    }
}
