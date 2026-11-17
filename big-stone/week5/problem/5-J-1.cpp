//
// Created by 5600G on 2026-11-17.
//
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101;
const int INF = 1e9;
int k;                  // 멀티탭 구멍의 개수 (문제 지문의 N, 1 <= k <= 100)
int n;                  // 전기용품 총 사용 횟수 (문제 지문의 K, 1 <= n <= 100)
int a[MAXN];             // 전기용품 사용 순서를 저장하는 배열
int visited[MAXN];       // visited[x] == 1 이면 x번 기기가 현재 멀티탭에 꽂혀 있음을 의미
int cnt;                // 답: 플러그를 뽑은 최소 횟수

vector<int> v;

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    // 입출력 속도 향상
    fastIO();

    // 1. 멀티탭 구멍 수(k)와 총 사용 횟수(n), 그리고 사용 순서 입력
    cin >> k >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    // 2. 사용 순서대로 전기용품 하나씩 확인
    for(int i = 0; i < n; i++){
        // 이미 멀티탭에 꽂혀 있는 기기라면 아무 작업 없이 통과
        if(!visited[a[i]]){

            // 멀티탭 구멍이 모두 꽉 찬 상태라면 기존 플러그 하나를 뽑아야 함
            if(v.size() == k){
                int last_idx = 0; // 현재 꽂힌 기기들 중 '가장 늦게 재사용되는 인덱스'의 최댓값
                int pos;          // 뽑아버릴 전기용품의 번호

                // 현재 멀티탭에 꽂혀 있는 모든 기기(_a)를 하나씩 검사
                for(int _a : v){
                    int here_pick = INF; // 기본값은 INF (앞으로 다시 안 쓰인다고 가정)

                    // 현재 시점 다음(i + 1)부터 끝까지 훑으며 _a가 언제 다시 등장하는지 탐색
                    for(int j = i + 1; j < n; j++){
                        if(_a == a[j]){
                            here_pick = j; // 가장 먼저 다시 쓰이는 시점을 찾으면 기록 후 즉시 종료
                            break;
                        }
                    }

                    // 더 나중에 쓰이거나(또는 아예 안 쓰이는 INF) 기기를 발견하면 교체 후보로 갱신
                    if(last_idx < here_pick){
                        last_idx = here_pick;
                        pos = _a;
                    }
                }

                // 결정된 기기(pos)의 플러그를 뽑고 횟수 증가
                visited[pos] = 0;
                cnt++;
                v.erase(find(v.begin(), v.end(), pos));
            }

            // 빈 구멍에 새로운 전기용품 a[i]를 꽂음
            v.push_back(a[i]);
            visited[a[i]] = 1;
        }
    }

    // 3. 플러그를 뽑은 최소 횟수 출력
    cout << cnt << "\n";
    return 0;
}