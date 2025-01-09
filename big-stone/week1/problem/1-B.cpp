//
// Created by 이동한 on 2025. 1. 9..
//
#include <bits/stdc++.h>
using namespace std;

int cnt[26];
string str;

/**
 * see https://www.acmicpc.net/problem/10808
 * @return 
 */
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> str;

    for (char character : str) {
        cnt[character - 'a']++;
    }

    for (int num : cnt) cout << num << " ";
    return 0;
}
