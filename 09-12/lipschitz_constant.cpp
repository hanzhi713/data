#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
struct point {
    double x;
    double y;
};
int main() {
    point data[200000];
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> data[i].x >> data[i].y;
    }
    sort(data, data + num, [](point &a, point &b) { return a.x < b.x; });
    double L = 0;
    for (int i = 1; i < num; i++) {
        double x1 = data[i].x,
                y1 = data[i].y;
        double diffx = data[i - 1].x - x1,
                diffy = data[i - 1].y - y1;
        double newL = abs(diffy / diffx);
        if (newL > L) L = newL;
    }
    cout.precision(numeric_limits<double>::max_digits10);
    cout << L << endl;
}