//
// Created by 5600G on 2026-11-17.
//
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 100001;

ll n,s,e,cnt[MAXN], a[MAXN],ret;
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    fastIO();
    // 1. 수열의 길이 및 원소 입력
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // 2. [1단계: 투 포인터 탐색] 오른쪽 끝(e)이 수열 끝에 도달할 때까지 진행
    while(e < n){
        // 현재 원소 a[e]가 윈도우 [s, e-1] 안에 없다면 윈도우에 포함시키고 오른쪽 확장
        if(!cnt[a[e]]){
            cnt[a[e]]++;
            e++;
        }
        // a[e]가 이미 윈도우 안에 존재한다면(중복 발생), 시작점 s로 만들 수 있는 구간 개수를 정산
        else{
            ret += (e - s);     // s에서 시작해 e-1까지 뻗을 수 있는 유효 부분 수열 (e - s)개 추가
            cnt[a[s]]--;        // 윈도우에서 맨 왼쪽 원소 a[s] 제외
            s++;                // 시작 포인터를 오른쪽으로 한 칸 이동
        }
    }

    // 3. [2단계: 잔여 구간 정산] e == n이 되어 끝난 후, 남은 구간 [s, n-1] 내부의 모든 부분 수열 추가
    // 남은 원소들은 모두 중복이 없으므로 길이 L = (e - s)일 때 L*(L+1)/2개의 부분 수열이 모두 유효함
    ret += (long long)(e - s) * (e - s + 1) / 2;

    // 4. 최종 경우의 수 출력
    cout << ret << '\n';
    return 0;
}