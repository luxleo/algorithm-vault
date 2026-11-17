//
// Created by 5600G on 2026-11-17.
//
#include<bits/stdc++.h>
using namespace std;

// 보석 최대 30만 개 × 최대 가격 100만 = 3 * 10^11 (int 범위 초과)이므로 long long 필수
typedef long long ll;

ll n, k;            // n: 보석 개수(N), k: 가방 개수(K)
ll ret;             // 답: 훔칠 수 있는 보석 가격의 최댓값
ll temp1, temp;     // 미사용 변수

int main(){
    // 입출력 속도 향상 (N, K가 최대 30만이므로 필수)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. 보석 개수(n)와 가방 개수(k) 입력
    cin >> n >> k;

    vector<pair<ll,ll>> v(n);   // 보석 정보: {무게(first), 가격(second)}
    vector<ll> vv(k);           // 가방 정보: 담을 수 있는 최대 무게

    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
    for(int i = 0; i < k; i++) {
        cin >> vv[i];
    }

    // 2. 보석은 무게(first) 기준 오름차순, 가방은 최대 무게 기준 오름차순 정렬
    sort(v.begin(), v.end());
    sort(vv.begin(), vv.end());

    // 현재 가방에 넣을 수 있는 보석들의 '가격'을 내림차순(가장 비싼 것이 top)으로 관리하는 최대 힙
    priority_queue<ll> pq;

    // 3. 용량이 작은 가방부터 하나씩 순회하며 최적의 보석 배정
    int j = 0; // 보석 배열을 가리키는 단방향 포인터 (전체 루프 동안 최대 N번만 증가)
    for(int i = 0; i < k; i++){
        // 현재 가방(vv[i])에 들어갈 수 있는 무게의 보석들을 모두 최대 힙에 추가
        while(j < n && v[j].first <= vv[i]) {
            pq.push(v[j++].second);
        }

        // 담을 수 있는 후보 보석이 하나라도 있다면, 그중 가장 비싼 보석 1개를 선택
        if(pq.size()){
            ret += pq.top();
            pq.pop();
        }
    }

    // 4. 훔칠 수 있는 보석 가격의 최대 합 출력
    cout << ret << "\n";
    return 0;
}