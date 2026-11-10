//
// Created by 5600G on 2026-11-10.
//
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000001;
int n, dat[MAX_N], ret[MAX_N];

stack<int> st; // 단조 스택, 아직 오큰수를 찾지 못한 인덱스를 오름차순으로 정렬하게 된다

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    memset(ret, -1, sizeof(n)); // 1바이트 단위의 수 1,0,-1로 초기화 할 때 사용

    for (int i=0; i<n; i++)
    {
        cin >> dat[i];
        while (!st.empty() && dat[st.top()] < dat[i]) // 현재 수가 아직 오큰수를 찾지 못한 인덱스의 오큰수가 되는지 확인
        {
            ret[st.top()] = dat[i]; // 오큰수 배열에 찾지 못한 인덱스의 오큰수 삽입
            st.pop();
        }
        st.push(i);
    }

    for (int i=0; i<n; i++)
        cout << ret[i] << ' ';
    cout << "\n";

    return 0;
}
