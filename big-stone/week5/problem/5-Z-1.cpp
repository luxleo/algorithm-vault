//
// Created by 5600G on 2026-11-19.
//
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;

const int MAXN = 1000001;
int N,s,e, l,r,ret;
P L[MAXN];

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main()
{
    fastIO();
    cin >> N;
    for (int i=0; i<N; i++)
    {
        cin >> s >> e;
        L[i] = {s,e};
    }

    sort(L,L+N);

    l = L[0].first;
    r = L[0].second;

    for (int i=1; i<N; i++)
    {
        // case 1 : r 이 다음 시작점 보다 작을 때
        if (r < L[i].first)
        {
            ret += (r-l);
            l = L[i].first;
            r = L[i].second;
        }
        // case 2 : r 이 다음 시작점 크거나 같고 끝점보다 작을 떄 (겹쳐 있을때)
        else if (r >= L[i].first && r < L[i].second)
        {
            r = L[i].second;
        }
        // case 3 : 다음 선분이 현재 선분에 완전히 겹쳐있을 때 => cur (1,5) , next (2,4)
        else continue;
    }

    ret += (r - l); // 최종적으로 남은 녀석 처리
    cout << ret << '\n';
    return 0;
}
