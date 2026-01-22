//
// Created by 5600G on 2026-01-22.
//
#include <iostream>
#include <map>
#include <queue>
using namespace std;

/** @see https://www.acmicpc.net/problem/14867
 * 물통 채우기 문제였다.
 * bfs를 통한 경로 찾기를 적용하면 구할 수 있다.
 * 명시적으로 경로 찾는 문제가 아니라 하더라도 다음의 조건을 만족하면
 * bfs를 적용한 경로찾기 문제로 풀이할 수 있다.
 *
 * 1. 한 스텝당 정해진 이동(연산) 양식
 * 2. 최소의 경로(횟수) 를 구하는 방식.
 * 3. 한 스텝당 일정한 갱신 양 (이 경우 +1)
 */
int a,b,c,d;
queue<pair<int,int>> q;
map<pair<int,int>,int> mp; // map 의 key 값으로 참조형 자료형을 사용할 수 있다.

void work(int x, int y, int d)
{
    if (mp[{x,y}]) return; // 이미 최단거리로 방문 했기 때문에 반환처리한다.
    mp[{x,y}] = d+1;
    q.emplace(x,y);
}

int bfs(int x, int y)
{
    mp[{x,y}] = 1; // 임의의 mp[{x,y}] 의 값이 0인 경우 방문하지 않았음을 의미힌다.
    q.emplace(x,y);

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        const int current = mp[{x,y}];
        work(a,y,current); // A 물병을 a의 양으로 가득채운다.
        work(x,b,current); // B 물병을 b의 양으로 가득채운다.
        work(0,y,current); // A 물병 비우기
        work(x,0,current);
        work(min(x+y,a), max(0,x+y-a),current); // B 물병을 A에 가능한한 많이 넣는다.
        work(max(0,x+y-b), min(b, x+y), current);
    }

    if (mp[{c,d}]) return mp[{c,d}] - 1; // 최초 부터 +1 을 할당하였으므로 -1 해주어야한다.
    return -1;
}

int main()
{
    cin >> a >> b >> c >> d;
    cout << bfs(0,0);
    return 0;
}