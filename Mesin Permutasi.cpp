#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
      int n, l;
      cin >> n >> l;
      map<int, map<int, vector<int>>> v;
      vector<map<int, map<int, int>>> kiriNya(n + 1); // kiriNya[n][permNKe-k][angkaDimaksud]
      vector<map<int, map<int, int>>> kananNya(n + 1);
      v[1][0] = {1};
      v[2][0] = {1, 2};
      v[2][1] = {2, 1};
      kiriNya[2][0][2] = 1;
      kananNya[2][1][2] = 1;
      int k = 2;
      
      while (k < n){
            int idx = 0;
            for (int x = 0; x < v[k].size(); x++){
                  if (abs((v[k][x][0] + 1) - 1) > l){
                        continue;
                  }else{
                        v[k + 1][idx].push_back(1);
                        for (int y = 0; y < k; y++){
                              int a = v[k][x][y] + 1;
                              v[k + 1][idx].push_back(a);
                        }
                        
                        idx++;
                  }
            }
            
            int p = 0;
            for (int x = 2; x < k + 1; x++){
                  for (int i = 0; i < v[k].size(); i++){
                        if (abs(v[k][i][0] - (x)) <= l){
                              if (kiriNya[k][i][x] == 0){
                                    if ((abs(x - (k + 1)) > l) || (abs(kananNya[k][i][x] - (k + 1)) > l)){
                                          continue;
                                    }else{
                                          v[k + 1][idx].push_back(x);
                                          for (int y = 0; y < v[k][i].size(); y++){
                                                int a = 0;
                                                if (v[k][i][y] == x){
                                                      a = k + 1;
                                                }else{
                                                      a = v[k][i][y];
                                                }
                                                v[k + 1][idx].push_back(a);
                                          }
                                          
                                          idx++;
                                    }
                              }else{
                                    if ((abs(kiriNya[k][i][x] - (k + 1)) > l) || (abs(kananNya[k][i][x] - (k + 1)) > l && kananNya[k][i][x] != 0)){
                                          continue;
                                    }else{
                                          v[k + 1][idx].push_back(x);
                                          for (int y = 0; y < v[k][i].size(); y++){
                                                int a = 0;
                                                if (v[k][i][y] == x){
                                                      a = k + 1;
                                                }else{
                                                      a = v[k][i][y];
                                                }
                                                v[k + 1][idx].push_back(a);
                                          }
                                          
                                          idx++;
                                    }
                              }  
                        }
                  }
            }
            
            // depan n
            for (int x = 0; x < v[k].size(); x++){
                  if (abs(v[k][x][0] - (k + 1)) <= l){
                        v[k + 1][idx].push_back(k + 1);
                        for (int y = 0; y < v[k][x].size(); y++){
                              v[k + 1][idx].push_back(v[k][x][y]);
                        }
                        
                        idx++;
                  }
            }
            
            for (int x = 0; x < v[k + 1].size(); x++){
                  kananNya[k + 1][x][v[k + 1][x][0]] = v[k + 1][x][1];
                  int ujung = 0, ujung2 = 0;
                  for (int y = 1; y < v[k + 1][x].size() - 1; y++){
                        kiriNya[k + 1][x][v[k + 1][x][y]] = v[k + 1][x][y - 1];
                        kananNya[k + 1][x][v[k + 1][x][y]] = v[k + 1][x][y + 1];
                        ujung = v[k + 1][x][y + 1];
                        ujung2 = v[k + 1][x][y];
                  }
                  kiriNya[k + 1][x][ujung] = ujung2;
            }
            k++;
      }
      
      for (int x = 0; x < v[k].size(); x++){
            for (int y = 0; y < v[k][x].size(); y++){
                  cout << v[k][x][y] << " ";
            }
            cout << "\n";
      }
}