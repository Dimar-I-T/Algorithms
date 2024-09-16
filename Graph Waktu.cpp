#include <iostream>
#include <map>
#include <vector>
#define ll unsigned long long
// Dimar's Graph Traversal Algorithm

using namespace std;

int main(){
      int n, m;
      cin >> n >> m;
      map<int, vector<int>> kananKiri; 
      vector<map<int, int>> kiriKananWaktu(100001);
      for (int x = 0; x < m; x++){
            int kiri, kanan, waktu;
            cin >> kiri >> kanan >> waktu;
            kananKiri[kanan].push_back(kiri);
            kiriKananWaktu[kiri][kanan] = waktu;
      }
      
      map<int, vector<vector<int>>> jalan;
      map<vector<int>, int> waktu;
      jalan[1] = {{1}};
      waktu[jalan[1][0]] = 0;
      for (int x = 2; x <= n; x++){
            for (int y = 0; y < kananKiri[x].size(); y++){
                  for (int z = 0; z < jalan[kananKiri[x][y]].size(); z++){
                        vector<int> jalanSem;
                        jalanSem = jalan[kananKiri[x][y]][z];
                        jalanSem.push_back(x);
                        jalan[x].push_back(jalanSem);
                        waktu[jalanSem] = waktu[jalan[kananKiri[x][y]][z]] +
                        kiriKananWaktu[jalanSem[jalanSem.size() - 2]][jalanSem[jalanSem.size() - 1]];
                  }
            }
      }
      
      if (jalan[n].size() == 0){
            cout << "-1";
      }else{
            ll hasil = waktu[jalan[n][0]];
            for (int x = 1; x < jalan[n].size(); x++){
                  if (hasil < waktu[jalan[n][x]]){
                        hasil = waktu[jalan[n][x]];
                  }
            }
            
            cout << hasil;
      }
      
      
}