#include "library.h"

#include <iostream>
#include <algorithm>

using namespace std;

int choice(int n, int k) {
    if (k > n) {
        return 0;
    }

    int r = 1;

    for (int d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }

    return r;
}

auto combinations(vector<int> A, int k) {
    auto N = A.size();
    vector <vector<int>> combinations;
    string select(k, 1);
    select.resize(N, 0);

    do {
        vector<int> c;
        for (auto i = 0; i < N; i++) {
            if (select[i]) {
                c.push_back(A[i]);
            }
        }
        combinations.push_back(c);
    } while (prev_permutation(select.begin(), select.end()));

    return combinations;
}

auto kcombinations(vector <vector<int>> A, int k) {

    vector <vector<int>> seconds;
    for (auto a : A) {

        for (auto b: combinations(a, k)) {
            vector<int> combined;
            combined.insert(combined.end(), a.begin(), a.end());
            combined.insert(combined.end(), b.begin(), b.end());
            seconds.push_back(combined);
        }
    }

    return seconds;
}