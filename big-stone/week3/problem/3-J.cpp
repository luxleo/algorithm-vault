/**
 * 
 * @see https://www.acmicpc.net/problem/14497
 */
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

char arr[301][301];
int vst[301][301];
int y,x;
const int dy[] = {-1,1,0,0};
const int dx[] = {0,0,-1,1};
queue<int> q;

int main() {
    int r,c,y1,x1,y2,x2;
    scanf("%d %d", &r,&c);
    scanf("%d %d %d %d",&y1,&x1, &y2,&x2);
    y1--; x1--; y2--; x2--;
    for (int i =0; i<r; i++) {
        scanf("%s",arr[i]); // (0) 연속한 문자열을 char 배열에 받는 방법
    }
    q.push(y1*1000 + x1); // (1) 2차원 좌표를 1차원으로 받는 방법. 단 곱하는 단위를 겹치지 않도록 잘 정해야한다.
    vst[y1][x1] = 1;
    int cnt = 0;
    //(2) flood fill(레이어 단위로 로직처리) 하기 위한 세팅
    while (arr[y2][x2] != '0') {
        cnt++;
        queue<int> temp;
        while (!q.empty()) {
            y = q.front() / 1000;
            x = q.front() % 1000;
            q.pop();
            for (int i = 0; i<4; i++) {
                int ny = y+dy[i];
                int nx = x+dx[i];
                if (ny < 0 || ny >=r || nx < 0 || nx>=c
                    || vst[ny][nx]) continue;
                vst[ny][nx] = cnt;
                if (arr[ny][nx] != '0') {
                    arr[ny][nx] = '0';
                    temp.push(ny * 1000 + nx);
                } else {
                    q.push(ny*1000 + nx); // 새로운 레이어 할당
                }
            }
        }
        q=temp; // 새로운 레이어로 부터 출발
    }
    // printf("%d\n",cnt);
    printf("%d\n",vst[y2][x2]);
    return 0;
}
