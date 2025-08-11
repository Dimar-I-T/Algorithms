#include <bits/stdc++.h>

using namespace std;

int main() {
    int p;
    cin >> p;
    for (long long x = 0; x < p; x++){
        long long m, n, k;
        cin >> m >> n >> k;
        vector<long long> lantai(m);
        for (long long y = 0; y < m; y++){
            cin >> lantai[y];
        }
        
        sort(lantai.begin(), lantai.end());
        long long hasil = 0;
        for (long long y = 0; y < k; y++){
            hasil += (n - lantai[y]);
        }
        
        for (long long y = k; y < m; y++){
            hasil += lantai[y];
        }
        
        cout << hasil << "\n";
    }
}