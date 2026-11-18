//
// Created by 5600G on 2026-11-18.
//
#include <bits/stdc++.h>
using namespace std;

int N,L,idx,ret,cnt;

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main()
{
    fastIO();
    cin >> N >> L;
    vector<pair<int,int>> v(N);
    // 각 웅덩이의 {시작 위치, 끝 위치} 저장
    for (int i=0;i<N;i++)
        cin >> v[i].first >> v[i].second;
    // 2. 왼쪽 웅덩이부터 순서대로 처리하기 위해 시작 위치 기준 오름차순 정렬
    sort(v.begin(), v.end());
    // 3. 정렬된 웅덩이를 하나씩 확인하며 필요한 널빤지 개수 계산
    for (int i=0; i<N; i++)
    {
        // [경우 1] 이전 웅덩이를 덮을 때 깐 널빤지가 이미 현재 웅덩이 끝까지 다 덮은 경우
        if (v[i].second <= idx ) continue;
        // [경우 2] 이전 널빤지가 현재 웅덩이 시작점에 못 미친 경우 -> 웅덩이 시작점(a[i].first)부터 새로 깔기
        if (idx < v[i].first)
        {
            // 덮어야 할 길이: (a[i].second - a[i].first)
            // 길이를 m으로 나눈 뒤 나머지가 조금이라도 남으면 널빤지 1개를 더 추가(+1)
            cnt = (v[i].second - v[i].first) / L + ((v[i].second - v[i].first) % L ==0? 0 : 1);
            // 새 널빤지 b개를 깔았을 때 도달하는 새로운 끝 좌표 갱신
            idx = v[i].first + cnt * L;
        }
        // [경우 3] 이전 널빤지가 현재 웅덩이의 앞부분을 일부 덮고 있는 경우 -> 이어지는 지점(idx)부터 깔기
        else
        {
            // 아직 안 덮인 남은 길이: (a[i].second - idx)
            cnt = (v[i].second - idx) / L + ((v[i].second - idx) % L ==0? 0 : 1);
            // 기존 끝점(idx)에서 b개만큼 더 연장한 좌표로 갱신
            idx = idx + cnt * L;
        }
        // 이번에 추가로 사용한 널빤지 개수 누적
        ret += cnt;
    }

    cout << ret << '\n';
    return 0;
}
