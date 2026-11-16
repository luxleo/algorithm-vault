#include <bits/stdc++.h>
using namespace std;

typedef long long ll; // 정답(쌍의 수)이 int 범위(약 21억)를 넘을 수 있으므로 long long 사용

ll n;       // 줄을 선 사람의 수 N (최대 500,000)
ll ret;     // 답: 서로 볼 수 있는 쌍의 총 개수
ll temp;    // 현재 순서에 들어오는 사람의 키

// 스택 원소: {사람의 키, 같은 키로 연속해서 묶인 사람 수}
// 스택 내부는 항상 바닥에서 꼭대기로 갈수록 키가 엄격히 작아지는(내림차순) 상태를 유지함
stack<pair<ll, ll>> s; 

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. 사람 수 입력
    cin >> n;  
    
    // 2. N명의 사람을 한 명씩 차례대로 확인
    for(int i = 0; i < n; i++){
        cin >> temp; // 현재 사람의 키 입력
        
        // cnt: 현재 사람(temp)과 키가 같아서 하나로 묶일 사람의 수 (자기 자신 1명으로 시작)
        int cnt = 1; 
        
        // 3. 스택의 맨 위 사람이 현재 사람(temp)보다 키가 작거나 같다면 반복
        // 이유: temp보다 작거나 같은 앞사람은 temp와 마주 볼 수 있고,
        //       작은 사람의 경우 temp에게 가려져 뒷사람과는 더 이상 볼 수 없으므로 스택에서 제거함
        while(s.size() && s.top().first <= temp){
            // 스택 맨 위에 묶여 있던 사람들(s.top().second명) 모두 현재 사람(temp)과 마주 볼 수 있음
            ret += s.top().second; 
            
            // 만약 앞사람과 현재 사람의 키가 정확히 같다면?
            if(s.top().first == temp){ 
                // 기존에 묶여 있던 인원수에 현재 사람(1명)을 합쳐서 하나로 압축
                cnt = s.top().second + 1;  
            } else {  
                // 앞사람이 현재 사람보다 키가 작았던 경우, 현재 사람의 연속 카운트는 1 유지
                cnt = 1; 
            }
            
            // 처리가 끝난 앞사람(들)을 스택에서 제거
            s.pop(); 
        }
        
        // 4. 작거나 같은 사람을 다 꺼낸 뒤에도 스택에 사람이 남아있다면?
        // 스택 맨 위(s.top())에는 현재 사람(temp)보다 키가 큰 '가장 가까운 앞사람'이 있음
        // 이 사람 1명과는 중간에 가리는 사람이 없으므로 서로 볼 수 있음!
        if(s.size()) ret++;
        
        // 5. 현재 사람의 {키, 묶인 인원수}를 스택에 추가
        s.push({temp, cnt});
    }
    
    // 6. 서로 볼 수 있는 총 쌍의 수 출력
    cout << ret << '\n';
    return 0;
}