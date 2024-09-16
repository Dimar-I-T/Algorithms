#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main(){
      string s;
      getline(cin, s);
      
      if (s.length() % 2 == 1){
            map<int, map<int, bool>> palindrom;
            int hasil = 0;
            int l = (s.length()/2) - 1, r = (s.length()/2) + 1;
            while (l != -1 && r != s.length()){
                  // cek palindrom utama
                  if (s[l] == s[r]){
                        if (l + 1 == r - 1){
                              hasil++;
                              palindrom[l][r] = 1;
                        }else{
                              if (palindrom[l + 1][r - 1]){
                                    hasil++;
                                    palindrom[l][r] = 1;
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
                              }else{
                                    if (l + 1 == x - 1){
                                          hasil++;
                                          palindrom[l][x] = 1;
                                    }else{
                                          if (palindrom[l + 1][x - 1]){
                                                hasil++;
                                                palindrom[l][x] = 1;
                                          }
                                    }
                              }
                        }
                        
                        // cek kanan
                        if (s[x] == s[r]){
                              if (x + 1 > r - 1){
                                    hasil++;
                                    palindrom[x][r] = 1;
                              }else{
                                    if (r - 1 == x + 1){
                                          hasil++;
                                          palindrom[x][r] = 1;
                                    }else{
                                          if (palindrom[x + 1][r - 1]){
                                                hasil++;
                                                palindrom[x][r] = 1;
                                          }
                                    }
                              }
                        }
                  }
                  
                  l--;
                  r++;
            }
            
            cout << hasil + s.length();
      }else{
            map<int, map<int, bool>> palindrom;
            int hasil = 0;
            if (s[s.length()/2 - 1] == s[s.length()/2]){
                  hasil++;
                  palindrom[s.length()/2 - 1][s.length()/2] = 1;
            }
            
            int l = s.length()/2 - 2, r = s.length()/2 + 1;
            while (l != -1 && r != s.length()){
                  // cek palindrom utama
                  if (s[l] == s[r]){
                        if (l + 1 == r - 1){
                              hasil++;
                              palindrom[l][r] = 1;
                        }else{
                              if (palindrom[l + 1][r - 1]){
                                    hasil++;
                                    palindrom[l][r] = 1;
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
                              }else{
                                    if (l + 1 == x - 1){
                                          hasil++;
                                          palindrom[l][x] = 1;
                                    }else{
                                          if (palindrom[l + 1][x - 1]){
                                                hasil++;
                                                palindrom[l][x] = 1;
                                          }
                                    }
                              }
                        }
                        
                        // cek kanan
                        if (s[x] == s[r]){
                              if (x + 1 > r - 1){
                                    hasil++;
                                    palindrom[x][r] = 1;
                              }else{
                                    if (r - 1 == x + 1){
                                          hasil++;
                                          palindrom[x][r] = 1;
                                    }else{
                                          if (palindrom[x + 1][r - 1]){
                                                hasil++;
                                                palindrom[x][r] = 1;
                                          }
                                    }
                              }
                        }
                  }
                  
                  l--;
                  r++;
            }
            
            cout << hasil + s.length();
      }
      return 0;
}