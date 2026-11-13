//
// Created by 5600G on 2026-11-13.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,ret, temp;

stack<pair<ll,ll>> st;

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main()
{
    fastIO();
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin >> temp;// 현재 사람의 키 입력
        // cnt: 현재 사람(temp)과 키가 같아서 하나로 묶일 사람의 수 (자기 자신 1명으로 시작)
        int cnt = 1;
        // 3. 스택의 맨 위 사람이 현재 사람(temp)보다 키가 작거나 같다면 반복
        // 이유: temp보다 작거나 같은 앞사람은 temp와 마주 볼 수 있고,
        //       작은 사람의 경우 temp에게 가려져 뒷사람과는 더 이상 볼 수 없으므로 스택에서 제거함
        while (!st.empty() && st.top().first <= temp)
        {
            // 스택 맨 위에 묶여 있던 사람들(s.top().second명) 모두 현재 사람(temp)과 마주 볼 수 있음
            ret += st.top().second;
            if (st.top().first < temp)
                cnt  = 1;
            // 만약 앞사람과 현재 사람의 키가 정확히 같다면?
            else if (st.top().first == temp)
                // 기존에 묶여 있던 인원수에 현재 사람(1명)을 합쳐서 하나로 압축
                // |
                // | |          => 이런 꼴이면 3->2->1->1 이니까 마지막 1의 경우 해당 원소만 더해주면 된다
                // | | | |
                cnt = st.top().second + 1;
            st.pop();
        }

        /// 4. 작거나 같은 사람을 다 꺼낸 뒤에도 스택에 사람이 남아있다면?
        // 스택 맨 위(s.top())에는 현재 사람(temp)보다 키가 큰 '가장 가까운 앞사람'이 있음
        // 이 사람 1명과는 중간에 가리는 사람이 없으므로 서로 볼 수 있음!
        if (!st.empty()) ret++;
        st.push({temp,cnt});
    }
    cout << ret << '\n';
    return 0;
}
