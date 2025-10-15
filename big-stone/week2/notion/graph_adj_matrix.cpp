/** 인접행렬
 * 그래프 표현 방식 중 하나이다.
 * 순회하는 방법을 알아본다.
 *
 * 인접행렬의 원소가 나타내는것은 [from][to]의 노드간 연결 상태 이므로
 * 이중순회문으로 각 노드로 부터 탐색 알고리즘을 적용시켜야한다.
 */
#include <bits/stdc++.h>
using namespace std;
const int V = 10;
int a[V][V], vst[V];

void go(int from)
{
    vst[from] = 1;
    cout << from << " ";
    for (int i=0; i<V; i++)
    {
        if (vst[i]) continue;
        if (a[from][i]) go(i);
    }
}

int main()
{
    a[1][2] = 1; a[1][3] = 1; a[3][4] = 1;
    a[2][1] = 1; a[3][1] = 1; a[4][3] = 1;
    for (int i=0; i<V; i++)
    {
        for (int j=0; j<V; j++)
        {
            if (!vst[i] && a[i][j]) go(i);
        }
    }
    return 0;
}
