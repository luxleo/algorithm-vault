//
// Created by 5600G on 2026-02-12.
//

/** @see https://www.acmicpc.net/problem/17612
 * 우선순위 큐의 순서배열 부등호 부호는 반대로 해주어야한다. (최대힙으로 구성되어있기 때문이다.)
 * sort(구조체, 구조체, comp) 로 커스텀 비교 로직을 구성할 수 있다.
 */
#include <bits/stdc++.h>
using namespace std;

struct Cacher
{
    int customer_id, maxTime, cacher_id;
};
// 입장 규칙을 정하는 비교 함수 (우선순위 큐용)
struct comp
{
    bool operator()(Cacher &a, Cacher &b)
    {
        if (a.maxTime == b.maxTime)
        {
            // 계산 완료 시간이 같으면 계산대 id 가 적은 점원이 먼저 계산
            return a.cacher_id> b.cacher_id;
        }
        // 계산 완료시간이 다르면, 빨리 끝나는 사람이 나간다.
        return a.maxTime > b.maxTime;
    }
};

bool cmp2(Cacher &a, Cacher &b)
{
    if (a.maxTime == b.maxTime)
        // 계산시간 같으면 계산대 번호 큰 고객부터 처리
        return a.cacher_id > b.cacher_id;
    // 계산시간 적게 걸리는 사람부터 처리
    return a.maxTime < b.maxTime;
}

priority_queue<Cacher, vector<Cacher>, comp> pq; // 계산대 상태 관리
vector<Cacher> v; // 계산을 마친 고객들을 순서대로 저장할 벡터

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int id, cost_time;
        cin >> id >> cost_time;

        if(i < k) {
            // 처음 K명의 고객은 1번부터 K번 계산대에 순서대로 들어감
            pq.push({id, cost_time, i + 1});
        } else {
            // K명 이후의 고객은 가장 빨리 비는 계산대로 이동
            // pq.top()은 현재 가장 빨리 계산이 끝나는 계산대의 정보
            int next_available_time = pq.top().maxTime;
            int target_cacher_id = pq.top().cacher_id;

            // 계산 완료된 사람은 결과 리스트(v)에 넣고 제거
            v.push_back(pq.top());
            pq.pop();

            // 새 고객을 방금 비워진 계산대에 배정 (기존 종료시간 + 현재 고객 물건 수)
            pq.push({id, next_available_time + cost_time, target_cacher_id});
        }
    }

    // 모든 고객이 계산대에 들어갔으므로, 남아있는 고객들을 모두 꺼냄
    while(pq.size()) {
        v.push_back(pq.top());
        pq.pop();
    }

    // 퇴장 규칙(cmp2)에 맞춰 정렬 (시간순, 같은 시간엔 계산대 번호 역순)
    sort(v.begin(), v.end(), cmp2);

    long long ret = 0;
    for(int i = 0; i < v.size(); i++) {
        // 결과값 계산: (순서 * 회원번호)를 모두 더함
        // 1LL을 곱해 long long 범위를 보장
        ret += 1LL * (i + 1) * v[i].customer_id;
    }
    cout << ret << "\n";
}
