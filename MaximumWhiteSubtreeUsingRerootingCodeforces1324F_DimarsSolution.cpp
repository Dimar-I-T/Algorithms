#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tetangga;
vector<int> dp;
vector<int> rerootedDP;
vector<int> val;
vector<bool> used;

void dfs(int sek, int par) {
    vector<int> selV = tetangga[sek];
    if (selV.size() == 1) {
        dp[sek] = (val[sek] == 1) ? 1 : -1;
    }

    int sum = 0;
    for (int sel : selV) {
        if (sel == par) {
            continue;
        }

        dfs(sel, sek);
        if (dp[sel] >= 0) {
            used[sel] = 1;
            sum += dp[sel];
        }
    }

    sum += val[sek];
    dp[sek] = sum;
}

void reroot(int sek, int par) {
    rerootedDP[sek] = dp[sek];
    for (int sel : tetangga[sek]) {
        if (sel == par) {
            continue;
        }

        int prevSek = dp[sek];
        int prevSel = dp[sel];
        if (used[sel]) {
            dp[sek] -= dp[sel];
        }

        if (dp[sek] >= 0) {
            dp[sel] += dp[sek];
        }
        
        reroot(sel, sek);

        if (used[sel]) {
            dp[sek] = prevSek;
        }

        dp[sel] = prevSel;
    }
}

int main() {
    int n;
    cin >> n;
    tetangga.clear(); tetangga.resize(n + 1);
    val.clear(); val.resize(n + 1);
    used.clear(); used.resize(n + 1);
    dp.clear(); dp.resize(n + 1);
    rerootedDP.clear(); rerootedDP.resize(n + 1);

    for (int x = 1; x <= n; x++) {
        int v;
        cin >> v;
        if (v) {
            val[x] = 1;
        } else {
            val[x] = -1;
        }
    }

    for (int x = 0; x < n - 1; x++) {
        int u, v;
        cin >> u >> v;
        tetangga[u].push_back(v);
        tetangga[v].push_back(u);
    }

    dfs(1, -1);
    reroot(1, -1);
    for (int x = 1; x <= n; x++) {
        cout << rerootedDP[x] << " ";
    }
}