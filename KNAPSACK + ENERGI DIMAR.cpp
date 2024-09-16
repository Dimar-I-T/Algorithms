#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, u;
    cin >> n >> u;
    vector<int> A(n + 1);
    vector<int> beda(n + 1);
    vector<int> X(n + 1);
    int minA = 1001;
    
    for (int x = 0; x < n; x++){
        int a, b, p;
        cin >> a >> b >> p;
        A[x + 1] = a;
        beda[x + 1] = a - b;
        X[x + 1] = p;
        minA = min(minA, a); 
    }
    
    vector<vector<int>> dp(u + 1);
    vector<vector<int>> E(u + 1);
    for (int x = 0; x < u + 1; x++){
        vector<int> isi(n + 1);
        dp[x] = isi;
        E[x] = isi;
    }
    
    for (int en = 0; en <= u; en++){
        for (int x = 1; x <= n; x++){
            if (en >= A[x]){
                if (dp[en - beda[x]][n] + X[x] > dp[en][x - 1]){
                    dp[en][x] = dp[en - beda[x]][n] + X[x];
                    E[en][x] = E[en - beda[x]][n];
                }else{
                      if (dp[en - beda[x]][n] + X[x] == dp[en][x - 1]){
                              if (E[en - beda[x]][n] > E[en][x - 1]){
                                    E[en][x] = E[en - beda[x]][n];
                              }else{
                                    E[en][x] = E[en][x - 1];
                              }
                        }else if (dp[en - beda[x]][n] + X[x] < dp[en][x - 1]){
                              E[en][x] = E[en][x - 1];
                        }
                        
                        dp[en][x] = dp[en][x - 1];
                }
            }else{
                  E[en][x] = E[en][x - 1];
                  dp[en][x] = dp[en][x - 1];
            }
            
            if (en < minA){
                E[en][x] = en; 
            }
        }
    }

    cout << dp[u][n] << " " << E[u][n]; 
}