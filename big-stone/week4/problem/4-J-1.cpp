//
// Created by 5600G on 2026-11-12.
//
#include <bits/stdc++.h>
using namespace std;

int a[4][4],N,M,ret ;

int main()
{
    scanf("%d %d", &N, &M);

    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            scanf("%1d", &a[i][j]); // 연속된 정수중 정확히 하나만 입력 받는다

    // 주어진 맵에 대한 모든 비트 0부터 2**(N*M) - 1까지의 모든 부분집합을 생성
    for (int s=0; s<(1 << (N*M)); s++)
    {
        int sum = 0;

        // 행 방향으로 훑는다 N -> M
        for (int i=0; i<N; i++)
        {
            int cur = 0;
            for (int j=0; j<M; j++)
            {
                int here = i*M + j; // 2차원 좌표를 1차원으로 인코딩
                if ((s & (1 << here)) == 0) // here 가 0으로 되어 있는 경우 즉 칸이 0 그룹(가로)에 속한 경우이다
                {
                    cur = cur * 10 + a[i][j]; // 현재 칸에 있는 수를 이어 붙인다
                } else
                {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur; // 나머지 처리
        }

        // 열 방향으로 훑는다 M -> N
        for (int j=0; j<M; j++)
        {
            int cur = 0;
            for (int i=0; i<N; i++)
            {
                int here = i*M + j;
                // if ((s & (1 << here)) == 1) 으로 하면 안된다 이유는 '(s & (1 << here)) 의 결과는 1,2,4,8 등 으로 구성되기 때문이다
                if ((s & (1 << here)) != 0) // here 가 1로 되어 있는 경우 즉 칸이 1 그룹(세로)에 속한 경우이다
                {
                    cur = cur * 10 + a[i][j];
                } else
                {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur; // 나머지 처리
        }
        ret = max(ret, sum);
    }

    printf("%d\n", ret);

    return 0;
}
