//
// Created by 이동한 on 2025. 9. 29..
//
/** G4 @see https://www.acmicpc.net/problem/16434
 *  이분탐색으로 결정 문제 푸는 것은 항상 갱신 조건을 구하는것이 관건
 *
 *  이 문제에서 크게 눈여겨 볼것은 세가지
 *  1. t,a,h를 각 배열로 같은 idx로 서로 다른 정보 조회하기 (기존에는 pair 등으로 처리했는데 이런 방법도 있음)
 *  2. 갱신 조건 구현하기 까다 로웠음
 *  3. mxHP 최대값 정하는 기준이 중요했음
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAX_SIZE = 1e6 + 1;
ll n, atk, t[MAX_SIZE], a[MAX_SIZE], h[MAX_SIZE], ret;

bool check(ll mid) {
    ll mxHP = mid;
    ll iAtk = atk;
    // mxHP = mid 일때 모든 n개의 방 클리어 가능한지 시도
    for (int i = 0; i < n; i++) {
        if (t[i] == 2) {
            mid = min(mxHP, mid + h[i]);
            iAtk += a[i];
        } else {
            // 체력이 h[i]인 적을 iAtk 공격으로 쓰러뜨리는데 필요한 횟수
            ll cnt = h[i] / iAtk + (h[i] % iAtk ? 1 : 0);
            mid -= (cnt - 1) * a[i]; // 용사가 공격하는 횟수 동안 공격력 a[i]인 적으로 부터 받는 총피해
        }
        if (mid <= 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> atk;
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> a[i] >> h[i];
    }
    ll lo = 1, hi = 1e18 + 1; // 1e18 인 이유는 용사의 공격력이 1이고 적의 공격력이 최대인 경우이기 때문이다.
    while (lo <= hi) {
        ll mid = (lo + hi) >> 1;
        if (check(mid)) {
            // mid 가 maxHP일때 클리어가능 하므로 더 적은 값을 가지도록 갱신
            hi = mid - 1;
            ret = mid;
        } else lo = mid + 1;
    }
    cout << ret << endl;
    return 0;
}
