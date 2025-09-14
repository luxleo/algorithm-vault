//
// Created by 이동한 on 2025. 9. 14..
//
/** G2
 * 원형으로 된 큐 구간합 구하기
 * map 이용하여 구간합 캐싱처리하기
 *
 * pSum배열이용하여 구간합 구하기, 사이즈 두배로 늘려 원형 구간합 구하기
 */
#include <bits/stdc++.h>
using namespace std;

int S, m, n, ret;
int a[1001], psum_a[1001], b[1001], psum_b[1001];
map<int, int> aCnt, bCnt;

// 참조형 자료형 인수로 어떻게 넘기는지 보기 -> int pusm[], map<int,int> &mp
void make(int n, int psum[], map<int, int> &mp) {
    // 원형큐 구간합 구하기
    for (int interval = 1; interval <= n; interval++) {
        for (int start = interval; start <= n + interval - 1; start++) {
            int sum = psum[start] - psum[start - interval];
            mp[sum]++;
            if (interval == n) break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> S >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        psum_a[i] = psum_a[i - 1] + a[i];
    }
    // 직선으로 이어주어 원형으로 탐색하는 경우도 count한다.
    for (int i = m + 1; i <= 2 * m; i++) {
        psum_a[i] = psum_a[i - 1] + a[i - m];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        psum_b[i] = psum_b[i - 1] + b[i];
    }
    for (int i = n + 1; i <= n * 2; i++) psum_b[i] = psum_b[i - 1] + b[i - n];
    make(m, psum_a, aCnt);
    make(n, psum_b, bCnt);
    // a,b 단독에서 합을 맞추는 경우
    ret += aCnt[S] + bCnt[S];
    // a,b 조합을 통해 합을 맞추는 경우
    for (int i = 1; i < S; i++) {
        ret += aCnt[i] * bCnt[S - i];
    }
    cout << ret << endl;
    return 0;
}
