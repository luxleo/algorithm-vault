#include <bits/stdc++.h>
using namespace std;

int n;          // 만들고 싶은 막대의 목표 길이 (X)
int ret = 1;    // 답: 풀로 붙일 막대의 개수
// 자연수 n을 2로 계속 나누면 마지막 몫은 항상 1(이진수의 맨 앞자리 1)이므로 미리 1을 세어 둠

int main(){
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. 목표 막대 길이 입력
    cin >> n;

    // 2. n을 2진수로 변환하면서 1의 개수를 세는 과정 (마지막 몫 1이 될 때까지 반복)
    while(n != 1){
        // n & 1 : 이진수의 가장 오른쪽 끝자리 비트가 1인지 확인 (n % 2 == 1 과 같음)
        // 해당 자릿수의 막대 조각이 필요하다는 뜻이므로 카운트 증가
        if(n & 1) ret++;

        // n을 2로 나누어 다음 자릿수 비트를 확인 (n >>= 1 과 같음)
        n /= 2;
    }

    // 3. 필요한 총 막대 개수 출력
    cout << ret << '\n';
    return 0;
}