#include <bits/stdc++.h>
using namespace std;

vector<int> parent, sz, H;
unordered_map<int, multiset<int>> componentMin;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);  
}

void unite(int a, int b) {
    int rootA = find(a), rootB = find(b);
    if (rootA == rootB) return;

    if (sz[rootA] < sz[rootB]) swap(rootA, rootB); 

    parent[rootB] = rootA;
    sz[rootA] += sz[rootB];

    for (int h : componentMin[rootB]) {
        componentMin[rootA].insert(h);
    }
    componentMin.erase(rootB);
}

void updateH(int u, int newH) {
    int rootU = find(u);
    
    componentMin[rootU].erase(componentMin[rootU].find(H[u]));

    H[u] = newH;
    componentMin[rootU].insert(newH);
}

int query(int u, int v) {
    int rootU = find(u), rootV = find(v);
    if (rootU == rootV) return 0;  
    return *componentMin[rootU].begin() + *componentMin[rootV].begin();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    parent.resize(n + 1);
    sz.assign(n + 1, 1);
    H.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> H[i];
        parent[i] = i;
        componentMin[i].insert(H[i]);
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        unite(a, b);
    }

    for (int i = 0; i < q; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 1) {
            updateH(u, v);
        } else {
            cout << query(u, v) << "\n";
        }
    }

    return 0;
}
