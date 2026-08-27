#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> B(n), J(n);
    for (int x = 0; x < n; x++) {
        cin >> B[x];
    }

    for (int x = 0; x < n; x++) {
        cin >> J[x];
    }

    queue<pair<int, int>> q;
    q.push({B[0], 0});
    int minSek = q.front().first;
    q.pop();
    if (n > 1) {
        if (minSek > B[1]) {
            q.push({B[1], 1});
        }
    }

    int res = -1;
    for (int x = 2; x < n; x++) {
        if (!q.empty() && q.front().second <= x - 2) {
            minSek = q.front().first;
            q.pop();
        }

        if (minSek < J[x]) {
            res = max(res, J[x] - minSek);
        }

        if (B[x] < minSek) {
            q.push({B[x], x});
        }
    }

    if (res <= 0) {
        cout << "tidak mungkin";
    } else {
        cout << res << "\n";
    }
}