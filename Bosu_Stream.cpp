#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
      string s;
      cin >> s;
      int sem = 0;
      int hasil = 1;
      for (int x = 1; x < s.length(); x++){
            if ((s[x - 1] == 'x' && s[x] == 'z') || (s[x - 1] == 'z' && s[x] == 'x')){
                  sem++;
            }else{
                  if (sem > 0){
                        hasil = max(hasil, sem + 1);
                  }
                  
                  sem = 0;
            }
      }
      
      if (sem > 0){
            hasil = max(hasil, sem + 1);
      }
      
      cout << hasil;
}