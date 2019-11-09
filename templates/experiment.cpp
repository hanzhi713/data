#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int, vector<int>, less<>> q;
    q.push(5);
    q.push(1);
    q.push(3);
    cout << q.top() << endl;
}
