//
// Created by 5600G on 2026-11-11.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e9;
int n, mp, mf, ms, mv;
int b, c, d, e, ret = INF, sum;

struct A
{
    int mp,mf,ms,mv,cost;
} a[16];
map<int, vector<vector<int>>> combi; // cost 를 키로 가지는 재료들의 조합

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    fastIO();
    cin >> n;
    cin >> mp >> mf >> ms >> mv;

    for (int i=0; i<n; i++)
    {
        cin >> a[i].mp >> a[i].mf >> a[i].ms >> a[i].mv >> a[i].cost;
    }

    // 핵심 알고리즘 부분 비트마스킹으로 조합을 구한다 .
    // --- BITMASK SUBSET GENERATION ---
    // With N ingredients, there are 2^N possible combinations (subsets).
    // (1 << n) equals 2^n. We loop i from 1 to (2^n - 1) to test all non-empty subsets.
    // Each integer 'i' in binary represents which ingredients are picked (1 = pick, 0 = skip).
    for (int i=0; i< (1 << n); i++)
    {
        b = c = d = e = sum = 0;
        vector<int> tmp;
        for (int j=0; j<n; j++)
        {
            // Check if the j-th bit in binary number 'i' is turned on (1)
            // (1 << j) creates a number with only the j-th bit set to 1.
            if (i & (1 << j))
            {
                tmp.emplace_back(j + 1);
                b += a[j].mp;
                c += a[j].mf;
                d += a[j].ms;
                e += a[j].mv;
                sum += a[j].cost;
            }
        }

        if (b >= mp && c >= mf && d >= ms && e >= mv)
        {
            if (ret >= sum) // ret > sum 으로 하면 최소 비용일 때 놓치는 경우가 생긴다
            {
                ret = min(ret, sum);
                combi[ret].emplace_back(tmp);
            }
        }
    }

    if (ret == INF) cout << -1 << '\n';
    else
    {
        sort(combi[ret].begin(), combi[ret].end());
        cout << ret << '\n';
        for (int i : combi[ret][0])
            cout << i << ' ';
        cout << '\n';
    }
    return 0;
}
