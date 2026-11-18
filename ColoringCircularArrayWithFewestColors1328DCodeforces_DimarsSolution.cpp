#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> T(n);
    for (int x = 0; x < n; x++) {
        cin >> T[x];
    }

    vector<int> res(n);
    res[0] = 1;
    int curr = 1;
    bool sek = 0;
    int lastSame = -1;
    int k = 1;
    for (int x = 1; x < n; x++) {
        if (T[x] != T[x - 1]) {
            sek = !sek;
            curr = sek + 1;
            k = 2;
        } else {
            lastSame = x;
        }

        res[x] = curr;
    }

    if (T[n - 1] != T[0] && res[n - 1] == res[0]) {
        if (lastSame != -1) {
            int last = res[lastSame] - 1;
            sek = last;
            for (int x = lastSame; x < n; x++) {
                sek = !sek;
                curr = sek + 1;
                res[x] = curr;
            }
        } else {
            res[0] = 3;
            k++;
        }
    }

    cout << k << "\n";
    for (int t : res) {
        cout << t << " ";
    }

    cout << "\n";
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}