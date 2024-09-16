#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
// Dimar's Code
using namespace std;

int Min(int a, int b){
      if (a < b){
            return a;
      }else{
            return b;
      }
}

int Maks(int a, int b){
      if (a > b){
            return a;
      }else{
            return b;
      }
}

int Menit(string b, string a){
      int sama = 0;
      for (int x = 0; x < Min(b.length(), a.length()); x++){
            if (b[x] == a[x]){
                  sama++;
            }
      }
      
      return Maks(b.length() - sama, a.length() - sama);
}

int main() {
      int t, n;
      cin >> t >> n;
      vector<vector<string>> sba;
      int l = n;
      while (l > 0){
            vector<string> ba(3);
            for (int x = 0; x < 3; x++){
                  cin >> ba[x];
            }
            sba.push_back(ba);
            l--;
      }
      
      vector<int> nilaiMenit(n);
      vector<int> idxKeTK(n);
      for (int x = 0; x < n; x++){
            nilaiMenit[x] = Menit(sba[x][0], sba[x][1]);
            idxKeTK[x] = stoi(sba[x][2]);
      }
      int minWaktu = nilaiMenit[0];
      int idx = 0;
      for (int x = 1; x < n; x++){
            if (minWaktu > nilaiMenit[x]){
                  minWaktu = nilaiMenit[x];
                  idx = x;
            }
      }
      
      if (minWaktu <= t){
            int dp[t][n];
            dp[0][0] = idxKeTK[idx];
            int a = 1;
            vector<int> nilaiDP;
            nilaiDP.push_back(idxKeTK[idx]);
            vector<vector<int>> Row_Angka(t);
            for (int x = 0; x < t; x++){
                  for (int y = 0; y < n; y++){
                        Row_Angka[x].push_back(0);
                  }
            }
            Row_Angka[0][idx] = 1;
            vector<vector<int>> nilaiRow_Angka;
            nilaiRow_Angka.push_back(Row_Angka[0]);
            for (int x = 0; x < t; x++){
                  for (int y = 0; y < n; y++){
                        if (x == 0 && y == 0){
                              continue;
                        }
                        // f(l), f(x + 1 - l) + f(l) jika F(l) != 0, dp sebelumnya
                        if ((x + 1) - nilaiMenit[y] < 0){
                              dp[x][y] = nilaiDP[a - 1];
                              nilaiDP.push_back(dp[x][y]);
                              Row_Angka[x] = nilaiRow_Angka[a - 1];
                              nilaiRow_Angka.push_back(Row_Angka[x]);
                        }else if ((x + 1) - nilaiMenit[y] > 0){
                              if (dp[x - nilaiMenit[y]][n - 1] + idxKeTK[y] > nilaiDP[a - 1]){
                                    if (Row_Angka[x - nilaiMenit[y]][y] == 0){
                                          dp[x][y] = dp[x - nilaiMenit[y]][n - 1] + idxKeTK[y];
                                          Row_Angka[x] = Row_Angka[x - nilaiMenit[y]];
                                          Row_Angka[x][y] = 1;
                                          nilaiDP.push_back(dp[x][y]);
                                          nilaiRow_Angka.push_back(Row_Angka[x]);
                                    }else{
                                          dp[x][y] = nilaiDP[a - 1];
                                          nilaiDP.push_back(dp[x][y]);
                                          Row_Angka[x] = nilaiRow_Angka[a - 1];
                                          nilaiRow_Angka.push_back(Row_Angka[x]);
                                    }
                              }else{
                                    dp[x][y] = nilaiDP[a - 1];
                                    nilaiDP.push_back(dp[x][y]);
                                    Row_Angka[x] = nilaiRow_Angka[a - 1];
                                    nilaiRow_Angka.push_back(Row_Angka[x]);
                              }
                        }else if ((x + 1) - nilaiMenit[y] == 0){
                              if (idxKeTK[y] > nilaiDP[a - 1]){
                                    dp[x][y] = idxKeTK[y];
                                    nilaiDP.push_back(idxKeTK[y]);
                                    Row_Angka[x][y] = 1;
                                    nilaiRow_Angka.push_back(Row_Angka[x]);
                              }else{
                                    dp[x][y] = nilaiDP[a - 1];
                                    nilaiDP.push_back(dp[x][y]);
                                    Row_Angka[x] = nilaiRow_Angka[a - 1];
                                    nilaiRow_Angka.push_back(Row_Angka[x]);
                              }
                        }
                        a++;
                  }
            }
            
            cout << dp[t - 1][n - 1];
      }else{
            cout << 0;
      }
      
	return 0;
}
