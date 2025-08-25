//
// Created by 이동한 on 2025. 8. 25..
//
/** S3 투포인터-타겟이 되는 합 구하기 [3273](https://www.acmicpc.net/problem/3273)
 * 투포인터 + 타겟합 구하기
 */
#include <bits/stdc++.h>
using namespace std;
int ret, N, X;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    vector<int> v(N); // 벡터의 크기를 동적으로 정해준다.
    for (int i = 0; i < N; i++) {
        // 마찬가지로 띄어쓰기가 있는 입력값 cin으로 받는 방법.
        cin >> v[i];
    }
    cin >> X;
    sort(v.begin(), v.end());
    // 정렬된 배열에서 타겟이 되는 합을 만족하는 두수를 뽑는 문제이다.
    // 이런 문제는 투포인터가 제격임.
    int l = 0, r = N - 1;
    while (l < r) {
        // 두수의 합에 따라 갱신 조건 구현
        int curSum = v[l] + v[r];
        if (curSum == X) {
            r--;
            ret++;
        } else if (curSum > X) r--;
        else l++;
    }
    cout << ret << endl;
    return 0;
}
