//
// Created by 5600G on 2025-10-17.
//
/** 2400이 포함되는 수 중에 순서대로 나열시 n번째에 오는 수를 찾으라.
 */
#include <bits/stdc++.h>
using namespace std;

int n;
int main()
{
    cin >> n;
    int cnt=0,ret=2400;
    while (true)
    {
        if (to_string(ret).find("2400") != string::npos )
        {
            cnt++;
            if (cnt == n)
            {
                cout << ret << "\n";
                break;
            }
        }
        ret++;
    }

    return 0;
}
