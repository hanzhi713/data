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

inline bool eqd(const char *dice1, const char *dice2) {
    for (int i = 0; i < 6; i++) {
        if (dice1[i] != dice2[i]) return false;
    }
    return true;
}

inline bool testEqual(char *dice1, char *dice2) {
    for (int j = 0; j < 4; ++j) {
        if (eqd(dice1, dice2)) return true;
        for (int k = 0; k < 4; ++k) {
            if (eqd(dice1, dice2)) return true;
            for (int i = 0; i < 4; ++i) {
                if (eqd(dice1, dice2)) return true;
                rotate(dice1, R3);
            }
            rotate(dice1, R2);
        }
        rotate(dice1, R1);
    }
    return false;
}

//inline bool testEqual(char *dice1, char *dice2) {
//    char temp1[] = {dice1[0], dice1[3], dice1[5], dice1[1], dice1[2], dice1[4]};
//    char temp2[] = {dice2[0], dice2[3], dice2[5], dice2[1], dice2[2], dice2[4]};
//
//    for (int i = 0; i < 6; ++i) {
//        if (eqd(temp1, temp2)) return true;
//        rotate(temp1, temp1 + 1, temp1 + 6);
//    }
//    return false;
//}

struct record {
    char dice[6];
    int count = 1;
};

int main() {
//        char b[] = {1,6,3,4,2,5};
////    char a[] = {1,6,2,5,4,3};
//    rt(b);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    vector<record> collections;
    cin >> n;

    int max_count = 1;
    for (int i = 0; i < n; ++i) {
        record temp;
        for (int j = 0; j < 6; ++j) {
            cin >> temp.dice[j];
        }
        for (auto &rec: collections) {
            if (testEqual(temp.dice, rec.dice)) {
                if (++rec.count > max_count) max_count = rec.count;
                goto end;
            }
        }
        collections.push_back(temp); // not in any other collection
        end:;
    }
    cout << max_count << endl;
}