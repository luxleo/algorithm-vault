//
// Created by 이동한 on 2025. 8. 18..
//
/**
 *[2109](https://www.acmicpc.net/problem/2109)
 * TIP
 * 그리디는 무조건 sort + pq 조합으로 접근하자.
 * 그림으로 문제상황을 떠올려 보면 좋다.
 *
 * 문제 접근 구조: 날짜별롤 pq의 크기를 유지하여 가장 가격이 작은 순으로 방출한다.
 *
 * 자칫 날짜별로 가장 높은 가격의 강의를 정리하면 된다고 착각할 수 있으나 그렇지 않다.
 * 반례 예시:
 * 1일차: 20, 10
 * 2일차: 30,40
 * 으로 주어진 경우 2일차의 강의만 수락하는것이 가장 경제적이다.
 */
#include <bits/stdc++.h>
using namespace std;
int n,a,b,ret;
vector<pair<int,int>> v;
priority_queue<int, vector<int>, greater<>> pq; // 최소 힙을 작성하는 방법이다. priority_queue<자료형, [사용할 자료구조],[정렬방식]>

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for ( int i =0; i<n; i++) {
        cin >> a >> b;
        v.emplace_back(b,a); // 정렬의 편의성을 위해 마감일, 비용 순으로 삽입한다.
    }
    sort(v.begin(), v.end());
    for (int i=0; i<n; i++) {
        pq.emplace(v[i].second);
        if (pq.size() < v[i].first) {
            pq.pop();
        }
    }

    while (!pq.empty()) {
        ret += pq.top(); pq.pop();
    }
    cout << ret << endl;
}
