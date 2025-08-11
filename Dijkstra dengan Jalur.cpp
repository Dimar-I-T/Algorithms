#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

vector<vector<pair<int, int>>> koneksi(5000);
vector<pair<int, int>> jarak(5001);
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
            if (jarak[kon[x].f].f > kon[x].s + jarak[p.s].f){
                jarak[kon[x].f].f = kon[x].s + jarak[p.s].f;
                jarak[kon[x].f].s = p.s;
            }
            
            pq.push({-1 * jarak[kon[x].f].f, kon[x].f});
        }
        
        cout << "\n";
        sudah[p.s] = 1;
        pq.pop();
    }
}

void PrintJalur(int dari, int ke){
    vector<bool> sudah(dari + 1);
    queue<int> q;
    q.push(ke);
    string kebalik = "";
    while (!q.empty()){
        if (sudah[q.front()]){
            break;
        }
        
        sudah[q.front()] = 1;
        kebalik += to_string(q.front()) + " >- ";
        q.push(jarak[q.front()].s);
        q.pop();
    }
    
    cout << "Jarak dari " << dari << " ke " << ke << " = " << jarak[ke].f << "\n";
    cout << "Jalur dari " << dari << ": ";
    for (int x = 3; x < kebalik.length(); x++){
        cout << kebalik[kebalik.length() - x - 1];
    }    
    
    cout << "\n";
}

int main() {
    int n, m, mulaiDari;
    cin >> n >> m >> mulaiDari;
    for (int x = 0; x < m; x++){
        int a, b, jarakAB;
        cin >> a >> b >> jarakAB;
        koneksi[a].push_back({b, jarakAB});
        koneksi[b].push_back({a, jarakAB});
        
        jarak[a].f = INT_MAX;
        jarak[b].f = INT_MAX;
    }
    
    jarak[mulaiDari].f = 0;
    BFS(mulaiDari);
    for (int x = 0; x < n; x++){
        PrintJalur(mulaiDari, x);
    }
}
