//
// Created by 5600G on 2026-11-17.
//
#include <bits/stdc++.h>
using namespace std;

int n,a,b,ret;
vector<pair<int,int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main()
{
    fastIO();
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> a >> b;
        v.emplace_back(a,b);
    }

    // first 기준으로 오름차순 정렬, 만일 first가 같다면 second 기준으로 오름차순 정렬
    sort(v.begin(),v.end());

    for (int i=0; i<n; i++)
    {
        ret += v[i].second;
        pq.emplace(v[i].second);

        // 현재까지 선택한 문제 수(pq.size())가 현재 데드라인(v[i].first)을 초과했다면?
        // 즉, 시간 안에 모두 풀 수 없는 상태라면 가장 컵라면 수가 적은 문제 1개를 포기함
        if (pq.size() > v[i].first)
        {
            ret -= pq.top();
            pq.pop();
        }
    }

    cout << ret << '\n';
    return 0;
}