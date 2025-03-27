//
// Created by 이동한 on 2025. 3. 25..
//
/**
문제
남극에 사는 김지민 선생님은 학생들이 되도록이면 많은 단어를
읽을 수 있도록 하려고 한다. 그러나 지구온난화로 인해
얼음이 녹아서 곧 학교가 무너지기 때문에, 김지민은
K개의 글자를 가르칠 시간 밖에 없다. 김지민이 가르치고
난 후에는, 학생들은 그 K개의 글자로만 이루어진 단어만을
읽을 수 있다. 김지민은 어떤 K개의 글자를 가르쳐야 학생들이
읽을 수 있는 단어의 개수가 최대가 되는지 고민에 빠졌다.

남극언어의 모든 단어는 "anta"로 시작되고, "tica"로 끝난다.
남극언어에 단어는 N개 밖에 없다고 가정한다. 학생들이 읽을 수
있는 단어의 최댓값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 단어의 개수 N과 K가 주어진다. N은 50보다 작거나
같은 자연수이고, K는 26보다 작거나 같은 자연수 또는 0이다.
둘째 줄부터 N개의 줄에 남극 언어의 단어가 주어진다.
단어는 영어 소문자로만 이루어져 있고, 길이가 8보다 크거나 같고,
15보다 작거나 같다. 모든 단어는 중복되지 않는다.

출력
첫째 줄에 김지민이 K개의 글자를 가르칠 때, 학생들이
읽을 수 있는 단어 개수의 최댓값을 출력한다.

예제 입력 1
3 6
antarctica
antahellotica
antacartica
예제 출력 1
2
 * @see https://www.acmicpc.net/problem/1062
 */
#include <bits/stdc++.h>
using namespace std;
int N,K;
int words[51]; // 비트 마스킹으로 나타내는 불리언 배열
string s;
int count(int bit) {
    int cnt = 0;
    for (int i=0; i<N; i++)
        if ((words[i] & bit) == words[i]) cnt++;
    return cnt;
}
int go(int index, int cnt, int bit) {
    if (cnt < 0) return 0;
    if (index == 26) return count(bit);
    int ret = go(index+1, cnt-1, bit | (1 << index)); // 현재 인덱스를 포함시킨 경우로 시작
    if (index != 'a'-'a' && index != 'n'-'a' && index != 't'-'a' && index != 'i'-'a' && index != 'c'-'a')
        ret = max(ret, go(index+1, cnt, bit));
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for (int i=0; i<N; i++) {
        cin >> s;
        for (char str: s)
            // 해당 단어에 사용된 알파벳 비트마스킹 이용하여 불리언 처리진행
            words[i] |= (1 << (str - 'a'));
    }
    cout << go(0,K,0) << "\n";
    return 0;
}
