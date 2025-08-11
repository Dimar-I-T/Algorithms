#include <bits/stdc++.h>

using namespace std;

vector<int> sudah(1000);
vector<vector<int>> koneksi(1000);
vector<int> banyakGraf(1000);
int indeksGraf = 0;

void DFS(int seb, int sek){
    sudah[sek] = 1;
    int ada = 0;
    vector<int> k = koneksi[sek];
    for (int x = 0; x < k.size(); x++){
        if (k[x] != seb && sudah[k[x]] == 1){
            banyakGraf[indeksGraf]++;
        }else{
            if (sudah[k[x]] == 0){
                DFS(sek, k[x]);
            }
        }
    }

    sudah[sek] = 2;
    return;
}

int main(){
    int n;
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
        int sek = simpul[x];
        if (sudah[sek] == 0){
            sudah[sek] = 1;
            for (int y = 0; y < koneksi[sek].size(); y++){
                if (sudah[koneksi[sek][y]] == 0){
                    DFS(sek, koneksi[sek][y]);
                }
            }

            indeksGraf++;
            cout << "Banyak Cycle Graf " << indeksGraf << " = " << banyakGraf[indeksGraf - 1] << "\n";
        }
    }
}