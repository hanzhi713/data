#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        unordered_map<string, int> count;
        int N;
        cin >> N;
        for (int j = 0; j < N; ++j) {
            string name;
            int num;
            cin >> name >> num;
            count[name] += num;
        }
        cout << count.size() << endl;
        vector<pair<string, int>> all(count.begin(), count.end());
        sort(all.begin(), all.end(), [](auto &a, auto &b) {
            if (a.second == b.second) {
                return a.first < b.first;
            } else {
                return a.second > b.second;
            }
        });

        for (auto &t: all) {
            cout << t.first << " " << t.second << endl;
        }
    }
}