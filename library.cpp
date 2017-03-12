#include "library.h"

#include <iostream>

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

