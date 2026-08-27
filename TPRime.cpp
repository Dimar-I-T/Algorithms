#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

bool isPrime(ll n) {
    ll cnt = 0;
    if (n <= 1)
        return 0;
    else {
        for (ll i = 2; i * i <= n; i++) {
            if (n % i == 0)
                cnt++;
        }

        if (cnt > 0)
            return 0;
        else
            return 1;
    }
    
    return 0;
}


void solve() {
    ll n;
    cin >> n;
    ll l = 1, r = n; 
    while (l <= r) {
        ll m = (l + r) / 2;
        ll sqr = m * m;
        if (sqr == n) {
            if (isPrime(m)) {
                cout << "YES\n";    
            } else {
                cout << "NO\n";
            }
            
            return;
        }
        
        if (sqr < n) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    
    cout << "NO\n";
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        solve();   
    }
}