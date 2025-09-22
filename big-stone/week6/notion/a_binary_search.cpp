//
// Created by 이동한 on 2025. 9. 22..
//
/**
 * 이분탐색은 정렬된 배열에서 적용가능하다.
 * mid == (l+r)/2를 기준으로 찾는 값(T)에 따라 갱신 조건이 달라진다.
 * 1. T< mid    : r = mid -1
 * 2. T > mid   : l = mid + 1
 * 3. T == mid  : T = mid (갱신 종료)
 *
 * 또한 이분탐색을 이용하면 최적화 문제를 결정 문제로 바꿀수 있다.
 * c++의 lower_bound 또는 upper_bound 를 이용하여 구할수 있다.
 */
#include <bits/stdc++.h>
using namespace std;

int binary_search(const vector<int> &arr, int target) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) l = mid + 1;
        else if (arr[mid] > target) r = mid - 1;
    }
    return -1; // 배열에 찾는 값이 없는 경우이다.
}

int main() {
    vector<int> arr = {3, 1, 6, 9, 10, 21, 22, 30};
    sort(arr.begin(), arr.end());
    int target = 6;
    int result = binary_search(arr, target);
    if (result == -1) cout << "Not found" << endl;
    else cout << result << endl;
    return 0;
}
