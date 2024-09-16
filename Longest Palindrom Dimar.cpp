#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
// Dimar's Longest Palindrome Algorithm
using namespace std;

int main(){
      string s;
      getline(cin, s);
      
      if (s.length() % 2 == 1){
            map<int, vector<int>> interval;
            map<int, map<int, bool>> palindrom;
            int hasil = 0;
            int l = (s.length()/2) - 1, r = (s.length()/2) + 1;
            while (l != -1 && r != s.length()){
                  // cek palindrom utama
                  if (s[l] == s[r]){
                        if (l + 1 == r - 1){
                              hasil++;
                              palindrom[l][r] = 1;
                              interval[abs(l - r)].push_back(l);
                              interval[abs(l - r)].push_back(r);
                        }else{
                              if (palindrom[l + 1][r - 1]){
                                    hasil++;
                                    palindrom[l][r] = 1;
                                    interval[abs(l - r)].push_back(l);
                                    interval[abs(l - r)].push_back(r);
                              }
                        }
                  }
                  
                  // cek sisa
                  for (int x = l + 1; x <= r - 1; x++){
                        // cek kiri
                        if (s[l] == s[x]){
                              if (l + 1 > x - 1){
                                    hasil++;
                                    palindrom[l][x] = 1;
                                    interval[abs(l - x)].push_back(l);
                                    interval[abs(l - x)].push_back(x);
                              }else{
                                    if (l + 1 == x - 1){
                                          hasil++;
                                          palindrom[l][x] = 1;
                                          interval[abs(l - x)].push_back(l);
                                          interval[abs(l - x)].push_back(x);
                                    }else{
                                          if (palindrom[l + 1][x - 1]){
                                                hasil++;
                                                palindrom[l][x] = 1;
                                                interval[abs(l - x)].push_back(l);
                                                interval[abs(l - x)].push_back(x);
                                          }
                                    }
                              }
                        }
                        
                        // cek kanan
                        if (s[x] == s[r]){
                              if (x + 1 > r - 1){
                                    hasil++;
                                    palindrom[x][r] = 1;
                                    interval[abs(x - r)].push_back(x);
                                    interval[abs(x - r)].push_back(r);
                              }else{
                                    if (r - 1 == x + 1){
                                          hasil++;
                                          palindrom[x][r] = 1;
                                          interval[abs(x - r)].push_back(x);
                                          interval[abs(x - r)].push_back(r);
                                    }else{
                                          if (palindrom[x + 1][r - 1]){
                                                hasil++;
                                                palindrom[x][r] = 1;
                                                interval[abs(x - r)].push_back(x);
                                                interval[abs(x - r)].push_back(r);
                                          }
                                    }
                              }
                        }
                  }
                  
                  l--;
                  r++;
            }
            
            bool ada = false;
            for (int x = s.length() - 1; x >= 0; x--){
                  if (interval[x].size() != 0){
                        ada = true;
                        cout << s.substr(interval[x][0], x + 1);
                        break;
                  }
            }
            
            if (!ada){
                  cout << s[0];
            }
      }else{
            map<int, vector<int>> interval;
            map<int, map<int, bool>> palindrom;
            int hasil = 0;
            if (s[s.length()/2 - 1] == s[s.length()/2]){
                  hasil++;
                  palindrom[s.length()/2 - 1][s.length()/2] = 1;
                  interval[1].push_back(s.length()/2 - 1);
                  interval[1].push_back(s.length()/2);
            }
            
            int l = s.length()/2 - 2, r = s.length()/2 + 1;
            while (l != -1 && r != s.length()){
                  // cek palindrom utama
                  if (s[l] == s[r]){
                        if (l + 1 == r - 1){
                              hasil++;
                              palindrom[l][r] = 1;
                              interval[abs(l - r)].push_back(l);
                              interval[abs(l - r)].push_back(r);
                        }else{
                              if (palindrom[l + 1][r - 1]){
                                    hasil++;
                                    palindrom[l][r] = 1;
                                    interval[abs(l - r)].push_back(l);
                                    interval[abs(l - r)].push_back(r);
                              }
                        }
                  }
                  
                  // cek sisa
                  for (int x = l + 1; x <= r - 1; x++){
                        // cek kiri
                        if (s[l] == s[x]){
                              if (l + 1 > x - 1){
                                    hasil++;
                                    palindrom[l][x] = 1;
                                    interval[abs(l - x)].push_back(l);
                                    interval[abs(l - x)].push_back(x);
                              }else{
                                    if (l + 1 == x - 1){
                                          hasil++;
                                          palindrom[l][x] = 1;
                                          interval[abs(l - x)].push_back(l);
                                          interval[abs(l - x)].push_back(x);
                                    }else{
                                          if (palindrom[l + 1][x - 1]){
                                                hasil++;
                                                palindrom[l][x] = 1;
                                                interval[abs(l - x)].push_back(l);
                                                interval[abs(l - x)].push_back(x);
                                          }
                                    }
                              }
                        }
                        
                        // cek kanan
                        if (s[x] == s[r]){
                              if (x + 1 > r - 1){
                                    hasil++;
                                    palindrom[x][r] = 1;
                                    interval[abs(x - r)].push_back(x);
                                    interval[abs(x - r)].push_back(r);
                              }else{
                                    if (r - 1 == x + 1){
                                          hasil++;
                                          palindrom[x][r] = 1;
                                          interval[abs(x - r)].push_back(x);
                                          interval[abs(x - r)].push_back(r);
                                    }else{
                                          if (palindrom[x + 1][r - 1]){
                                                hasil++;
                                                palindrom[x][r] = 1;
                                                interval[abs(x - r)].push_back(x);
                                                interval[abs(x - r)].push_back(r);
                                          }
                                    }
                              }
                        }
                  }
                  
                  l--;
                  r++;
            }
            
            bool ada = false;
            for (int x = s.length() - 1; x >= 0; x--){
                  if (interval[x].size() != 0){
                        ada = true;
                        cout << s.substr(interval[x][0], x + 1);
                        break;
                  }
            }
            
            if (!ada){
                  cout << s[0];
            }
      }
}
