/** S4 @see https://www.acmicpc.net/problem/2670
 * bruteForce 이용시 모든 가능한 곱셈 구간을 직접 만든다. (0-1,0-2,0-3 ... 1-2,1-3 ... )
 * optimized 이용시 O(n) 으로 갱신할지 새로 할당할지 선택한다.
 */
#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------------------------------------
// [1] Brute-force O(n^2) approach
// -----------------------------------------------------------------------------
double bruteForce(const vector<double> &nums) {
    int n = nums.size();
    double mx = -1e9; // very small initial value

    for (int start = 0; start < n; start++) {
        double curr = 1.0;
        for (int end = start; end < n; end++) {
            curr *= nums[end];
            mx = max(mx, curr);
        }
    }
    return mx;
}

// -----------------------------------------------------------------------------
// [2] Optimized O(n) approach (Dynamic Programming style)
// -----------------------------------------------------------------------------
double optimized(const vector<double> &nums) {
    int n = nums.size();
    if (n == 0) return 0.0;

    double b = nums[0];
    double ret = b;

    for (int i = 1; i < n; i++) {
        // either start new product from nums[i], or extend previous product
        if (nums[i] > b * nums[i]) b = nums[i];
        else b *= nums[i];
        ret = max(ret, b);
    }

    return ret;
}

// -----------------------------------------------------------------------------
// [3] Main Function - client can choose algorithm
// -----------------------------------------------------------------------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<double> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    double ret;
    // ret = bruteForce(nums);
    ret = optimized(nums);
    cout << fixed << setprecision(3) << ret << "\n";
    return 0;
}
