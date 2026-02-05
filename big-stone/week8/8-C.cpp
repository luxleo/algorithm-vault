//
// Created by 5600G on 2026-02-05.
//
/** @see https://www.acmicpc.net/problem/17258
 * 데이터 전처리 (압축) 을 통하여 효율을 추구함
 */
#include <bits/stdc++.h>
using namespace std;

struct Segment // 구간의 길이와 해당 구간 동안 사람의 수
{
    int duration, cnt;
};
int N,M,K,T, dp[301][301], cnt[301]; // cnt: 시간당 사람의 수. dp[구간인덱스][남은 사람의 수]
vector<Segment> v;

/**
 *
 * @param idx : 현재 조회하는 v 인덱스
 * @param remnant : 남은 친구 수
 * @param prev : 이전 단계에 존재한 친구 수
 * @return
 */
int go(int idx, int remnant, int prev)
{
    if (idx == v.size()) return 0;
    int &ret = dp[idx][remnant];
    if (ret) return ret;

    int cost = max(0, T - v[idx].cnt);
    int real_cost = (prev >= cost) ? 0 : cost - prev; // 이전에 부른 친구가 있고 그 수가 비용보다 크면 비용이 0, 아니면 더 불러야하는 수;
    if (cost == 0) prev = 0;
    if (remnant >= real_cost)
    {
        return ret = max(go(idx+1, remnant - real_cost, cost) + v[idx].duration, go(idx+1, remnant, prev));
    }
    // ret = go(idx+1,remnant,prev) 의 의미는 영제가 떠났다는 의미가 되므로 v[idx].duration 을 더하지 않는다. 이는 머무는 시간이 추가 되지 않음을 의미한다.
    return ret = go(idx+1, remnant, prev);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K >> T;

    for (int i=0; i<M; i++)
    {
        int start, end;
        cin >> start >> end;
        // end 에는 나가므로 포함하지 않는다.
        for (int j=start; j<end; j++) cnt[j] = min(T,++cnt[j]);
    }

    // 파티 진행 시간 동안 인원수 동일한 구간끼리 압축
    int current_people = cnt[1];
    int duration = 1;
    for (int i=2; i<= N; i++)
    {
        if (current_people == cnt[i])
        {
            duration++;
            continue;
        }
        // 만일 시간에서 인원이 달라지면 압축진행한다.
        v.push_back({duration, current_people});
        current_people = cnt[i];
        duration = 1; // 구간 초기화
    }
    v.push_back({duration, current_people}); // 루프 끝나고나서 처리
    cout << go(0,K,0) << "\n";
    return 0;
}
