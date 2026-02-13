//
// Created by 5600G on 2026-02-13.
//

/** @see https://www.acmicpc.net/problem/14864
 * 애드혹 문제
 * 관찰하는 것이 중요하다.
 *
 * 순서대로 카드값을 가진다고 가정했을때,
 * 순서가 앞인데 카드가 더 큰값이면 순서가 앞인 학생은 처음 값보다 1커야하고
 * 순서가 뒤인데 카드가 작은 값이면 순서가 뒤인 학생은 처음 값보다 1작아야한다.
 * 카드를 가진 사람수는 유일해야한다.
 */
#include <iostream>

using namespace std;
const int MAX_N = 100001;
int n,m,x,y,cnt[MAX_N], val[MAX_N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i=0; i<m; i++)
    {
        cin >> x >> y;
        val[x]++; // x번 학생은 뒤에 작은 번호가 있으니 +
        val[y]--; // y번 학생은 앞에 큰 번호가 있으니 -
    }
    for (int i=1; i<=n; i++)
    {
        val[i] += i; // 증분 만큼 옮겨준다.
        cnt[val[i]]++; // 해당 카드 값을 가지는 인원의 수를 늘려준다.
    }

    bool flag = false;
    for (int i=0; i<n; i++)
        if (cnt[i+1] > 1) flag = true; // 같은 카드를 가진 학생이 두 명 이상이면 틀린 입력이다.
    if (flag) cout << -1 << "\n";
    else
    {
        for (int i=1; i<=n; i++) cout << val[i] << " ";
    }
    return 0;
}
