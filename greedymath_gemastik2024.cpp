#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

const int MAXQ = 2 * 1e5;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, q;
    cin >> n >> q;
    vector<ll> A(n);
    for (ll x = 0; x < n; x++) {
        cin >> A[x];
    }
    
    sort(A.begin(), A.end());
    ll sum = 0;
    for (ll x : A) {
        sum += x;
    }
    
    vector<ll> Q(MAXQ); 
    while (q--) {
        ll x;
        cin >> x;
        if (!Q[x]) {
            int i = n - x;
            ll sumIni = sum;
            while (i >= 0) {
                sumIni -= A[i]/2;
                i -= x;
            }
            
            Q[x] = sumIni;
        }
        
        cout << Q[x] << "\n";
    }
}