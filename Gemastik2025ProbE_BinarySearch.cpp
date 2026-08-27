#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

struct Feri {
    ll c = 0;
    ll l = 0;
    ll s = 0;
    ll u = 0;
    ll r = 0;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, p;
    cin >> n >> p;
    vector<Feri> feriV(n);
    for (ll x = 0; x < n; x++) {
        ll ci, li, si, ui, ri;
        cin >> ci >> li >> si >> ui >> ri;
        feriV[x] = {ci, li, si, ui, ri};
    }
    
    ll l = 0, r = 0.6 * LLONG_MAX;
    ll minT = 0.6 * LLONG_MAX;
    while (l <= r) {
        ll m = (l + r) / 2;
        // m itu detik ke-t tebakan binary search
        ll sumMobil = 0;
        for (ll x = 0; x < n; x++) {
            Feri fi = feriV[x];
            ll wi = fi.l + fi.s + fi.u + fi.r;
            ll ri = fi.r;
            ll ci = fi.c;
            ll bi = (m + ri) / wi;
            ll toti = ci * bi;
            sumMobil += toti;
        }
        
        // kalau sum masih kurang, tambahkan detik -> l ke kanan
        // kalau lebih, kurangin detik -> r ke kiri
        if (sumMobil >= p) {
            r = m - 1;
            minT = min(minT, m);
        } else {
            l = m + 1;
        }
        
    }
    
    cout << minT;
}
