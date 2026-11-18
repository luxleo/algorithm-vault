//
// Created by 5600G on 2026-11-18.
//
#include <bits/stdc++.h>
#define s second
#define f first

using namespace std;
const int INF = 987654321;

// 시계 방향 이동 순서: 0(오른쪽) -> 1(아래) -> 2(왼쪽) -> 3(위)
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int n, m, k;                    // n: 행, m: 열, k: 회전 연산 개수
int a[104][104];                // 초기 원본 배열 (절대 수정하지 않고 보존)
int b[104][104];                // 각 순열 순서마다 복사해서 실제로 회전시킬 작업용 배열
int ret = INF;                  // 답: 모든 순서 중 가장 작은 '배열의 값'
int r, c, s;                    // 회전 연산 입력용 변수 (중심 행, 중심 열, 반지름 크기)
int visited[104][104];          // 테두리 좌표를 수집할 때 한 바퀴 다 돌았는지 체크하는 배열
int dir;                        // 현재 테두리를 따라 이동 중인 방향 (0 ~ 3)
int sy, sx, ey, ex;             // 현재 회전할 정사각형 테두리의 왼쪽 위(sy, sx)와 오른쪽 아래(ey, ex)

vector<pair<int, int>> vv;      // 테두리 한 겹의 좌표들을 시계 방향으로 순서대로 담는 벡터
vector<int> v_idx;              // 회전 연산들의 실행 순서를 섞기 위한 인덱스 배열 (0, 1, ..., k-1)

// 회전 연산 정보를 저장하는 구조체
struct A{
    int y, x, cnt; // 중심 좌표 (y, x)와 테두리 겹 수 (cnt = s)
};
vector<A> v;

/**
 * @brief 정사각형 테두리의 왼쪽 위(sy, sx)에서 출발해 시계 방향으로 한 바퀴 돌며 좌표를 수집하는 재귀 함수
 */
void go(int y, int x, int first){
    // 출발 직후(first == 1)가 아닌데 네 꼭짓점 중 하나에 도착했다면 이동 방향을 90도 꺾음!
    if(!first && y == sy && x == sx) dir++;
    if(!first && y == sy && x == ex) dir++;
    if(!first && y == ey && x == ex) dir++;
    if(!first && y == ey && x == sx) dir++;

    // 현재 방향으로 한 칸 전진
    int ny = y + dy[dir];
    int nx = x + dx[dir];

    // 이미 방문한 칸(출발점)으로 돌아왔다면 한 바퀴를 다 돈 것이므로 종료
    if(visited[ny][nx]) return;

    visited[ny][nx] = 1;
    vv.push_back({ny, nx}); // 테두리 좌표 추가
    go(ny, nx, 0);          // 다음 칸으로 재귀 이동
}

/**
 * @brief 중심 (y, x) 기준으로 반지름 1부터 cnt까지 모든 정사각형 테두리를 시계 방향으로 1칸씩 회전
 */
void rotateAll(int y, int x, int cnt){
    // 안쪽 테두리(i = 1)부터 가장 바깥 테두리(i = cnt)까지 차례대로 처리
    for(int i = 1; i <= cnt; i++){
        // 현재 겹의 왼쪽 위 꼭짓점과 오른쪽 아래 꼭짓점 계산
        sy = y - 1 * i;
        sx = x - 1 * i;
        ey = y + 1 * i;
        ex = x + 1 * i;

        // 좌표 수집용 변수들 초기화
        vv.clear();
        dir = 0;
        memset(visited, 0, sizeof(visited));

        // 시작점(sy, sx)을 먼저 넣고 시계 방향으로 한 바퀴 돌며 테두리 좌표 수집
        visited[sy][sx] = 1;
        vv.push_back({sy, sx});
        go(sy, sx, 1);

        // 1. 수집된 좌표(vv)에 들어있는 실제 숫자들을 1차원 벡터(vvv)에 순서대로 복사
        vector<int> vvv;
        for(pair<int, int> c : vv) vvv.push_back(b[c.f][c.s]);

        // 2. 1차원 벡터를 오른쪽으로 1칸 회전 (맨 뒤 원소가 맨 앞으로 이동 -> 시계 방향 1칸 회전 효과!)
        rotate(vvv.rbegin(), vvv.rbegin() + 1, vvv.rend());

        // 3. 한 칸씩 밀린 숫자들을 원래 좌표 위치에 다시 덮어씀
        for(int j = 0; j < vv.size(); j++) b[vv[j].f][vv[j].s] = vvv[j];
    }
}

/**
 * @brief 현재 정해진 순서(v_idx)대로 모든 회전 연산을 수행한 뒤, 배열의 값(각 행 합 중 최솟값)을 반환
 */
int solve(){
    // 정해진 순서대로 회전 연산 실행
    for(int i : v_idx) rotateAll(v[i].y, v[i].x, v[i].cnt);

    // 각 행의 합을 구해 그중 가장 작은 값을 찾음
    int mn = INF;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < m; j++) cnt += b[i][j];
        mn = min(mn, cnt);
    }
    return mn;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. 배열 크기(n, m)와 회전 연산 개수(k), 그리고 초기 배열 입력
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    // 2. K개의 회전 연산 정보 입력 (문제는 1행 1열부터 시작하므로 r, c에서 1씩 빼서 0-based로 변환)
    for(int i = 0; i < k; i++){
        cin >> r >> c >> s;
        r--; c--;
        v.push_back({r, c, s});
        v_idx.push_back(i); // 순열 생성을 위해 0, 1, ..., k-1 인덱스 저장
    }

    // 3. next_permutation으로 회전 연산의 모든 실행 순서를 시도하며 최솟값 갱신
    do{
        memcpy(b, a, sizeof(b));    // 매 순서마다 원본 배열 a를 b에 새로 복사
        ret = min(ret, solve());    // 해당 순서로 회전했을 때의 최솟값으로 정답 갱신
    }while(next_permutation(v_idx.begin(), v_idx.end()));

    // 4. 최종 최솟값 출력
    cout << ret << "\n";
    return 0;
}