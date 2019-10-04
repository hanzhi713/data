#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    for (int __ = 0; __ < N; ++__) {
        string a, b;
        cin >> a >> b;

        set<vector<int>> traits;
        for (int len = b.length(); len > 0; --len) {
            vector<int> freq(26, 0);
            for (int i = 0; i < len; ++i) { // initial freq stat
                freq[b[i] - 97]++;
            }
            traits.insert(freq);
            for (int i = 0, T = b.length() - len; i < T; ++i) {
                freq[b[i] - 97]--;
                freq[b[i + len] - 97]++;
                traits.insert(freq);
            }
        }

        for (int len = a.length(); len > 0; --len) {
            vector<int> freq(26, 0);
            for (int i = 0; i < len; ++i) { // initial freq stat
                freq[a[i] - 97]++;
            }
            if (traits.find(freq) != traits.end()) {
                cout << a.substr(0, len) << endl;
                goto next;
            }
            for (int i = 0, T = a.length() - len; i < T; ++i) {
                freq[a[i] - 97]--;
                freq[a[i + len] - 97]++;
                if (traits.find(freq) != traits.end()) {
                    cout << a.substr(i + 1, len) << endl;
                    goto next;
                }
            }
        }
        cout << "None" << endl;
        next:;

    }
}
