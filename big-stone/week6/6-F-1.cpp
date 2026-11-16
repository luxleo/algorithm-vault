//
// Created by 이동한 on 2026. 11. 15..
//
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 123457;
ll n, atk, t[MAXN], a[MAXN], h[MAXN], lo, hi, ret;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool check(ll mid) {
    ll mxHP = mid;
    ll init_atk = atk;
    for (int i = 0; i < n; i++) {
        if (t[i] == 2) {
            mid = min(mxHP, mid + h[i]);
            init_atk += a[i];
        } else {
            ll cnt = h[i] / init_atk + (h[i] % init_atk == 0 ? 0 : 1);
            mid -= (cnt - 1) * a[i]; // 용사가 먼저 공격하기 때문에
        }
        if (mid <= 0) return false;
    }
    return true;
}

int main() {
    fastIO();
    cin >> n >> atk;
    for (int i = 0; i < n; i++)
        cin >> t[i] >> a[i] >> h[i];

    lo = 1;
    hi = 1e18 + 1;

    while (lo <= hi) {
        ll mid = (lo + hi) >> 1;
        if (check(mid)) {
            hi = mid - 1;
            ret = mid;
        } else lo = mid + 1;
    }

    cout << ret << '\n';
    return 0;
}
