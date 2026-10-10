#include <iostream>
#include <vector>
#define ll long long
using namespace std;

const int MAXN = 5 * 1e4 + 1;
const int MAXK = 501;

vector<vector<int>> adj(MAXN);
vector<vector<int>> dp(MAXN, vector<int>(MAXK));
vector<vector<int>> rootedDP(MAXN, vector<int>(MAXK));

void dfs(int sek, int par, int k) {
    for (int sel : adj[sek]) {
        if (sel == par) {
            continue;
        }
        
        if (k >= 1) {
            dp[sek][k] += dp[sel][k - 1];
        }

        dfs(sel, sek, k);
    }
}

void reroot(int sek, int par, int k) {
    rootedDP[sek][k] = dp[sek][k];
    for (int sel : adj[sek]) {
        if (sel == par) {
            continue;
        }
        
        int sebs = rootedDP[sek][k - 1];
        int sebSel = dp[sel][k];
        
        if (k >= 2) {
            rootedDP[sek][k - 1] -= dp[sel][k - 2];
            dp[sel][k] += rootedDP[sek][k - 1];
        } 

        reroot(sel, sek, k);

        if (k >= 2) {
            rootedDP[sek][k - 1] = sebs;
            dp[sel][k] = sebSel;
        } 
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int x = 0; x < n - 1; x++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        dp[u][0] = 1;
        dp[v][0] = 1;
        rootedDP[u][0] = 1;
        rootedDP[v][0] = 1;
    }
    
    for (int x = 1; x <= k; x++) {
        dfs(1, 0, x);
        if (x == 1) {
            for (int y = 1; y <= n; y++) {
                rootedDP[y][1] = adj[y].size();
            }
        } else {
            reroot(1, 0, x);
        }
    }
    
    ll sum = 0;
    for (int x = 1; x <= n; x++) {
        sum += rootedDP[x][k];
    }

    ll res = sum / 2;
    cout << res;
}
