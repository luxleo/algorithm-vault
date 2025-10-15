//
// Created by 이동한 on 2025. 9. 22..
//
/**
 * LIS : (Longest Increasing Sequence) 최장증가부분수열 이다.
 * 구현 방식에 두 가지가 있는데 O(n) / O(logn)이 있다.
 * 이때 O(logn)인 경우는 prev_list를 이용하여 실제 배열을 구하지 못한다.
 *
 * 구하는 값은 크게 두 가지 인데
 * 1. 최장 수열 길이의 값
 * 2. 최장 부분 수열 구하기
 *
 * 2번의 경우 prev_list를 이용하여 구한다.
 */
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

const vector<int> dat = {10, 20, 10, 30, 20, 50};
int cnt[11];
int prev_list[101];

int just_count() {
    memset(cnt, 0, sizeof(cnt));
    int ret = 0;
    for (int i = 0; i < dat.size(); i++) {
        int max_val = 0;
        for (int j = 0; j < i; j++) {
            if (dat[j] < dat[i] && max_val < cnt[j]) {
                max_val = cnt[j];
            }
        }
        cnt[i] = max_val + 1;
        ret = max(ret, cnt[i]);
    }
    return ret;
}

void trace(vector<int> &trace_vec, int idx) {
    if (idx == -1) return;
    trace_vec.push_back(dat[idx]);
    trace(trace_vec, prev_list[idx]);
}

vector<int> with_subsequence() {
    int ret = 0, idx = 0;
    vector<int> trace_vec;
    fill(prev_list, prev_list + 101, -1);
    fill(cnt, cnt + 11, 1);
    for (int i = 0; i < dat.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (dat[j] < dat[i] && cnt[i] < cnt[j] + 1) {
                cnt[i] = cnt[j] + 1;
                prev_list[i] = j;
                if (ret < cnt[i]) {
                    ret = cnt[i];
                    idx = i;
                }
            }
        }
    }

    trace(trace_vec, idx);
    for (int num: trace_vec) {
        cout << num << ' ';
    }
}

// TODO: O(logn) 구현하기
