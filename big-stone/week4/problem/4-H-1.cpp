//
// Created by 5600G on 2026-11-12.
//
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 51;
// comp[k]: k번 방의 넓이(칸 수).
int N,M, mx, vst[MAXN][MAXN], a[MAXN][MAXN],comp[MAXN*MAXN];
const int dy[] = {0, -1, 0, 1};
const int dx[] = {-1, 0, 1, 0};
struct res
{
    int room_num, max_room_size, merged_max_room_size;
} ans;

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int bfs(int iy, int ix, int label)
{
    queue<pair<int,int>> q;
    vst[iy][ix] = label;
    q.emplace(iy,ix);

    int res = 1;
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i=0; i<4; i++)
        {
            // 0(서), 1(북), 2(동), 3(남) 4방향 확인
            // (1 << i)는 각각 1(서), 2(북), 4(동), 8(남)을 의미
            // a[y][x] & (1 << i) 가 0이라는 뜻은 해당 방향에 벽이 없다는 의미!
            if (!(a[y][x] & (1 << i)))
            {
                // 벽이 없는 이웃 칸으로 이동하여 연결된 칸의 개수를 누적
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || ny >=N || nx<0 || nx>=M) continue;
                if (vst[ny][nx]) continue;
                vst[ny][nx] = label;
                res++;
                q.emplace(ny,nx);
            }
        }
    }
    return res;
}

int main()
{
    fastIO();
    cin >> M >> N;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            cin >> a[i][j];
        }
    }

    // 2. 성의 모든 칸을 순회하며 방의 개수(cnt)와 각 방의 넓이 계산
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            // 아직 방 번호가 배정되지 않은 칸을 발견하면 새로운 방 탐색 시작
            if (!vst[i][j])
            {
                ++ans.room_num;
                comp[ans.room_num] = bfs(i, j, ans.room_num);
                ans.max_room_size = max(ans.max_room_size,comp[ans.room_num]); // 가장 넓은 방의 넓이(2번 답) 갱신
            }
        }
    }

    // 3. 벽 하나를 허물었을 때 합쳐지는 두 방의 최대 넓이(3번 답) 계산
    // 모든 칸에서 '아래쪽(i+1)'과 '오른쪽(j+1)' 인접 칸만 확인하면 성 안의 모든 벽을 중복 없이 검사할 수 있
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            // [경우 1] 아래쪽 칸과 비교 (범위 내일 때)
            if (i + 1 < N)
            {
                if (vst[i][j] != vst[i+1][j])
                {
                    // 두 칸이 서로 다른 방에 속해 있다면, 사이 벽을 부수고 두 방을 합칠 수 있음
                    ans.merged_max_room_size = max(ans.merged_max_room_size,comp[vst[i][j]] + comp[vst[i+1][j]]);
                }
            }
            // [경우 2] 오른쪽 칸과 비교 (범위 내일 때)
            if (j+1 < M)
            {
                if (vst[i][j] != vst[i][j+1])
                {
                    ans.merged_max_room_size = max(ans.merged_max_room_size,comp[vst[i][j]] + comp[vst[i][j+1]]);
                }
            }
        }
    }

    cout << ans.room_num << '\n' << ans.max_room_size << '\n' << ans.merged_max_room_size << '\n';
    return 0;
}
