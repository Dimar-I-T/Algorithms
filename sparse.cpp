#include <bits/stdc++.h>
using namespace std;

int a[400001][50] = {0};
int bin_log[400001] = {0};

int query(int l, int r){
    int length = r - l + 1;
    int k = bin_log[length];
    return a[l][k] & a[r - (1 << k) + 1][k];
}

int main() {
    int t;
    cin >> t;
    bin_log[1] = 0;
    while (t > 0){
        int n;
        cin >> n;
        vector<int> A(n);
        for (int x = 2; x < n + 100; x++){
            bin_log[x] = bin_log[x / 2] + 1;
        }
        
        for (int x = 0; x < n; x++){
            cin >> A[x];
            a[x][0] = A[x];
        }
        
        for (int k = 1; k < 30; k++){
            for (int x = 0; x + (1 << k) - 1 < n; x++){
                a[x][k] = a[x][k - 1] & a[x + (1 << (k - 1))][k - 1];
            }
        }
        
        // for (int x = 0; x < n; x++){
        //     for (int y = 0; y < 18; y++){
        //         cout << a[x][y] << " ";
        //     }
            
        //     cout << "\n";
        // }
        
        int q;
        cin >> q;
        while (q > 0){
            int a, b;
            cin >> a >> b;
            cout << query(a - 1, b - 1) << "\n";
            q--;
        }
        
        t--;
    }
    
}