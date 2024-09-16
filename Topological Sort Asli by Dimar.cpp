#include <bits/stdc++.h>
using namespace std;
// Dimar's Topological Sort Algorithm
vector<vector<int>> koneksi(50001);
vector<int> pernah(50001), b(50001), hasil;
bool adaCycle = 0;
void TS(int s){
    pernah[s] = 1;
    vector<int> koneksi1 = koneksi[s];
    for (int x = 0; x < koneksi1.size(); x++){
        if (pernah[koneksi1[x]] == 1){
            adaCycle = 1;
            break;
        }
        
        if (pernah[koneksi1[x]] != 2){
            TS(koneksi1[x]);
        }
    }
    
    if (adaCycle){
        return;
    }
    
    pernah[s] = 2;
    hasil.push_back(s);
}

int main(){
    int n, m;
    cin >> n >> m;
    unordered_map<int, bool> ada;
    for (int x = 0; x < m; x++){
        int kiri, kanan;
        cin >> kiri >> kanan;
        ada[kiri] = 1; ada[kanan] = 1;
        koneksi[kiri].push_back(kanan);
        b[kanan]++;
    }
    
    for (int x = 1; x <= n; x++){
        if (!ada[x]){
            hasil.push_back(x);
        }else{
            if (pernah[x] == 0 ){
                TS(x);
                if (adaCycle){
                    break;
                }
            }
        }
    }
    
    if (adaCycle || hasil.size() == 0){
        for (int x = 0; x < n; x++){
            cout << "-1 ";
        }
    }else{
        for (int x = 0; x < hasil.size(); x++){
            cout << hasil[hasil.size() - 1 - x] << " ";
        }
    }
}
