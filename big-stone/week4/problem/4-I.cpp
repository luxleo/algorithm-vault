//
// Created by 이동한 on 2025. 3. 31..
//
/** 비트마스킹 덧셈, 뺄셈, 토글, 체크 이용
문제
비어있는 공집합 S가 주어졌을 때,
아래 연산을 수행하는 프로그램을 작성하시오.

add x: S에 x를 추가한다. (1 ≤ x ≤ 20)
S에 x가 이미 있는 경우에는 연산을 무시한다.
remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20)
S에 x가 없는 경우에는 연산을 무시한다.
check x: S에 x가 있으면 1을,
없으면 0을 출력한다. (1 ≤ x ≤ 20)
toggle x: S에 x가 있으면 x를 제거하고,
없으면 x를 추가한다. (1 ≤ x ≤ 20)
all: S를 {1, 2, ..., 20} 으로 바꾼다.
empty: S를 공집합으로 바꾼다.

입력
첫째 줄에 수행해야 하는 연산의 수 M
(1 ≤ M ≤ 3,000,000)이 주어진다.
둘째 줄부터 M개의 줄에 수행해야 하는
연산이 한 줄에 하나씩 주어진다.

출력
check 연산이 주어질때마다, 결과를 출력한다.

예제 입력 1
26
add 1
add 2
check 1
check 2
check 3
remove 2
check 1
check 2
toggle 3
check 1
check 2
check 3
check 4
all
check 10
check 20
toggle 10
remove 20
check 10
check 20
empty
check 1
toggle 1
check 1
toggle 1
check 1

예제 출력 1
1
1
0
1
0
1
0
1
0
1
1
0
0
0
1
0
 * @see
 */
#include <bits/stdc++.h>
using namespace std;

int M,bit,x;
string s;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M;
    for (int i=0; i<M; i++) {
        cin >> s;
        if (s == "all") bit = (1 << 21) - 1; // (0) 111111...11(20)
        else if (s == "empty") bit=0; // (1) 비우기
        else {
            cin >> x;
            if (s[0] == 'a') bit |= (1 << x); // (2) 비트 덧셈 ( 불리언 배열 true)
            else if (s[0] == 'r') bit &= ~(1 << x); // (3) 비트 제거
            else if (s[0] == 'c') cout << ((bit & (1 << x)) ? "1" : "0") << "\n"; //
            else if (s[0] == 't') bit ^= (1 << x); // (4) 토글
        }
    }
    return 0;
}
