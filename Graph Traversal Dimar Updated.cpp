#include <iostream>
#include <map>
#include <vector>
// Dimar's Graph Traversal Algorithm

using namespace std;

int Maks(int a, int b){
      if (a > b){
            return a;
      }else{
            return b;
      }
}

bool Min(int kiri, int kanan){
      if (kiri < kanan){
            return 0;
      }else{
            return 1;
      }
}

int main(){
      int n;
      cin >> n;
      map<int, vector<int>> kananKiri;
      for (int x = 0; x < n - 1; x++){
            vector<int> kiriKanan(2);
            cin >> kiriKanan[0] >> kiriKanan[1];
            bool idx = Min(kiriKanan[0], kiriKanan[1]);
            int kiriAs = kiriKanan[idx];
            int kananAs = kiriKanan[!idx];
            kananKiri[kananAs].push_back(kiriAs);
      }
      
      int hasil = 0;
      map<int, vector<vector<int>>> jalan;
      jalan[1] = {{1}};
      for (int x = 2; x <= n; x++){
            for (int y = 0; y < kananKiri[x].size(); y++){
                  for (int z = 0; z < jalan[kananKiri[x][y]].size(); z++){
                        vector<int> jalanSem;
                        jalanSem = jalan[kananKiri[x][y]][z];
                        jalanSem.push_back(x);
                        jalan[x].push_back(jalanSem);
                        hasil = Maks(hasil, jalanSem.size() - 1);
                  }
            }
      }
      
      cout << hasil;
}