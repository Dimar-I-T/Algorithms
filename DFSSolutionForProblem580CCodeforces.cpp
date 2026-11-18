#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    vector<int> tetangga;
    bool hasCat;
};

vector<Node> nodes;
int n, m;

void dfs(int par, int sek, int cnt, int& res) {
    if (cnt > m) {
        return;
    }

    vector<int> selV = nodes[sek].tetangga;

    if (selV.size() == 1 && sek != 1) {
        res++;
        return;
    }

    bool prevHasCat = nodes[sek].hasCat;
    for (int sel : selV) {
        if (par == sel) {
            continue;
        }

        bool nextHasCat = nodes[sel].hasCat;
        if (prevHasCat && nextHasCat) {
            dfs(sek, sel, cnt + 1, res);
        } else if (nextHasCat) {
            dfs(sek, sel, 1, res);
        } else {
            dfs(sek, sel, 0, res);
        }
    }
}

int main() {
    cin >> n >> m;
    nodes.clear(); nodes.resize(n + 1);

    int res = 0;

    for (int x = 1; x <= n; x++) {
        bool a;
        cin >> a;
        nodes[x].hasCat = a;
    }

    for (int x = 0; x < n - 1; x++) {
        int u, v;
        cin >> u >> v;
        nodes[u].tetangga.push_back(v);
        nodes[v].tetangga.push_back(u);
    }

    int cnt = 0;
    if (nodes[1].hasCat) {
        cnt++;
    }

    dfs(0, 1, cnt, res);

    cout << res;
}