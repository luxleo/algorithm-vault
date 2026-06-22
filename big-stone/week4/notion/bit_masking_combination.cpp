//
// Created by 5600G on 2026-03-17.
//

/**
 * 비트마스킹을 이용하여 경우의 수 구하기
 * 아이디어: 경우의 수 모집합이 되는 원소의 개수 n개의 원소를 가지는 집합을 만들고 (1 << n)
 * 전체 집합의 크기 (1 << n) 을 상한으로 가지는 for 문을 만들어 경우의 수를 카운트 한다.
 *  for(int i=0; i< (1 << n); i++ )
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a[] = {"사과", "딸기", "포도", "배"};
    int n = sizeof(a)/sizeof(a[0]);
    for (int i=0; i < (1 << n); i++)
    {
        string ret = "";
        for (int j=0; j<n; j++)
        {
            if (i & ( 1 << j))
            {
                ret += (a[j] + " ");
            }
        }
        cout << ret << "\n";
    }
    return 0;
}
