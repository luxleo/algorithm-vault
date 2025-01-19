//
// Created by 이동한 on 2025. 1. 18..
//
#include <bits/stdc++.h>
using namespace std;

int N;
char arr[64][64];
string s;
string quad(int ix, int iy, int size) {
    if (size == 1) return string(1, arr[iy][ix]);
    char cur = arr[iy][ix];
    string ret = "";
    for (int x = ix; x < ix+ size; x++) {
        for (int y = iy; y < iy + size; y++) {
            if (cur != arr[y][x]) { // (1) 재귀 들어가는 조건 + 분할 정복은 나뉘는 패턴이 고정적이어야한다. 이 경우 4등분 해서 들어간다.
                ret += "(";
                ret += quad(ix, iy, size >> 1);
                ret += quad(ix + size /2 , iy, size / 2);
                ret += quad(ix , iy + size /2, size / 2);
                ret += quad(ix + size /2 , iy + size /2, size / 2);
                ret += ")";
                return ret;
            }
        }
    }
    return string(1, cur);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s;
       for (int j = 0; j < N; j++) {
           arr[i][j] = s[j];
       }
    }
    cout << quad(0, 0, N) << "\n";
    return 0;
}
