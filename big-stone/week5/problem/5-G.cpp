//
// Created by 이동한 on 2025. 8. 24..
//

/** G3 [1633](https://www.acmicpc.net/problem/1644)
 * 에라토스테네스의 체 + 투포인터를 이용한 구간합.
 */
#include <bits/stdc++.h>
using namespace std;

bool che[4000001];
int n, a[2000001], p, lo, hi, ret, sum;

int main() {
    scanf("%d", &n);
    // ㅇㅔ라토스테네스의 체 실행
    for (int i = 2; i <= n; i++) {
        if (che[i]) continue;
        for (int j = 2 * i; j <= n; j += i) {
            che[j] = true;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (!che[i]) {
            // 소수인 경우 데이터 어레이에 넣어주기
            a[p++] = i;
        }
    }
    // 투포인터를 이용한 구간합
    while (1) {
        if (sum >= n) {
            sum -= a[lo++];
        } else if (hi == p) break;
        else sum += a[hi++];
        if (sum == n) ret++;
    }
    printf("%d\n", ret);
    return 0;
}
