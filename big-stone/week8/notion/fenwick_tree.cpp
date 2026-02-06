//
// Created by 5600G on 2026-02-06.
//

#include <iostream>
#include <ostream>
#include <vector>
using namespace std;
vector<int> tree;

void update(int idx, int val)
{
    while (idx < tree.size()) // tree size 는 데이터 size + 1 이므로
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int sum(int index)
{
    int ret = 0;
    while (index > 0)
    {
        ret += tree[index];
        index -= (index & -index);
    }
    return ret;
}

int rangeQuery(int left, int right)
{
    return sum(right) - sum(left - 1);
}

int main()
{
    vector<int> data = {3,4,10,11};
    int n = data.size();
    tree.resize(n+1, 0);
    for (int i=0; i<n; i++)
    {
        update(i+1, data[i]);
    }
    cout << "1 ~ 4 sum :" << rangeQuery(1, 4) << "\n"; // 28
    cout << "2 ~ 3 sum :" << rangeQuery(2, 3) << "\n"; // 14

    update(5,2);
}
