//
// Created by 이동한 on 2025. 1. 12..
//
#include <bits/stdc++.h>
using namespace std;

int n,m;
string s, dat[100000];
map<string, int> mp;
/**
 * map에 할당하는 방법, atoi(const *char) 이용방법.
 * 문제 링크
 * @see: https://www.acmicpc.net/problem/1620
 */
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        dat[i+1] = s;
        mp[s] = i+1; // (0) map에 []로 접근하여 할당한다.
    }
    for (int i=0; i< m; i++) {
        cin >> s;
        if (atoi(s.c_str()) == 0) { // (1)
            cout << mp[s] << "\n";
        } else cout << dat[atoi(s.c_str())] << "\n";
    }
    return 0;
}
