//
// Created by hanzhi713 on 11/6/2019.
//
#include <bits/stdc++.h>
#define int long long
using namespace std;

int numbers[200000];
#undef int
int main() {
#define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, d;
    cin >> N >> d;
    for (int i = 0; i < N; ++i) {
        int t;
        cin >> t;
        numbers[i] = t / d;
    }
    int count = 0;

    sort(numbers, numbers + N);
    int s = 1;
    for (int i = 1; i < N; ++i) {
        if (numbers[i] == numbers[i - 1]) {
            count += s;
            s += 1;
        } else {
            s = 1;
        }
    }
    cout << count << endl;
}