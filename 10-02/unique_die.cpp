//
// Created by hanzhi713 on 10/2/19.
//

#include <bits/stdc++.h>
using namespace std;

static char R1[] = {5, 3, 4, 2};
static char R2[] = {3, 1, 2, 0};
static char R3[] = {5, 1, 4, 0};

inline void rotate(char *dice, const char *R) {
    char last = dice[R[3]];
    for (int i = 3; i >= 1; --i) {
        dice[R[i]] = dice[R[i - 1]];
    }
    dice[R[0]] = last;
}

inline int toNum(const char *dice) {
    int sum = 0;
    for (int i = 0; i < 6; ++i) {
        sum += (dice[i] - 48);
        sum *= 10;
    }
    return sum;
}

inline void update(unordered_map<int, int> &collections, char *dice) {
    for (int j = 0; j < 4; ++j) {
        auto r = collections.find(toNum(dice));
        if (r != collections.end()) {
            r->second++;
            return;
        }
        for (int k = 0; k < 4; ++k) {
            r = collections.find(toNum(dice));
            if (r != collections.end()) {
                r->second++;
                return;
            }
            for (int i = 0; i < 4; ++i) {
                r = collections.find(toNum(dice));
                if (r != collections.end()) {
                    r->second++;
                    return;
                }
                rotate(dice, R3);
            }
            rotate(dice, R2);
        }
        rotate(dice, R1);
    }
    collections[toNum(dice)] = 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    unordered_map<int, int> collections;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char dice[6];
        for (int j = 0; j < 6; ++j)
            cin >> dice[j];
        update(collections, dice);
    }
    int max_count = 1;
    for (auto &it: collections) {
        if (it.second > max_count) max_count = it.second;
    }
    cout << max_count << endl;
}