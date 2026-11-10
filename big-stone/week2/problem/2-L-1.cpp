//
// Created by 5600G on 2026-08-12.
//

#include <bits/stdc++.h>
using namespace std;
int tA, tB, sA, sB,n;
string team, winTime;

int parseTimeToMinute(string s)
{
    int hour = stoi(s.substr(0,2));
    int minute = stoi(s.substr(3,2));
    return hour*60 + minute;
}

void printWinTime(int minute)
{
    // TODO: i want to print as following 355 -> "05:55"
    int hours = (minute / 60); // wrap around 24 hours
    int mins  = minute % 60;

    // Print in zero-padded format
    printf("%02d:%02d\n", hours, mins);
}

void judgeScore(string team, int minute)
{
    if (team == "1")
    {
        sA++;
        if (sA - sB == 1) // 최초로 넘을 때 점수 갱신한다
        {
            tA += minute - tB;
        } else if (sA == sB) // 동점이면 이기고 있었던 팀 갱신 해준다
        {
            tB += minute - tB;
        }
    } else
    {
        sB++;
        if (sB - sA == 1) // 최초로 넘을 때 점수 갱신한다
        {
            tB += minute - tA;
        } else if (sA == sB) // 동점이면 이기고 있었던 팀 갱신 해준다
        {
            tA += minute - tA;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> team >> winTime;
        int time = parseTimeToMinute(winTime);
        judgeScore(team, time);
    }
    printWinTime(tA);
    printWinTime(tB);
    return 0;
}
