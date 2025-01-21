//
// Created by 이동한 on 2025. 1. 21..
//
#include <bits/stdc++.h>
using namespace std;

/**
*동혁이는 NBA 농구 경기를 즐겨 본다.
*동혁이는 골이 들어갈 때 마다 골이 들어간 시간과 팀을 적는 이상한 취미를 가지고 있다.
농구 경기는 정확히 48분동안 진행된다.
각 팀이 몇 분동안 이기고 있었는지 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 골이 들어간 횟수 N(1<=N<=100)이 주어진다.
둘째 줄부터 N개의 줄에 득점 정보가 주어진다.
득점 정보는 득점한 팀의 번호와 득점한 시간으로 이루어져 있다.
팀 번호는 1 또는 2이다. 득점한 시간은 MM:SS(분:초) 형식이며,
분과 초가 한자리 일 경우 첫째자리가 0이다. 분은 0보다 크거나 같고,
47보다 작거나 같으며, 초는 0보다 크거나 같고, 59보다 작거나 같다. 득점 시간이 겹치는 경우는 없다.

출력
첫째 줄에 1번 팀이 이기고 있던 시간, 둘째 줄에 2번 팀이 이기고 있던 시간을 출력한다.
시간은 입력과 같은 형식(MM:SS)으로 출력한다.

예제 입력 1
1
1 20:00

예제 출력 1
28:00
00:00
 * @see https://www.acmicpc.net/problem/2852
 */
#define prev prevTime // (1) 예약어랑 겹치면 따로 정의 해주면 된다.
#define time tt
int n, acnt, bcnt, scoreTeam,A,B;
string time,prev;

string secondToString(int second) {
    string minute = "00" + to_string(second/60); // (2) 포매팅 하여 출력하는 방법
    string sec = "00" + to_string(second % 60);
    //(3) string.substr(startIdx, number);
    return minute.substr(minute.size()-2,2) + ":" + sec.substr(sec.size()-2,2);
}

// (3) 시간이 나오면 항상 단위 최소로 맞추어 줄것 시 -> 분 , 분 -> 초
int timeToSecond(string str_time) {
    // (4) atoi(stirng.c_str());
    return atoi(str_time.substr(0,2).c_str())* 60 + atoi(str_time.substr(3,2).c_str());
};

void score(int &acc, string s) {
    acc += timeToSecond(s) - timeToSecond(prev);
}

int main() {
    cin >> n;
    for (int i =0; i<n; i++) {
        cin >> scoreTeam >> time;
        // (5) 최초 득점을 생각하면 먼저 점수를 내주고 승리 시간이 카운트 되므로
        // 순서를 잘 지켜줄것
        if (A > B) score(acnt, time);
        else if (B>A) score(bcnt, time);
        if (scoreTeam == 1) A++;
        else B++;
        prev = time;
    }
    // (6) 경계 조건 뺴먹지 않기!!
    if (A>B) score(acnt, "48:00");
    else if (B>A) score(bcnt, "48:00");
    cout << secondToString(acnt) << "\n";
    cout << secondToString(bcnt) << "\n";
    return 0;
}
