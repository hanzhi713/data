//
// Created by hanzhi713 on 9/19/19.
//

#include <bits/stdc++.h>

using namespace std;

struct Sol {
    int16_t idx;
    int16_t r;
    int16_t c;
    int16_t end;
    float score;
    bool direction;

    Sol(int16_t idx, int16_t r, int16_t c, float s, bool d) : idx(idx), r(r), c(c), end(0), score(s), direction(d) {}
};

ostream &operator<<(ostream &out, const Sol &c) {
    out << c.idx << (c.direction ? "D" : "A"); //<< ": " << c.score << " " << c.r << ", " << c.c;
    return out;
}

void inline countNum(const int8_t *grid, int16_t r, int16_t c, Sol &sol) {
    if (sol.direction) { // down
        for (int i = sol.r; i < r; i++) {
            if (grid[i * c + sol.c] == 1) {
                sol.end = i;
                return;
            }
        }
        sol.end = r;
    } else {
        for (int i = sol.c; i < c; i++) {
            if (grid[sol.r * c + i] == 1) {
                sol.end = i;
                return;
            }
        }
        sol.end = c;
    }
}

float inline calcScore(const int8_t *grid, int16_t c, Sol &sol) {
    int existCount = 0;
    int count;
    if (sol.direction) { // down
        count = sol.end - sol.r;
        for (int i = sol.r; i < sol.end; i++) {
            auto temp = grid[c * i + sol.c];
            existCount += (temp == 2) * (count--);
        }
        count = sol.end - sol.r;
    } else {
        count = sol.end - sol.c;
        for (int i = sol.c; i < sol.end; i++) {
            auto temp = grid[sol.r * c + i];
            existCount += (temp == 2) * (count--);
        }
        count = sol.end - sol.c;
    }
    return sol.score = static_cast<float>(existCount) / ((count * (count + 1)) >> 1);
}

int main() {
    int16_t r, c;
    cin >> r >> c;
    int size = r * c;
    auto *grid = new int8_t[size]();
    vector<Sol> starts;
    starts.reserve(size);

    for (int16_t i = 0; i < r; i++) {
        for (int16_t j = 0; j < c; j++) {
            char x;
            cin >> x;
            int16_t idx = c * i + j;
            if (x == '.') {
                grid[idx] = 0;
            } else if (x == '#') {
                grid[idx] = 1;
            } else {
                grid[idx] = 2;
            }
        }
    }

    int16_t count = 1;
    for (int16_t i = 0; i < r; i++) {
        for (int16_t j = 0; j < c; j++) {
            int idx = c * i + j;
            if (grid[idx] == 1) continue;
            bool flag = false;
            if (j == 0 || grid[idx - 1] == 1) { // across
                starts.push_back({count, i, j, 0.0, false});
                flag = true;
            }
            if (i == 0 || grid[idx - c] == 1) { // down
                starts.push_back({count, i, j, 0.0, true});
                flag = true;
            }
            if (flag) count++;
        }
    }

    for (auto &sol : starts)
        countNum(grid, r, c, sol);

    while (!starts.empty()) {
        float maxScore = calcScore(grid, c, starts[0]);
        int maxIdx = 0;
        for (int i = 1; i < starts.size(); i++) {
            auto &sol = starts[i];
            auto score = calcScore(grid, c, sol);
            if (score > maxScore) {
                maxScore = score;
                maxIdx = i;
            } else if (score == maxScore) {
                auto& mxE = starts[maxIdx];
                if (sol.direction < mxE.direction || sol.idx < mxE.idx)
                    maxIdx = i;
            }
        }
        auto it = starts.begin() + maxIdx;
        auto &sol = *it;
        if (maxScore != 1) {
            if (sol.direction) { // down
                for (int i = sol.r; i < sol.end; i++)
                    grid[i * c + sol.c] = 2;
            } else {
                for (int i = sol.c; i < sol.end; i++)
                    grid[c * sol.r + i] = 2;
            }
            cout << *it << endl;
        }
        starts.erase(it);
    }
}