//
// Created by 5600G on 2026-11-17.
//
#include <bits/stdc++.h>
using namespace std;

int from, to;       // 입력받을 회의의 시작 시간(from)과 종료 시간(to)
int n;              // 회의의 총 개수 N (1 <= N <= 100,000)
int idx = 0;        // 템플릿용 미사용 변수
int ret = 1;        // 답: 최대 회의 개수 (N >= 1이므로 첫 번째 회의는 무조건 선택 가능해 1로 시작)

int main(){
    // 입출력 속도 향상 (N이 최대 10만이므로 필수)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. 회의 개수 입력
    cin >> n;

    // {종료 시간(first), 시작 시간(second)} 순서로 저장할 벡터
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
        cin >> from >> to;
        // 종료 시간 기준 정렬을 쉽게 하기 위해 순서를 뒤집어 삽입
        v.push_back({to, from});
    }

    // 2. 종료 시간(first) 오름차순 -> 종료 시간이 같다면 시작 시간(second) 오름차순 정렬
    sort(v.begin(), v.end());

    // 3. 가장 빨리 끝나는 첫 번째 회의를 기준으로 초기 설정
    from = v[0].second;
    to = v[0].first;

    // 4. 두 번째 회의(인덱스 1)부터 순서대로 확인하며 겹치지 않는 회의 선택
    for(int i = 1; i < n; i++){
        // 현재 회의의 시작 시간(v[i].second)이 직전 회의의 종료 시간(to)보다 빠르다면 겹치므로 건너뜀
        // (시작 시간과 직전 종료 시간이 같은 경우 v[i].second == to 는 연속 진행 가능하므로 통과!)
        if(v[i].second < to) continue;

        // 겹치지 않는 가장 빨리 끝나는 회의를 선택하고, 기준 종료 시간(to) 갱신
        from = v[i].second;
        to = v[i].first;
        ret++;
    }

    // 5. 배정할 수 있는 최대 회의 개수 출력
    cout << ret << '\n';
    return 0;
}