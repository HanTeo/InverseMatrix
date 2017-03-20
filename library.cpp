#include "library.h"
#include "Eigen/Dense"
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

template<typename T>
auto combinations(vector <T> A, int k) {
    auto N = A.size();
    vector <vector<T>> combinations;
    string select(k, 1);
    select.resize(N, 0);

    do {
        vector <T> c;
        for (auto i = 0; i < N; i++) {
            if (select[i]) {
                c.push_back(A[i]);
            }
        }
        combinations.push_back(c);
    } while (prev_permutation(select.begin(), select.end()));

    return combinations;
}

template<typename T>
auto kcombinations(vector <vector<T>> A, int k) {

    vector <vector<T>> seconds;
    for (auto a : A) {

        for (auto b : combinations(a, k)) {
            vector <T> combined;
            combined.insert(combined.end(), a.begin(), a.end());
            combined.insert(combined.end(), b.begin(), b.end());
            seconds.push_back(combined);
        }
    }

    return seconds;
}

template<typename T>
auto toEigen(vector <T> A, int n) {

    Eigen::MatrixXf eigen(n, n);

    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            eigen(i, j) = A[k++];
        }
    }

    return eigen;
}

template<typename T>
auto buildMatrix(vector <T> selection) {
    vector <T> square;
    int N = selection.size();

    int i = 0;
    sort(selection.begin(), selection.end());
    while (i < N) {
        square.insert(square.end(), selection.begin(), selection.end());
        i++;
        next_permutation(selection.begin(), selection.end());
    }

    return toEigen(square, N);
}
