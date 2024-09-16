#include <iostream>
#include <vector>
#include <algorithm>
#define mp make_pair
#define f first
#define s second
// Dimar's Code
using namespace std;
vector<vector<int>> tetangga(100001);
vector<bool> sudah(100001);
vector<int> jarak(100001);
vector<int> jarakMulai(1);
int mulai = 0, a = 0;

void DFS(int di){
      if (!sudah[di]){
            sudah[di] = true;
            for (int x = 0; x < tetangga[di].size(); x++){
                  int sek = tetangga[di][x];
                  if (!sudah[sek]){
                        jarak[sek] = jarak[di] + 1;
                        jarakMulai[a] = max(jarakMulai[a], jarak[sek]);
                        DFS(sek);
                  }
                  
                  if (di == mulai){
                        a++;
                        jarakMulai.push_back(0);
                  }
            }
      }
}

int main(){
      int n;
      cin >> n;
      
      for (int x = 0; x < n - 1; x++){
            int kiri, kanan;
            cin >> kiri >> kanan;
            tetangga[kiri].push_back(kanan);
            tetangga[kanan].push_back(kiri);
      }
      
      for (int x = 1; x <= n; x++){
            if (tetangga[x].size() > 1){
                  mulai = x;
                  break;
            }
      }
      
      DFS(mulai);
      sort(jarakMulai.begin(), jarakMulai.end());
      if (n == 2){
            cout << 1;
      }else{
            cout << jarakMulai[jarakMulai.size() - 1] + jarakMulai[jarakMulai.size() - 2];
      }
}
