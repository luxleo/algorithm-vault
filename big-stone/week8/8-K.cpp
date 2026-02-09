//
// Created by 5600G on 2026-02-09.
//

/** @see https://www.acmicpc.net/problem/2042
 * 펜윅 트리 문제의 전형이었다.
 * 수가 바뀌면 그 수 자체를 동적 배열에서 바꾸는게 아니라 그 차이만큼 바꾸어 주어야한다.
 * 그리고 원본 데이터는 그 자체로 바꿔 줘야한다, )ex : dat[i] = newVal, update(i, newVal - oldVal)
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, m, k;
ll a,b,c,temp;
vector<ll> dat,tree;

ll sum(ll idx)
{
    ll ret = 0;
    while (idx > 0)
    {
        ret += tree[idx];
        idx -= (idx & -idx);
    }
    return ret;
}

void update(ll idx, ll val)
{
    while (idx < tree.size())
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int main()
{   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    dat.resize(n+1);
    tree.resize(n+1);

    for (int i=0; i<n; i++)
    {
        cin >> temp;
        dat[i+1] = temp;
        update(i+1, temp);
    }

    m+=k;
    while (m--)
    {
        cin >> a;
        if (a == 1)
        {
            cin >> b >> c; // a b c 와 같이 한 줄에 입력이 다 주어져도 이렇게 받을 수 있다.
            ll diff = c- dat[b];
            dat[b] = c;
            update(b,diff);
        } else
        {
            cin >> b >> c;
            cout << sum(c) - sum(b-1) << "\n";
        }
    }

    return 0;
}
