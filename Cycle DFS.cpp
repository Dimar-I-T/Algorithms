#include <bits/stdc++.h>

using namespace std;

vector<int> sudah(1000);
vector<vector<int>> koneksi(1000);
bool adaCycle = 0;

void DFS(int seb, int sek){
    sudah[sek] = 1;
    cout << "seb = " << seb << " " << "sek = " << sek << "\n";
    for (int x = 0; x < koneksi[sek].size(); x++){
        if (koneksi[sek][x] != seb && sudah[koneksi[sek][x]] == 1){
            cout << "CYCLE ";
            cout << "sek = " << sek << " t = " << koneksi[sek][x] << "\n";
            adaCycle = 1;
            return;
        }else{
            if (sudah[koneksi[sek][x]] == 0){
                DFS(sek, koneksi[sek][x]);
            }
        }
    }

    sudah[sek] = 2;
}

int main(){
    int n, pertama = -1;
    cin >> n;
    for (int x = 0; x < n; x++){
        int a, b;
        cin >> a >> b;
        if (pertama == -1){
            pertama = a;
        }

        koneksi[a].push_back(b);
        koneksi[b].push_back(a);
    }

    sudah[pertama] = 1;
    for (int x = 0; x < koneksi[pertama].size(); x++){
        if (sudah[koneksi[pertama][x]] == 0){
            DFS(pertama, koneksi[pertama][x]);
        }
    }

    cout << adaCycle;
}