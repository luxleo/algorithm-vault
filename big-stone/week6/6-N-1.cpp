//
// Created by 5600G on 2026-11-16.
//
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
int N, a[MAXN], prev_list[MAXN], cnt[MAXN],ret = 1,lastIdx;

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void go(int idx)
{
    if (idx == -1) return;
    go(prev_list[idx]);
    cout << a[idx] << ' ';
}

int main()
{
    fastIO();
    cin >> N;
    for (int i=0; i<N; i++)
        cin >> a[i];

    memset(prev_list, -1, sizeof(prev_list));
    fill(cnt, cnt + MAXN, 1);

    for (int e=0; e<N; e++)
    {
        for (int s = 0; s<e; s++)
        {
            if (a[s] < a[e] && cnt[e] < cnt[s] + 1)
            {
                cnt[e] = cnt[s] + 1;
                prev_list[e] = s;

                if (ret < cnt[e])
                {
                    ret = cnt[e];
                    lastIdx = e;
                }
            }
        }
    }
    cout << ret << '\n';
    go(lastIdx);

    return 0;
}
