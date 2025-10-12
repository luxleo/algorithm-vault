//
// Created by 이동한 on 2025. 10. 12..
//

/** S2 @see https://www.acmicpc.net/problem/11053
 * LIS를 trace 없이 실행할때 O(logn) , O(n**2) 방식으로 실행하는 방법이 있다.
 * O(n**2) 방법의 경우 dp 방식으로 갱신한다.
 * O(logn)의 경우 lower_bound() 함수를 이용하여 새롭게 갱신된 경우에만 카운트해준다.
 * 이때 주의할 점은 lower_bound(lis, lis+len,target)처럼 갱신되는 len을 기준으로 해주어야한다.
 * 이유는 오름차순으로 정렬하기 때문이다.
 * 만일 전체 길이 n으로 하면 정렬되어 있지 않기 때문에 오류가 발생한다.
 */
#include <bits/stdc++.h>
using namespace std;

int n, ret;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void slow() {
    int ret = 0, temp = 0, cnt[1004] = {}, mx = 0;
    // memset(cnt,  0, sizeof(cnt)); -> 해당 코드를 위의 zero initialization으로 대체할 수 있다.
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
        mx = 0;
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i] && mx < cnt[j]) mx = cnt[j];
        }
        cnt[i] = mx + 1;
        ret = max(ret, cnt[i]);
    }
    cout << ret << "\n";
}

void quick() {
    int temp = 0, len = 0, lis[1004];
    cin >> n;
    fill(lis, lis + n, 0);
    for (int i = 0; i < n; i++) {
        cin >> temp;
        auto pos = lower_bound(lis, lis + len, temp); // lis + len임에 주의하기. len까지만 정렬되어있기 때문
        if (*pos == 0) len++;
        *pos = temp;
    }
    cout << len << "\n";
}

int main() {
    fastIO();
    // quick();
    slow();

    return 0;
}
