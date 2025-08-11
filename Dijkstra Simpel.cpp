#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

vector<vector<pair<int, int>>> koneksi(5000);
vector<int> jarak(5001);
vector<bool> sudah(5000);

void BFS(int mulaiDari){
    // {shortest distance, node sekarang}
    priority_queue<pair<int, int>> pq;
    pq.push({0, mulaiDari});
    
    while (!pq.empty()){
        pair<int, int> p = pq.top();
        cout << "Node ke-" << p.s << "\n";
        vector<pair<int, int>> kon = koneksi[p.s];
        for (int x = 0; x < kon.size(); x++){
            if (sudah[kon[x].f]){
                continue;
            }
            
            cout << "Node koneksinya: " << kon[x].f << "\n";
            jarak[kon[x].f] = min(jarak[kon[x].f], kon[x].s + jarak[p.s]);
            pq.push({-1 * jarak[kon[x].f], kon[x].f});
        }
        
        cout << "\n";
        sudah[p.s] = 1;
        pq.pop();
    }
}

int main() {
    int n, m, mulaiDari;
    cin >> n >> m >> mulaiDari;
    for (int x = 0; x < m; x++){
        int a, b, jarakAB;
        cin >> a >> b >> jarakAB;
        koneksi[a].push_back({b, jarakAB});
        koneksi[b].push_back({a, jarakAB});
        
        jarak[a] = INT_MAX;
        jarak[b] = INT_MAX;
    }
    
    jarak[mulaiDari] = 0;
    BFS(mulaiDari);
    for (int x = 0; x < n; x++){
        cout << "Jarak dari " << mulaiDari << " ke " << x << " = " << jarak[x] << "\n";
    }
}
