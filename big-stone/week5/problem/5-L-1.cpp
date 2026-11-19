//
// Created by 5600G on 2026-11-18.
//
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 21;
int n,k,ret = INF, dat[MAXN][MAXN], vst[MAXN];

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int go(vector<int> &a, vector<int> &b)
{
    int sumA = 0, sumB=0;
    for (int i=0; i< k; i++)
        for (int j=0; j<k; j++)
        {
            if (i == j) continue;
            sumA += dat[a[i]][a[j]];
            sumB += dat[b[i]][b[j]];
        }

    return abs(sumA - sumB);
}

void combi(int here, vector<int> &v)
{
    if (v.size() == k)
    {
        vector<int> start,link;
        for (int i = 0; i < n; i++)
        {
            if (vst[i]) start.push_back(i);
            else link.push_back(i);
        }

        ret = min(ret, go(start,link));
        return;
    }

    for (int i=here + 1; i<n; i++)
    {
        vst[i] = 1;
        v.push_back(i);
        combi(i,v);
        v.pop_back();
        vst[i] = 0;
    }
}

int main()
{
    fastIO();
    cin >> n;

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> dat[i][j];

    k =  n >> 1;

    vector<int> v;
    combi(-1,v);

    cout << ret << '\n';

    return 0;
}
