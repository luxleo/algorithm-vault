//
// Created by 이동한 on 2025. 8. 28..
//
/** G1 [1700](https://www.acmicpc.net/problem/1700)
 * 메모리 할당 최적화 알고리즘을 떠올려야햇다.
 * 아이디어는 가장 변경 가능성이 적은 후순위로 오는 요소를
 * 가장 우선적으로 뽑아 버리는게 좋다.
 */
#include <bits/stdc++.h>
using namespace std;
int k, n, vst[104], a[104], cnt;
const int INF = 987654321;
vector<int> v; // k 크기의 콘센트

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> k >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        if (!vst[a[i]]) {
            if (v.size() == k) {
                // 현재의 가전기구가 콘센트에 꼽혀있지 않는 경우인데 콘센트가 다 차버린 경우 뺼 요소를 고른다.
                // 이떄 unplug할 요소를 정하는 기준은 가장 나중에 들어오는 순서를 가진 요소이다.
                int farthest_idx = 0, pos;
                for (int cur: v) {
                    int temp_idx = INF;
                    for (int j = i + 1; j < n; j++) {
                        if (cur == a[j]) {
                            // 현재 인덱스에서 멀리 떨어질 수록 변경 가능성이 적으므로
                            // 변경 대상으로잡는다.
                            temp_idx = j;
                            break;
                        }
                    }
                    if (farthest_idx < temp_idx) {
                        farthest_idx = temp_idx;
                        pos = cur;
                    }
                }

                // 현재 콘센트에 연결된 요소중 가장 후에 들어오는
                // 요소를 빼준다 unplug!!
                vst[pos] = 0;
                cnt++;
                v.erase(find(v.begin(), v.end(), pos));
            }
            // 현재 탐색중인 요소를 plug 처리
            v.emplace_back(a[i]);
            vst[a[i]] = 1;
        }
    }
    cout << cnt << endl;
    return 0;
}
