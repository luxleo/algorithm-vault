//
// Created by 이동한 on 2026. 11. 16..
//
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 501;
int N, a, b, lis[MAXN];

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    fastIO();
    cin >> N;
    vector<pair<int, int> > v;

    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v.emplace_back(a, b);
    }

    // 2. A전봇대 위치(pair의 first)를 기준으로 오름차순 정렬
    // A가 오름차순으로 정렬되면, B의 순서가 증가할 때마다 전깃줄이 교차하지 않음이 보장됨
    sort(v.begin(), v.end());

    int len = 0;

    // 3. 정렬된 전깃줄들의 B전봇대 위치(v[i].second)에 대해 O(N log N) LIS 길이 계산
    for (int i = 0; i < v.size(); i++) {
        // 현재 채워진 구간 [lis, lis + len) 에서 v[i].second 이상이 처음 나오는 위치 탐색
        auto pos = lower_bound(lis, lis + len, v[i].second);
        // 위치 번호는 항상 1 이상의 자연수이므로, 가리키는 값이 0이라면 아직 안 채워진 새 칸임
        if (*pos == 0) len++;
        // 해당 위치의 꼬리값을 더 작은(또는 같은) v[i].second로 갱신
        *pos = v[i].second;
    }

    // 4. 전체 전깃줄 수(n)에서 남길 수 있는 최대 개수(len)를 빼서 없애야 할 최솟값 출력
    cout << N - len << '\n';
    return 0;
}
