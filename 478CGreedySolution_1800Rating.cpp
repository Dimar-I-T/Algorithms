#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<unsigned long long> c(3);
    cin >> c[0] >> c[1] >> c[2];
    unsigned long long res = 0;
    sort(c.begin(), c.end());
    if (2*c[0] < c[1] && 2*c[1] < c[2]) {
        res = c[0] + c[1];
    } else if (2*c[0] >= c[1] && 2*c[1] < c[2]) {
        if (2*(c[0] + c[1]) < c[2]) {
            res = c[0] + c[1];
        } else {
            res = (c[0] + c[1] + c[2]) / 3; 
        }
    } else {
        res = (c[0] + c[1] + c[2]) / 3;
    }
    
    if (c[0] + c[1] + c[2] >= 3) {
        cout << res;
    } else {
        cout << 0;
    }
}
