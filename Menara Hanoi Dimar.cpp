#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <iostream>
#define ll long long
// Dimar's Hanoi's Tower Algorithm
using namespace std;

int main(){
      int n;
      cin >> n;
      if (n == 1){
            cout << "1 A C";
      }else{
            vector<int> cara = {1, 65, 66, 2, 65, 67, 1, 66, 67};
            if (n == 2){
                  for (int x = 1; x <= cara.size(); x++){
                        if ((x + 2) % 3 == 0){
                              cout << cara[x - 1] << " ";
                        }else{
                              cout << char(cara[x - 1]) << " ";
                        }
                        if (x % 3 == 0){
                              cout << "\n";
                        }
                  }
            }else{
                  map<int, int> atas, bawah;
                  for (int x = 1; x <= n; x++){
                        atas[x] = x;
                        bawah[x] = x;
                  }
                  
                  atas[65] = 65; atas[66] = 67; atas[67] = 66;
                  bawah[66] = 65; bawah[65] = 66; bawah[67] = 67;
                  int k = 2;
                  // operasi
                  while (k < n){
                        vector<int> temp = cara;
                        // atas
                        for (int x = 0; x < cara.size(); x++){
                              cara[x] = atas[cara[x]];
                        }
                        cara.push_back(k + 1);
                        cara.push_back(65);
                        cara.push_back(67);
                        
                        // bawah
                        for (int x = 0; x < temp.size(); x++){
                              cara.push_back(bawah[temp[x]]);
                        }
                        k++;
                  }
                  
                  for (int x = 1; x <= cara.size(); x++){
                        if ((x + 2) % 3 == 0){
                              cout << cara[x - 1] << " ";
                        }else{
                              cout << char(cara[x - 1]) << " ";
                        }
                        if (x % 3 == 0){
                              cout << "\n";
                        }
                  }
            }
      }
}
