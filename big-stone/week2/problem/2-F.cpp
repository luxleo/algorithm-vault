//
// Created by 이동한 on 2025. 1. 18..
//
#include <bits/stdc++.h>
using namespace std;
int n,m,iterNum,pos,ret,r,l;

/**
 * 사과와 바구니의 관계를 칸 으로 생각하지 않고 점(인덱스)로 생각하면 r = l+m-1 의 식이 이해가 갈것이다.
 * @see https://www.acmicpc.net/problem/2828
 */
int main() {
    cin >> n >> m;
    cin >> iterNum;
    l = 1;
    for (int i = 0; i < iterNum; i++) {
        r= l + m -1; // (0) 직관적이지 않다면 모델을 바꾸어 볼것. 칸이 아니라 땅에 박힌 막대기 통로를 통해서 사과가 내려온다고.
        cin >> pos;
        if (pos >= l && pos <= r) continue;
        //(1) 아래와 같이 바구니를 움직이는 과정을 순차적으로 조정해주어야한다고 생각했는데 전혀 그럴필요 없다. 한방에 계산해서 처리하기.
        if (pos < l) {
            ret += (l - pos);
            l = pos;
        } else if (pos > r) {
            l += (pos - r);
            ret += (pos -r);
        }
    }
    cout << ret << "\n";
    return 0;
}