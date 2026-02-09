//
// Created by 5600G on 2026-02-09.
//

/** @see https://www.acmicpc.net/problem/11658
 * 펜윅트리 동적배열을 2차원으로 확장하였다.
 * 주의할 점은 내부 while 문 의 경우 넘겨받은 인덱스로 연산하면 업데이트 되기 때문에 항상 지역변수로 초기화하여 시작해야한다.
 * 마찬가지로 펜윅트리 업데이트 로직 호출 시 동적배열 은 (newVal - oldVal) 차이 만큼만 업데이트 하고 데이터는 통째로 변경해준다.
 */
#include <bits/stdc++.h>
using namespace  std;
#define MAX_N 1025
int n,m;
int dat[MAX_N][MAX_N], tree[MAX_N][MAX_N];

void update(int y, int x, int val)
{
    while (y <=n)
    {
        int col = x; // x값을 그대로 이용하면 다음 루프때 업데이트 된 x로 연산하기에 오류가 된다.
        while (col <= n)
        {
            tree[y][col] += val;
            col += (col&-col);
        }
        y += (y & -y);
    }
}

int sum(int y, int x)
{
    int ret = 0;
    while (y>0)
    {
        int col=x;
        while (col>0)
        {
            ret += tree[y][col];
            col -= (col & -col);
        }
        y -= (y & -y);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            int temp;
            cin >> dat[i][j];
            update(i,j,dat[i][j]);
        }
    }

    while (m--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int y1,x1,y2,x2;
            cin >> y1 >> x1 >> y2 >> x2;
            cout << sum(y2,x2) - sum(y2,x1-1) - sum(y1-1,x2) + sum(y1-1,x1-1) << "\n";
        } else
        {
            int y,x,val;
            cin >> y >> x >> val;
            int diff = val - dat[y][x]; // 업데이트 값 - 기존값이 차이다. 자꾸 순서 반대로 한다.
            update(y,x,diff);
            dat[y][x] = val;
        }
    }
    return 0;
}
