#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a = -1, b = -1, c = -1;
    int as = -1, bs = -1, cs = -1;
    for (int x = 2; x * x <= n; x++) {
        if (n % x == 0) {
            a = n / x;
            as = x;
            for (int y = x + 1; y * y <= a; y++) {
                if (a % y == 0 && n != as * (as * y) && n != y * (as * y)) {
                    b = a / y;
                    bs = y;
                    break;
                }
            }
            
            break;
        }
    }
    
    cs = n / (as * bs);
    
    if (as == -1 || bs == -1 || cs == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << as << " " <<  bs << " " << cs << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}