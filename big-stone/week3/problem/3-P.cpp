//
// Created by 이동한 on 2025. 2. 23..
//
/** 전체 경우의 수 카운트 해보기 == 100C3 이었음 == 100*99*98 / 3*2*1 이므로 완전탐색 가능한 범위이다.
 *
문제
2017년 4월 5일 식목일을 맞이한 진아는
나무를 심는 대신 하이테크관 앞 화단에 꽃을
심어 등교할 때 마다 꽃길을 걷고 싶었다.

진아가 가진 꽃의 씨앗은 꽃을 심고나면
정확히 1년후에 꽃이 피므로 진아는
다음해 식목일 부터 꽃길을 걸을 수 있다.

하지만 진아에게는 꽃의 씨앗이 세개밖에
없었으므로 세 개의 꽃이 하나도 죽지
않고 1년후에 꽃잎이 만개하길 원한다.

꽃밭은 N*N의 격자 모양이고 진아는 씨앗을
(1,1)~(N,N)의 지점 중 한곳에 심을 수 있다.
꽃의 씨앗은 그림 (a)처럼 심어지며
1년 후 꽃이 피면 그림 (b)모양이 된다.

꽃을 심을 때는 주의할 점이있다.
어떤 씨앗이 꽃이 핀 뒤 다른 꽃잎(혹은 꽃술)과
닿게 될 경우 두 꽃 모두 죽어버린다.
또 화단 밖으로 꽃잎이 나가게 된다면
그 꽃은 죽어버리고 만다.

그림(c)는 세 꽃이 정상적으로
핀 모양이고 그림(d)는 두 꽃이 죽어버린 모양이다.

하이테크 앞 화단의 대여 가격은 격자의
한 점마다 다르기 때문에 진아는 서로 다른 세 씨앗을
모두 꽃이 피게하면서 가장 싼 가격에 화단을 대여하고 싶다.

단 화단을 대여할 때는 꽃잎이 핀 모양을 기준으로
대여를 해야하므로 꽃 하나당 5평의 땅을 대여해야만 한다.
돈이 많지 않은 진아를 위하여 진아가
꽃을 심기 위해 필요한 최소비용을 구해주자!

입력
입력의 첫째 줄에 화단의 한 변의 길이 N(6≤N≤10)이 들어온다.

이후 N개의 줄에 N개씩 화단의 지점당 가격(0≤G≤200)이 주어진다.

출력
꽃을 심기 위한 최소 비용을 출력한다.

예제 입력 1
6
1 0 2 3 3 4
1 1 1 1 1 1
0 0 1 1 1 1
3 9 9 0 1 99
9 11 3 1 0 3
12 3 0 0 0 1
예제 출력 1
12
 * @see https://www.acmicpc.net/problem/14620
 */
#include <bits/stdc++.h>
using namespace std;
int arr[11][11],vst[11][11],N,ret = 987654321; // 최소값 찾을떄는 최대에서 시작
const int dy[] = {-1,1,0,0};
const int dx[] = {0,0,-1,1};

void unseed(int y,int x) {
    vst[y][x] = 0;
    for (int i=0; i<4; i++) {
        int ny = y+dy[i];
        int nx = x+dx[i];
        vst[ny][nx] = 0;
    }
}
int seed(int y, int x) {
    int localCost = arr[y][x];
    vst[y][x] = 1;
    for (int i=0; i<4; i++) {
        int ny = y+dy[i];
        int nx = x+dx[i];
        vst[ny][nx] = 1;
        localCost += arr[ny][nx];
    }
    return localCost;
}
bool check(int y, int x) {
    if (vst[y][x]) return false;
    for (int i=0; i<4; i++) {
        int ny = y+dy[i];
        int nx = x+dx[i];
        if (ny <0 || ny >=N || nx <0 || nx >= N || vst[ny][nx]) return false;
    }
    return true;
}

/**
 * 조합을 완전탐색으로 진행할 때 재귀로 구현. 탈출조건과 누적합과 함께 구현함.
 * @param cnt 탈출조건이자 현재까지 진행한 조합의 갯수
 * @param acc 조합이 진행되며 갱신되는 누적합
 */
void go(int cnt, int acc) {
    if (cnt == 3) {
        ret = min(ret,acc);
        return;
    }
    for (int i=0; i<N; i++) {
        for (int j =0; j<N; j++) {
            if (check(i,j)) {
                go(cnt+1, acc + seed(i,j));
                unseed(i,j);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i =0; i<N; i++) {
        for (int j =0; j<N; j++) {
            cin >> arr[i][j];
        }
    }
    go(0,0);
    cout << ret << "\n";
    return 0;
}
