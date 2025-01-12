//
// Created by 이동한 on 2025. 1. 12..
//

#include <bits/stdc++.h>
using namespace std;

int n,m,ret;
string a,b;
/**
 * 문제 링크
 * @see: https://www.acmicpc.net/problem/9375
 */
int main() {
    cin >> n;
    while (n--) { // (1) 한 함수 안에 여러번 수행되는 로직 구성시 while 문을 이용한다.
        cin >> m;
        map<string, int> mp;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            mp[b]++;
        }
        ret = 1;
        for (auto m : mp) {
            ret *= m.second + 1; // (2) map.second 이용하기
        }
        cout << --ret << "\n";
    }
    return 0;
}
