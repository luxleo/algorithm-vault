//
// Created by 5600G on 2026-11-11.
//
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1023; // max depth가 10 이므로 2**10 -1 의 노드를 가질 수 있다
const int MAXLEVEL = 11;
int K, dat[MAXN];
vector<int> v[MAXLEVEL];

void buildTreeFromInorderResult(int s, int e, int level){
    if (s > e) return;
    if (s == e)
    {
        v[level].emplace_back(dat[s]);
        return;
    }

    // 완전 이진 트리 중위 순회시 시작 점과 끝점의 평균은 반드시 루트노드의 인덱스에 위치한다
    // 완전 이진 트리의 경우 루트 노드를 기준으로 왼쪽 서브트리와 오른쪽 서브 트리의 노드 수는 정확히 같기 때문이다.
    int mid = (s + e) >> 1;
    v[level].emplace_back(dat[mid]);

    buildTreeFromInorderResult(s, mid - 1, level + 1);
    buildTreeFromInorderResult(mid + 1, e, level + 1);
}

int main(){
    cin >> K;
    int endIdx = pow(2,K) - 1;

    for (int i=0; i< endIdx; i++)
        cin >> dat[i];

    buildTreeFromInorderResult(0,endIdx - 1, 1);

    for (int i=1; i<=K; i++)
    {
        for (int node : v[i])
            cout << node << " ";
        cout << "\n";
    }
    return 0;
}
