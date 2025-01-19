//
// Created by 이동한 on 2025. 1. 20..
//
#include <bits/stdc++.h>
using namespace std;

int n,c,temp;
vector<pair<int, int >> v;
map<int ,int> mp_freq,mp_idx;

/**
 * 커스텀 comparator 작성하기
 * @param a
 * @param b
 * @return
 */
bool cmp (pair<int , int >a , pair<int,int> b) {
    if (a.second ==  b.second) {
        // 빈도수가 같은 경우 인덱스가 작은 녀석을 기준으로 정렬
        return mp_idx[a.first] < mp_idx[b.first];
    }
    // 빈도수가 큰녀석을 기준으로 정렬
    return a.second > b.second;
}

/**
위대한 해커 창영이는 모든 암호를 깨는 방법을 발견했다. 그 방법은 빈도를 조사하는 것이다.
창영이는 말할 수 없는 방법을 이용해서 현우가 강산이에게 보내는 메시지를 획득했다. 이 메시지는 숫자 N개로 이루어진 수열이고, 숫자는 모두 C보다 작거나 같다.
창영이는 이 숫자를 자주 등장하는 빈도순대로 정렬하려고 한다.
만약, 수열의 두 수 X와 Y가 있을 때, X가 Y보다 수열에서 많이 등장하는 경우에는 X가 Y보다 앞에 있어야 한다.
만약, 등장하는 횟수가 같다면, 먼저 나온 것이 앞에 있어야 한다.
이렇게 정렬하는 방법을 빈도 정렬이라고 한다.
수열이 주어졌을 때, 빈도 정렬을 하는 프로그램을 작성하시오.

입력
첫째 줄에 메시지의 길이 N과 C가 주어진다. (1 ≤ N ≤ 1,000, 1 ≤ C ≤ 1,000,000,000)
둘째 줄에 메시지 수열이 주어진다.

출력
첫째 줄에 입력으로 주어진 수열을 빈도 정렬한 다음 출력한다.

예제 입력 1     예제 출력 1
5 2
2 1 2 1 2     2 2 2 1 1
 * 
 * @see https://www.acmicpc.net/problem/2910
 */
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> c;
    for (int i =0; i < n; i++) {
        cin >> temp;
        mp_freq[temp]++;
        if (mp_idx[temp] == 0) mp_idx[temp] = i+1;
    }

    for (auto el : mp_freq) {
        v.push_back(make_pair(el.first, el.second)); // 나타난 숫자, 빈도수
    }

    sort(v.begin(), v.end(),cmp);

    for (auto el : v) {
        for (int i=0; i< el.second; i++) {
            cout << el.first << " ";
        }
    }
    return 0;
}
