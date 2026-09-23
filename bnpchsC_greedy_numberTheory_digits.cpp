#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    vector<ll> sepPangkat(11);
    sepPangkat[0] = 1;
    for (int x = 1; x < 11; x++) {
        sepPangkat[x] = 10 * sepPangkat[x - 1];
    }
    
    ll n, k;
    cin >> n >> k;
    vector<ll> A(n);
    for (int x = 0; x < n; x++) {
        cin >> A[x];
    }
    
    sort(A.rbegin(), A.rend());
    ll digit = 10;
    while (digit > 0 && k > 0) {
        // jika digit d -> artinya ada d digit, artinya cek pembagian dengan 10^(d - 1)
        ll sep = sepPangkat[digit - 1];
        for (ll& a : A) {
            // cek dulu atleast d digit
            string s = to_string(a);
            ll banyakD = s.length();
            if (banyakD < digit) {
                continue;
            }
            
            ll digitSek = (a - (a / sepPangkat[digit]) * sepPangkat[digit]) / sepPangkat[digit - 1];
            ll tambahKanDigit = 9 - digitSek;
            if (k < tambahKanDigit) {
                tambahKanDigit = k;    
            }
            
            k -= tambahKanDigit;
            ll tambahKanSemua = tambahKanDigit * sepPangkat[digit - 1];
            a += tambahKanSemua;
        }
        
        digit--;
    }
    
    if (k > 0) {
        ll ubahDigitJadi = (9 + k) % 10;
        A[0] -= 9;
        A[0] += ubahDigitJadi;
    }
    
    ll res = 0;
    for (ll a : A) {
        res += a;
    }
    
    cout << res;
}