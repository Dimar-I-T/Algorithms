#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 3 * 1e5;

vector<ll> K(MAXN);
vector<vector<ll>> adj(MAXN);
vector<ll> maxSumRaw(MAXN);
vector<pair<ll, ll>> maxRooted(MAXN);
vector<ll> sumPosV(MAXN);
vector<ll> sumNegV(MAXN);
// first positif, second negatif
vector<pair<ll, ll>> sumPosNegV(MAXN);

void dfs(ll sek, ll par) {
    vector<ll> selV = adj[sek];
    sumPosNegV[sek].first = K[sek];
    sumPosNegV[sek].second= K[sek];
    for (ll sel : selV) {
        if (sel == par) {
            continue;
        }
        
        dfs(sel, sek);
        if (sumPosNegV[sel].first > 0) {
            sumPosNegV[sek].first += sumPosNegV[sel].first;
        }

        if (sumPosNegV[sel].second < 0) {
            sumPosNegV[sek].second += sumPosNegV[sel].second;
        }
    }
}

void reroot(ll sek, ll par) {
    maxRooted[sek] = sumPosNegV[sek];
    for (ll g : adj[sek]) {
        if (g == par) {
            continue;
        }
        
        ll posSebSek = sumPosNegV[sek].first;
        ll negSebSek = sumPosNegV[sek].second;
        ll posSebg = sumPosNegV[g].first;
        ll negSebg = sumPosNegV[g].second;

        if (sumPosNegV[g].first > 0) {
            sumPosNegV[sek].first -= sumPosNegV[g].first;
        }

        if (sumPosNegV[g].second < 0) {
            sumPosNegV[sek].second -= sumPosNegV[g].second;
        }

        if (sumPosNegV[sek].first > 0) {
            sumPosNegV[g].first += sumPosNegV[sek].first;
        }

        if (sumPosNegV[sek].second < 0) {
            sumPosNegV[g].second += sumPosNegV[sek].second;
        }

        reroot(g, sek);

        sumPosNegV[sek].first = posSebSek;
        sumPosNegV[sek].second = negSebSek;
        sumPosNegV[g].first = posSebg;
        sumPosNegV[g].second = negSebg;
    }
}


int main() {
    ll n;
    cin >> n;
    for (ll x = 1; x <= n; x++) {
        cin >> K[x];
    }
    
    for (ll x = 0; x < n - 1; x++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, 0);
    reroot(1, 0);
    for (ll x = 1; x <= n; x++) {
        cout << max(abs(maxRooted[x].first), abs(maxRooted[x].second)) << " ";
    }
}