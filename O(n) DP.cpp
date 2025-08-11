#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t > 0){
        int n, k;
        cin >> n >> k;
        vector<int> A(n), B(n + 1), dp(n + 1, INT_MAX);
        for (int x = 0; x < n; x++){
            cin >> A[x];
        }
        
        sort(A.begin(), A.end());
        for (int x = 0; x < n; x++){
            B[x + 1] = A[x];
        }
        
        dp[0] = 0;
        int hasil = INT_MAX;
        for (int x = k; x <= n; x++){
            hasil = min(hasil, dp[x - k] - B[x - k + 1]);
            dp[x] = hasil + B[x];
        }
        
        cout << dp[n] << "\n";
        t--;
    }
}