//
// Created by 5600G on 2026-11-12.
//


#include <bits/stdc++.h>
using namespace std;

const int MAXN = 51;
int N,K, words[MAXN];
string s;

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int count(int mask)
{
    int cnt = 0;
    for (int word : words)
    {
        if (word && (word & mask) == word) cnt++;
    }
    return cnt;
}

int go(int here, int k, int mask)
{
    if (k<0) return 0;
    if (here == 26) return count(mask);
    // 현재 인덱스에 해당하는 알파벳 가르치는 경우
    int ret = go(here + 1, k - 1, mask | (1 << here));
    // a,n,t,i,c 는 무조건 가르쳐야 하는 단어이므로 이외의 단어라면 가르치지 않는 경우를 카운트한다
    if (here != 'a' - 'a' && here != 'n' - 'a' && here != 't' - 'a' && here != 'i' - 'a' && here != 'c' - 'a')
        ret = max(ret, go(here + 1, k, mask));
    return ret;
}

int main()
{
    cin >> N >> K;
    for (int i=0; i<N; i++)
    {
        cin >> s;
        for (char c:s)
            words[i] |= (1 << (c - 'a')); // 단어에 해당하는 비트 켜준다
    }
    cout << go(0,K,0) << '\n';

    return 0;
}
