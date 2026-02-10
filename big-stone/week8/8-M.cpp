//
// Created by 이동한 on 2026. 2. 9..
//


#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// n: 세로, m: 가로, T: 최대 허용 높이차, D: 제한 시간, ret: 결과값(최대 높이) ,3000 이 되는 이유는 좌표 압축을 위해 * 100 을 수행하기 때문
int n, m, T, D, a[30][30], b[3000][3000], ret;
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,1,-1};
vector<int> v; // 압축된 좌표 인덱스 저장
string s;

/** @see https://www.acmicpc.net/problem/1486
 * 좌표압축 (2->1차원)
 * 탐색 구현
 * @return
 */
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> T >> D;

    // 산 높이 받아내기
    for (int i=0;i<n; i++)
    {
        cin >> s;
        for (int j=0; j<m; j++)
        {
            if (s[j] >= 'a') a[i][j] = s[j] - 'a' + 26;
            else a[i][j] = s[j] - 'A';
        }
    }

    ret = a[0][0]; // 결과 초기값은 출발 위치이다.

    // 좌표압축
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) v.emplace_back(i * 100 + j);

    // 모든 정점 사이 거리 초기화
    fill(&b[0][0], &b[0][0] + 3000 * 3000, INF);
    for (int node : v) b[node][node] = 0;

    // 이동 시작
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            for (int d = 0; d<4; d++)
            {
                int ny = i + dy[d];
                int nx = j + dx[d];

                if (ny >= n || nx >= m || ny<0 || nx<0) continue;

                // 높이차가 T 미만일때만 이동
                int height_diff = abs(a[ny][nx] - a[i][j]);
                if (height_diff <= T)
                {
                    if(a[ny][nx] > a[i][j]) {
                        // 더 높은 곳으로 갈 때: (높이차의 제곱)초 소요
                        b[i * 100 + j][ny * 100 + nx] = height_diff * height_diff;
                    } else {
                        // 낮거나 같은 곳으로 갈 때: 1초 소요
                        b[i * 100 + j][ny * 100 + nx] = 1;
                    }
                }
            }
        }
    }

    // 최단거리 갱신시 경유 노드를 가장 바깥으로 뺴야한다.
    for (int k : v)
    {
        for (int i : v)
        {
            for (int j : v)
            {
                b[i][j] = min(b[i][j], b[i][k] + b[k][j]);
            }
        }
    }

    // 5. 결과 도출: 호텔(0,0)에서 출발해 j까지 갔다가 돌아올 수 있는지 확인
    for(int j : v) {
        // b[0][j]: 호텔 -> j 이동 시간
        // b[j][0]: j -> 호텔 이동 시간
        // 왕복 시간이 D 이내라면
        if(b[0][j] != INF && b[j][0] != INF && D >= b[0][j] + b[j][0]) {
            // 해당 지점의 높이와 현재까지의 최대 높이를 비교하여 갱신
            ret = max(ret, a[j / 100][j % 100]);
        }
    }

    cout << ret << "\n"; // 최종 최대 높이 출력

    return 0;
}
