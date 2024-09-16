#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
// Dimar's Graph Traversal Algorithm

using namespace std;

int main(){
      int n, m;
      cin >> n >> m;
      map<int, vector<int>> kananKiri; 
      for (int x = 0; x < m; x++){
            int kiri, kanan;
            cin >> kiri >> kanan;
            kananKiri[kanan].push_back(kiri);
      }
      
      vector<int> awal = {1};
      map<int, vector<vector<int>>> jalan;
      jalan[1] = {{1}};
      for (int x = 2; x <= n; x++){
            for (int y = 0; y < kananKiri[x].size(); y++){
                  for (int z = 0; z < jalan[kananKiri[x][y]].size(); z++){
                        vector<int> jalanSem;
                        jalanSem = jalan[kananKiri[x][y]][z];
                        jalanSem.push_back(x);
                        jalan[x].push_back(jalanSem);
                  }
            }
      }
      
      for (int x = 0; x < jalan[n].size(); x++){
            for (int y = 0; y < jalan[n][x].size(); y++){
                  cout << jalan[n][x][y] << " ";
            }
            cout << "\n";
      }
}