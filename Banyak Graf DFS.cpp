#include <bits/stdc++.h>

using namespace std;

vector<bool> sudah(1000);
vector<vector<int>> koneksi(1000);

void DFS(int sek){
    sudah[sek] = 1;
    for (int x = 0; x < koneksi[sek].size(); x++){
        if (sudah[koneksi[sek][x]] == 0){
            DFS(koneksi[sek][x]);
        }
    }
}

int main(){
    int n, banyakGraf = 0;
    cin >> n;
    vector<int> simpul;
    for (int x = 0; x < n; x++){
        int a, b;
        cin >> a >> b;
        if (koneksi[a].size() == 0){
            simpul.push_back(a);
        }

        if (koneksi[b].size() == 0){
            simpul.push_back(b);
        }

        koneksi[a].push_back(b);
        koneksi[b].push_back(a);
    }

    for (int x = 0; x < simpul.size(); x++){
        if (!sudah[simpul[x]]){
            DFS(simpul[x]);
            banyakGraf++;
        }
    }

    cout << banyakGraf;
}