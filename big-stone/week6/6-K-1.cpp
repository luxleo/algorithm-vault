#include <bits/stdc++.h> 
using namespace std; 

int n;                      // 수열의 크기 N (최대 1,000,000)
int lis[1000004];           // lis[k]: 길이가 k+1인 증가 부분 수열의 마지막 원소 최솟값
int len;                    // 현재까지 만들어진 가장 긴 증가 부분 수열의 길이
int num;                    // 현재 입력받은 수열의 원소 값
pair<int, int> ans[1000004];// ans[i]: i번째 원소가 들어간 {lis 인덱스(_pos), 실제 값(num)} 기록
stack<int> stk;             // 역추적한 실제 LIS 원소들을 올바른 순서로 뒤집어 출력하기 위한 스택

// 수열 원소의 최댓값이 10^9 이므로, 그보다 큰 10^9 + 4를 '비어 있음(무한대)' 표시로 사용
const int INF = 1e9 + 4;

int main() {
    // 1. lis 배열 전체를 INF로 초기화 (아직 채워지지 않은 칸임을 구분하기 위함)
    fill(lis, lis + 1000004, INF);
    
    // 2. 수열의 크기 N 입력
    scanf("%d", &n);
    
    // 3. [1단계: O(N log N) LIS 길이 계산 및 위치 기록]
    for (int i = 0; i < n; i++){
        scanf("%d", &num);
        
        // 현재까지 채워진 구간 [lis, lis + len) 에서 num 이상이 처음 나오는 위치(포인터) 탐색
        auto lowerPos = lower_bound(lis, lis + len, num);
        
        // 포인터에서 시작 주소를 빼서 0부터 시작하는 정수 인덱스(_pos) 계산
        int _pos = (int)(lower_bound(lis, lis + len, num) - lis);
        
        // 가리킨 칸이 INF라는 것은 num이 기존 모든 원소보다 커서 맨 뒤에 새로 추가된다는 뜻
        if(*lowerPos == INF) len++;
        
        // 해당 위치의 값을 더 작은(또는 같은) num으로 갱신
        *lowerPos = num;  
        
        // 나중에 실제 수열을 복원하기 위해 i번째 원소가 들어간 위치와 값을 기록
        ans[i].first = _pos;
        ans[i].second = num; 
    }
    
    // 4. 가장 긴 증가 부분 수열의 최대 길이 출력
    printf("%d\n", len);
    
    // 5. [2단계: 뒤에서부터 역추적(Backtracking)하여 실제 부분 수열 복원]
    // 인덱스 (len - 1) 부터 0 까지 차례대로 짝이 맞는 원소를 뒤에서부터 찾아 스택에 삽입
    for(int i = n - 1; i >= 0; i--){
        if(ans[i].first == len - 1){
            stk.push(ans[i].second); 
            len--; // 다음으로 찾을 앞쪽 인덱스 목표로 감소
        }
    }
    
    // 6. 스택에서 꺼내며 앞에서부터 순서대로 LIS 출력
    // (백준 채점 시스템은 공백과 줄바꿈을 모두 공백 문자로 동일하게 처리하므로 %d\n도 정답 인정됨)
    while(stk.size()){
        printf("%d\n", stk.top());
        stk.pop();
    } 
    return 0;
}