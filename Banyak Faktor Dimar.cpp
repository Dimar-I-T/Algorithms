#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

int g(int n){
      int sqr = sqrt(n);
      set<int> faktor;
      for (int x = 1; x <= sqr; x++){
            if (n % x == 0){
                  faktor.insert(x);
                  faktor.insert(n / x);
            }
      }
      
      return faktor.size();
}

int main(){
      int n;
      cin >> n;
      int hasil = 0;
      for (int x = 1; x <= n; x++){
            hasil += g(x);
      }
      
      cout << hasil;
      return 0;
}