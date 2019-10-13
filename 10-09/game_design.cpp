//
// Created by hanzhi713 on 10/9/19.
//
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> blocks;

void backtrack(string& s, char last, int i, int x, int y) {
    if (s[i] == 'U') {
        if (last == 'R') {
//            backtrack(s, i + 1, , y);
        }
        for (int m = -100000; m < 100000; ++m) {
            int nx = x + m;
            blocks.emplace_back(nx, y);

        }
    }
}

int main() {
    string s;
    cin >> s;
    s.reserve();

    for (int i = 0; i < s.size(); i++) {
        char di = s[i];
//        if (di == 'L')
//        LRUD
    }

    for(int i = 0; i < n; i ++){
        for (int j = 0; j < i; j++){

        }
    }

}