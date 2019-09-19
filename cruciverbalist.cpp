//
// Created by hanzhi713 on 9/19/19.
//

#include <bits/stdc++.h>
using namespace std;

struct Sol {
    int idx;
    int r;
    int c;
    float score;
    bool direction;
    Sol(int idx, int r, int c, float s, bool d): idx(idx), score(s), r(r), c(c), direction(d) {}

    string getName() {
//
//        return "A" + "B";
    }
};

ostream & operator << (ostream &out, const Sol &c)
{
//    out << c.real;
//    out << "+i" << c.imag << endl;
    return out;
}

void inline calcScore(const int8_t *grid, int r, int c, Sol& sol) {
    int existCount = 0;
    int count = 0;
    if (sol.direction) { // down
        for (int i = sol.r; i < r; i++) {
            int idx = r * i + sol.c;
            auto temp = grid[idx];
            if (temp == 1) {
                break;
            }
            existCount += temp == 2;
            count++;
        }
    } else {
        for (int i = sol.c; i < c; i++) {
            int idx = sol.r * r + i;
            auto temp = grid[idx];
            if (temp == 1) {
                break;
            }
            existCount += temp == 2;
            count++;
        }
    }
    sol.score = static_cast<float>(existCount) / count;
}

int main() {
    int r, c;
    cin >> r >> c;
    int size = r * c;
    auto *grid = new int8_t[size]();
    vector<Sol> starts;
    starts.reserve(size);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; ++j) {
            char x;
            cin >> x;
            int idx = r * i + j;
            if (x == '.') {
                grid[idx] = 0;
            } else if (x == '#') {
                grid[idx] = 1;
                continue;
            } else {
                grid[idx] = 2;
            }
            if (j == 0 || grid[idx - 1] == '#') { // across
                starts.push_back({0, i, j, 0.0, false});
            }
            if (i == 0 || grid[(i - 1) * r + c] == '#') { // down
                starts.push_back({0, i, j, 0.0, true});
            }
        }d
    }

    for (auto& sol : starts) {
        calcScore(grid, r, c, sol);
    }
//    while ()
}