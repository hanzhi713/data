//
// Created by hanzhi713 on 10/2/19.
//

#include <bits/stdc++.h>
using namespace std;

struct item {
    string name;
    int count;
};

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        unordered_map<string, int> count;
        int N;
        cin >>N;
        for (int j = 0; j < N; ++j) {
            string name;
            int num;
            cin >> name >> num;
            count[name] += num;
        }
        vector<item> all;
//        all.reserve(count.size());

        cout << count.size() << endl;
//        int k = 0;
//        for (auto &it: count) {
//            cout << k << endl;
//            all[k++] = {it.first, it.second};
//        }

        for (auto &it: count) {
            all.push_back({it.first, it.second});
        }

        sort(all.begin(), all.end(), [](item& a, item&b) {
            if (a.count == b.count) {
                return a.name < b.name;
            } else {
                return a.count > b.count;
            }
        });

        for (auto &t: all) {
            cout << t.name << " " << t.count << endl;
        }
    }



}