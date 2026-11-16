//
// Created by 5600G on 2026-11-12.
//
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101;
int N,L,mp[MAXN][MAXN],tmp[MAXN][MAXN],ret;

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// 의문 : 이렇게 되면 a 는 배열 전체를 복사하여 전달 되나 아니면 참조값이 전달 되나
void solve(int a[MAXN][MAXN])
{
    for (int i=0; i<N; i++)
    {
        int cnt = 1; // 지금까지 연속한 평지 개수 카운트, 현재 발판 부터 카운트 하므로 초기값은 1
        int j;
        // 다음 칸과 비교하므로 N-1까지 탐색한다
        for (j=0; j<N-1; j++)
        {
            if (a[i][j] == a[i][j+1])
                cnt++; // 같은 높이면 평지 개수 증가시킴
            else if (a[i][j] + 1 == a[i][j+1] && cnt >=L)
            {
                cnt = 1;
            }
            // 내리막이 한 칸 낮은 경우 cnt >=0 이상이어야 이전에 설치하려던 내리막이 끝나기전에 새로운 내리막이 아님을 보장함
            else if (a[i][j] - 1 == a[i][j+1] && cnt >=0)
            {
                cnt = -L+1; // 이미 한 칸은 밟은 곳에서 시작하므로 +1 해준다
            }
            else break;
        }
        // 모든 행을 다 순회했고, 평지가 0이상이면 (내리막 때문에 0 가능) 지나갈 수 있는 길이다
        if (j == N-1 && cnt >=0) ret++;
    }
}

int main()
{
    fastIO();
    cin >> N >> L;
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
        {
            cin >> mp[i][j];
            tmp[j][i] = mp[i][j]; // 전치 행렬에 데이터 삽입 (전치 행렬을 이용하면 행과 열을 순회하는 중복로직을 작성할 필요 없이 행에 대하여 연산가능하다
        }

    solve(mp);
    solve(tmp);
    // 경사로 놓을 수 있는 곳에 다 놓고

    // 모든 행과 열을 탐색하여 지나갈 수 있는 길 카운트 하고 반환한다
    cout << ret << '\n';
    return 0;
}
