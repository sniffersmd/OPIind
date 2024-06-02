#include "pch.h"
#include "calc.h"
#include <algorithm>

namespace calc {
    int calcing(int n, const std::vector<int>& a, int k) {
        std::vector<int> sorted_a = a;
        std::sort(sorted_a.begin(), sorted_a.end(), std::greater<int>());

        int total_teams = 0;
        for (int i = 0; i < n; ++i) {
            total_teams += std::min(sorted_a[i], k);
        }

        return total_teams;
    }
}
