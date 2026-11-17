//
// Created by 5600G on 2026-11-17.
//
#include <bits/stdc++.h>
using namespace std;

bool che[4000001];      // 에라토스테네스의 체 배열 (false: 소수, true: 합성수)
int n;                  // 목표 자연수 N (1 <= N <= 4,000,000)
int a[2000001];         // N 이하의 소수들을 오름차순으로 저장할 배열 (400만 이하 소수는 약 28만 개)
int p;                  // 찾은 소수의 총개수
int lo, hi;             // 투 포인터: 현재 연속 구간의 시작(lo)과 끝 다음 위치(hi)
int ret;                // 답: 연속된 소수의 합으로 N을 나타내는 경우의 수
int sum;                // 현재 구간 a[lo ... hi-1]의 누적 합

int main(){
    // 1. 목표 자연수 N 입력
    scanf("%d", &n);

    // 2. [1단계: 에라토스테네스의 체] 2부터 n까지의 소수 판별
    for(int i = 2; i <= n; i++){
        if(che[i]) continue;            // 이미 합성수로 판별된 수는 건너뜀
        for(int j = 2 * i; j <= n; j += i){
            che[j] = 1;                 // i의 배수들을 합성수(true)로 표시
        }
    }

    // 판별된 소수들만 배열 a에 순서대로 저장
    for(int i = 2; i <= n; i++){
        if(!che[i]) a[p++] = i;
    }

    // 3. [2단계: 투 포인터] 연속된 소수 구간의 합이 n이 되는 경우 탐색
    while(1){
        // 현재 합이 n 이상이면 왼쪽 끝(a[lo])을 빼서 구간 축소
        if(sum >= n) {
            sum -= a[lo++];
        }
        // 합이 n보다 작은 상태에서 오른쪽 포인터가 끝(p)에 도달하면 더 이상 합을 키울 수 없으므로 종료
        else if(hi == p) {
            break;
        }
        // 현재 합이 n보다 작으면 오른쪽 끝(a[hi])을 더해 구간 확장
        else {
            sum += a[hi++];
        }

        // 구간 조정 후 누적 합이 정확히 n과 같다면 경우의 수 증가
        if(sum == n) ret++;
    }

    // 4. 결과 출력
    printf("%d\n", ret);
    return 0;
}