//
// Created by 이동한 on 2025. 8. 25..
//
/** G4 [13144](https://www.acmicpc.net/problem/13144)
 * 투포인터+ 슬라이딩 윈도우+시작인덱스로부터 생성되는 부분수열
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int s, e, N;
ll cnt[100001], arr[100001], ret;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        // 여백이 있는 입력을 받는 방법.
        scanf("%lld", arr + i); // arr는 항상 시작 주소를 참조한다. => arr + i 다음 자리에 할당
    }
    while (e < N) {
        // 슬라이딩 윈도우 끝 인덱스를 중복되는 원소 없을때 까지 확장시킨다.
        if (!cnt[arr[e]]) {
            cnt[arr[e]]++;
            e++;
        } else {
            // 중복된 원소 있는 경우 현재 시작 인덱스(s)로 부터 수열의 길이(가능한 조합의경우의 수 이므로)
            // 만큼 더해준다.
            ret += (e - s);
            // 이후 해당 시작 인덱스의 원소에 해당하는 카운트를 초기화한다.
            cnt[arr[s]]--;
            s++;
            // 이후 e 인덱스의 원소의 카운트 원소(cnt[arr[e]]) 의 값이 0이 되고 while 문
            // 종료조건 까지 돌아간다.
        }
    }
    // 아래는 최종 상태를 반영해준다. 길이가 (e-s) 만큼 남은 경우
    // 예를 들어 5의 길이 만큼 남았다면 해당 시작 인덱스(s)에서
    // 생성 가능한 부분수열은 5+4+3+2+1이다.
    ret += (ll) (e - s) * (e - s + 1) / 2; // 타입 캐스팅 해주지 않으면 틀린다.
    printf("%lld\n", ret);
    return 0;
}
