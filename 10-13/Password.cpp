//
// Created by hanzhi713 on 10/13/19.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int k, m, mi;
    string s, t, encoded;
    vector<string> v;

    cin >> s;
    for (int i = 0; i < 26; i++) {
        cin >> t;
        v.push_back(t);
    }

    cin >> k >> m;
    for (int i = 0; i < k; i++) {
        encoded = "";
        for (int j = 0; j < s.length(); j++) {
            encoded += v[s[j] - 'a'];
        }
        s = encoded;
    }

    for (int i = 0; i < m; i++) {
        cin >> mi;
        cout << encoded[mi - 1] << endl;
    }
}
