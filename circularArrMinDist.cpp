#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> A(n);
    for (ll x = 0; x < n; x++) {
        ll ai;
        cin >> ai;
        ai %= m;
        A[x] = {ai, x + 1};
    }
    
    sort(A.begin(), A.end(), cmp);
    ll dist = abs(A[0].first - A[1].first);
    pair<ll, ll> hasil = {A[0].second, A[1].second};
    for (ll x = 0; x < n - 1; x++) {
        pair<ll, ll> curr = A[x];
        pair<ll, ll> next = A[x + 1];
        ll distSek = abs(curr.first - next.first);
        if (dist > distSek) {
            dist = distSek;
            hasil = {curr.second, next.second};
        }
    }
    
    // jarak paling ujung dan paling awal

    ll distSek = abs(A[n - 1].first - m) + A[0].first;
    if (dist > distSek) {
        hasil = {A[0].second, A[n - 1].second}; 
    }
    
    cout << hasil.first << " " << hasil.second;
}
