#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
// Dimar's Code
using namespace std;

int main(){
      int n, target;
      cin >> n >> target;
      vector<int> a(n);
      for (int x = 0; x < n; x++){
            cin >> a[x];
      }
      
      sort(a.begin(), a.end());
      vector<map<int, int>> dp(target + 1);
      for (int x = 0; x < dp.size(); x++){
            for (int y = 0; y < n; y++){
                  dp[x][a[y]] = 0;
            }
      }
      
      for (int x = 0; x < n; x++){
            dp[0][a[x]] = 1;
      }
      
      for (int x = 1; x <= target; x++){
            for (int y = 0; y < n; y++){
                  if (x == a[y]){
                        dp[x][a[y]] = dp[x][a[y - 1]] + 1;
                  }else if (x < a[y]){
                        dp[x][a[y]] = dp[x][a[y - 1]];
                  }else if (x > a[y]){
                        int t = dp[x - a[y]][a[n - 1]] - dp[x - a[y]][a[y]];
                        dp[x][a[y]] = dp[x][a[y - 1]] + t;
                  }
            }
      }
      
      cout << dp[target][a[n - 1]];
      return 0;
}
