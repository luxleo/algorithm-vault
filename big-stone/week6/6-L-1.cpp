#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 연속된 부분 수열 중 곱이 최대가 되는 값을 찾아 반환하는 함수 (시간 복잡도: O(N^2))
 * @param nums 입력받은 N개의 실수 벡터 (복사 비용을 아끼기 위해 const 참조자로 전달)
 * @return 연속 부분 수열 곱의 최댓값
 */
double go(const vector<double>& nums) {
    int n = nums.size();
    
    // 답을 저장할 최댓값 변수 (모든 입력이 0.0 이상이므로 매우 작은 음수로 초기화)
    double mx = -1e9;
    
    // 1. 부분 수열의 시작 인덱스(start)를 0부터 n-1까지 하나씩 고정
    for (int start = 0; start < n; start++) {
        // 곱셈의 항등원인 1.0으로 현재 구간의 누적 곱 초기화
        double curr = 1.0;
        
        // 2. 시작점(start)부터 끝점(end)을 오른쪽으로 한 칸씩 확장하며 누적 곱 계산
        for (int end = start; end < n; end++) {
            curr *= nums[end];      // 직전까지의 곱에 현재 원소 nums[end]를 추가로 곱함
            mx = max(mx, curr);     // 한 개 이상의 연속된 수이므로 매 단계마다 최댓값 갱신
        }
    }
    return mx;
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. 실수의 개수 N 입력
    int n;
    cin >> n;

    // 2. N개의 실수 입력
    vector<double> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // 3. 연속 부분 최대 곱 계산
    double ret = go(nums);
    
    // 4. 소수점 이하 넷째 자리에서 반올림하여 셋째 자리까지 고정 출력
    cout << fixed << setprecision(3) << ret << '\n';

    return 0;
}