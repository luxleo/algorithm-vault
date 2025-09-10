//
// Created by 이동한 on 2025. 9. 10..
//
/** G1
 * 관건은 상어의 움직임을 한칸씩 움직이지 않는 것이다.
 * 한칸씩 움직인다면 타임오버 발생한다.
 * 모듈러 연산을 통하여 직접 움직인 효과와 동일하게 처리하는 것이 중요했다.
 * 단순히 맵의 길이로 나누는 것이 아니라 맵의 길이 * 2 로 모듈러 연산을 하여 왕복을 단위로 계산한다.
 *
 * 또한 벽에 반사 되는 효과를 나타내기 위해 ^= 연산을 통해 바로 뒤집어 주었다. 물론 dy,dx도 이에 맞게 설정한다.
 */
#include <bits/stdc++.h>
using namespace std;
const int max_n = 100;

struct Shark {
    int y, x, s, dir, z, dead;
} a[max_n * max_n];

const int dx[] = {0, 0, 1, -1};
const int dy[] = {-1, 1, 0, 0};
int shark[max_n][max_n], R, C, M, ret, temp[max_n][max_n]; // temp는 상어들의 위치가 중복되는 경우르 계산하기 위함이다.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> C >> M;
    for (int i = 1; i <= M; i++) {
        // shark 배열에 상어의 위치를 인덱스로 나타낸다.
        cin >> a[i].y >> a[i].x >> a[i].s >> a[i].dir >> a[i].z;
        a[i].y--;
        a[i].x--;
        a[i].dir--;

        // 벽을 한번 왕복하는 기준으로 모듈러 연산을 진행한다.
        if (a[i].dir <= 1) {
            // 방향이 위 아래로 움직이는 경우
            a[i].s %= 2 * (R - 1);
        } else {
            // 방향이 좌우로 움직이는 경우 dir == 2, dir ==3
            a[i].s %= 2 * (C - 1);
        }
        shark[a[i].y][a[i].x] = i;
    }
    // 낚시꾼이 시뮬레이션
    for (int x = 0; x < C; x++) {
        for (int y = 0; y < R; y++) {
            if (shark[y][x]) {
                // 이 조건문 때문에 상어의 인덱스를 1부터 시작함
                a[shark[y][x]].dead = 1; // 상어 죽음 처리
                ret += a[shark[y][x]].z;
                shark[y][x] = 0;
                break;
            }
        }
        memset(temp, 0, sizeof(temp)); // 배열 전체 초기화할떄 사용
        for (int i = 1; i <= M; i++) {
            if (a[i].dead) continue;

            int iy = a[i].y;
            int ix = a[i].x;
            int s = a[i].s;
            int d = a[i].dir;
            int ny, nx;

            while (1) {
                ny = iy + s * dy[d];
                nx = ix + s * dx[d];
                if (nx < C && ny < R && ny >= 0 && nx >= 0) break; // 반사되는 범위가 아니면 break;
                if (d <= 1) {
                    // 상하로 움직일때
                    if (ny < 0) {
                        s -= iy; // 속도에서 움직인 거리를 제하여 다음 while문 으로 갱신해준다.
                        iy = 0; // 초기 y의 위치도 변경해준다.
                    } else {
                        s -= R - 1 - iy;
                        iy = R - 1;
                    }
                } else {
                    // 좌우로 움직일때
                    if (nx < 0) {
                        s -= ix;
                        ix = 0;
                    } else {
                        s -= C - 1 - ix;
                        ix = C - 1;
                    }
                }
                d ^= 1; // 한번 부딪힌 경우이므로 방향전환 해준다.
            }

            if (temp[ny][nx]) {
                // 상어가 같은 자리에 여러마리 몰린 경우 가장 큰놈만 살려둔다.
                if (a[temp[ny][nx]].z < a[i].z) {
                    a[temp[ny][nx]].dead = 1;
                    temp[ny][nx] = i;
                } else {
                    a[i].dead = 1;
                }
            } else {
                temp[ny][nx] = i;
            }

            // 상어 위치 갱신
            a[i].y = ny;
            a[i].x = nx;
            a[i].dir = d;
        }
        memcpy(shark, temp, sizeof(temp));
    }
    cout << ret << endl;
    return 0;
}
