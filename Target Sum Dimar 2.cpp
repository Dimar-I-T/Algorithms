#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(){
      int n, target;
      cin >> n >> target;     // Dimar's Code
      vector<int> a(n);
      for (int x = 0; x < n; x++){
            cin >> a[x];
      }
      
      sort(a.begin(), a.end());
      vector<map<int, map<int, int>>> dp(target + 1);
      map<int, int> mB;
      for (int x = 1; x < n; x++){
            if (a[x] == a[x - 1]){
                  mB[x] = mB[x - 1] + 1;
            }else{
                  mB[x] = 0;
            }
      }
      
      for (int x = 0; x < dp.size(); x++){
            for (int y = 0; y < n; y++){
                  dp[x][a[y]][mB[y]] = 0;
            }
      }
      
      for (int x = 0; x < n; x++){
            dp[0][a[x]][mB[x]] = 1;
      }
      
      for (int x = 1; x <= target; x++){
            for (int y = 0; y < n; y++){
                  if (x == a[y]){
                        dp[x][a[y]][mB[y]] = dp[x][a[y - 1]][mB[y - 1]] + 1;
                  }else if (x < a[y]){
                        dp[x][a[y]][mB[y]] = dp[x][a[y - 1]][mB[y - 1]];
                  }else if (x > a[y]){
                        int t = dp[x - a[y]][a[n - 1]][mB[n - 1]] - dp[x - a[y]][a[y]][mB[y]];
                        dp[x][a[y]][mB[y]] = dp[x][a[y - 1]][mB[y - 1]] + t;
                  }
            }
      }
      
      cout << dp[target][a[n - 1]][mB[n - 1]];
      return 0;
}



