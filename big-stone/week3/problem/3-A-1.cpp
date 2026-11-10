//
// Created by 5600G on 2026-11-10.
//

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 51;
const int MAX_M = 14;
const int INF = 1e9;
int n,m,ret, mp[MAX_N][MAX_N], vst[MAX_M];

vector<pair<int,int>> home, chicken;

int calcDistance(vector<int> &idx)
{
    int res = 0;
    for (auto [y1,x1] : home)
    {
        int local_res = INF;
        for (int i : idx)
        {
            // abs 함수로 절대값 바로 구하기
            local_res = min(local_res, abs(y1-chicken[i].first) + abs(x1-chicken[i].second));
        }
        res += local_res;
    }
    return res;
}

// dfs로 조합 구하기 / 조합 구현시 방문배열 원복해줘야한다
int dfs(int here, vector<int> &idx)
{
    if (idx.size() == m)
        return calcDistance(idx); // 완성된 조합에서 계산된 거리를 반환한다

    int res = 0;
    vst[here] = 1;

    for (int i=here; i<chicken.size(); i++)
    {
        if (!vst[i])
        {
            idx.emplace_back(i);
            res = min(res, dfs(i, idx));
            idx.pop_back();
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == 1) home.emplace_back(i,j);
            if (mp[i][j] == 2) chicken.emplace_back(i,j);
        }
    }

    // 조합으로 xCm 을 선택한다
    // 선택한 거리를 구하고 최소값을 갱신한다
    vector<int> idx;
    for (int i=0; i<chicken.size(); i++)
    {
        memset(vst, 0, sizeof(vst));
        idx.emplace_back(i);
        ret = min(ret, dfs(i, idx));
        idx.pop_back();
    }

    cout << ret << '\n';
    return 0;
}
