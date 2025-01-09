//
// Created by 이동한 on 2025. 1. 9..
//
/**
 * 순열은 순서 있도록 원소를 뽑는 경우이다.
 * nPr = n!/(n-r)!
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> a = {4,1, 2, 3};
void permutation_usage() {
    vector<int> local_a = a;
    // next_permutation은 현재 순서를 기준으로 순열을 만들어 간다. 따라서 오름차순으로 정렬을 해주어야 모든 순열을 만들수 있다.
    sort(local_a.begin(), local_a.end()); // same as sort(&a, &a+4);

    do {
        for (auto i : local_a) {
            cout << i << " ";
        }
        cout << endl;
    } while (next_permutation(local_a.begin(), local_a.end()));

    for (auto i : a) {
        cout << i << " ";
    }
}

/**
 * nCk에서 재귀 방식의 조합 조합 가능 수 n이 4 이상일때 사용하면 좋다.
 * @param start Starting index for the combination.
 * @param n Total number of elements in the data vector.
 * @param k Size of each combination to generate.
 * @param acc Vector used to collect the current combination during recursion.
 * @param data Original data vector from which combinations are formed.
 */
void combi(int start,int n,int k, vector<int> acc, vector<int> data) {
    if (acc.size() == k) {
        for (auto i : acc) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    for (int i= start; i<n; i++ ) {
        acc.push_back(data[i]);
        combi(i+1,n,k,acc,data);
        acc.pop_back();
    }
}

/**
 * nCk에서 k가 3이하 일때는 루프로 돌려주는게 좋다.
 */
void combi_with_loop() {
    int n = 10;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                cout << i << " " << j << " " << k << "\n";
            }
        }
    }
}

int main() {
    permutation_usage();
    combi(0, 5, 4, {}, {1,2,3,4,5});
    combi_with_loop();
    return 0;
}
