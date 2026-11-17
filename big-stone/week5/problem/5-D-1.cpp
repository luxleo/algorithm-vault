//
// Created by 5600G on 2026-11-17.
//
#include<bits/stdc++.h>
using namespace std;

int n; // 방문한 소의 총 마릿수 N (1 <= N <= 100)

int main(){
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. 소의 수 N 입력
    cin >> n;

    // {도착 시각(first), 검문 소요 시간(second)} 쌍을 저장할 벡터
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    // 2. 도착 시각(first) 기준으로 오름차순 정렬
    // 도착 시각이 같다면 검문 시간(second) 기준 오름차순으로 정렬됨 (순서는 결과에 영향 없음)
    sort(a.begin(), a.end());

    // 3. 첫 번째 소는 기다림 없이 도착 즉시 검문을 시작하므로 종료 시각으로 초기화
    int realTime = a[0].first + a[0].second;

    // 4. 두 번째 소(인덱스 1)부터 마지막 소까지 순서대로 검문 시뮬레이션
    for(int i = 1; i < a.size(); i++){
        // 검문소가 비는 시각(realTime)과 현재 소가 도착한 시각(a[i].first) 중 더 늦은 시각에 검문 시작
        realTime = max(realTime, a[i].first);

        // 검문 소요 시간만큼 경과
        realTime += a[i].second;
    }

    // 5. 마지막 소가 검문을 마치고 입장한 최종 시각 출력
    cout << realTime << "\n";
    return 0;
}