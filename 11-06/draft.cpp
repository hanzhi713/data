#include <bits/stdc++.h>
using namespace std;

vector<string> pref[60];
vector<string> teams[60];
bool visited[65000];
pair<string, bool *> allnames[65000];
unordered_map<string, bool *> selected;

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        auto &vec = pref[i];
        int q;
        cin >> q;
        vec.resize(q);
        for (int j = 0; j < q; j++) {
            cin >> vec[j];
        }
    }
    int p;
    cin >> p;
    selected.reserve(p);
    for (int i = 0; i < p; ++i) {
        string name;
        cin >> name;
        selected[name] = &visited[i];
        allnames[i] = {name, &visited[i]};
    }
    int idx = 0;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            auto &curPref = pref[j];
            for (auto mit = curPref.begin(); mit != curPref.end(); mit++) {
                auto &p = *mit;
                auto it = selected.find(p);
                if (!it->second[0]) {
                    it->second[0] = true;
                    teams[j].push_back(p);
                    curPref.erase(mit);
                    goto end;
                }
            }
            while (allnames[idx].second[0])
                idx++;
            teams[j].push_back(allnames[idx].first);
            allnames[idx].second[0] = true;
            end:;
        }
    }
    for (int i = 0; i < n; ++i) {
        auto &vec = teams[i];
        for (int j = 0; j < k; ++j)
            cout << vec[j] << " ";
        cout << endl;
    }
}