#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

ll binexp(ll a, ll b, ll m){
    ll result =  1;
    while (b > 0){
        if (b & 1){
            result = (result * 1LL * a) % m;
        }

        a = (a * 1LL * a) % m;
        b >>= 1;
    }

    return result;
}

const ll N = 1e6 + 10;
ll fact[N];

ll combination(ll n, int r){
    ll ans = fact[n];
    ll den = (fact[n - r] * 1LL * fact[r]) % M;
    ans = (1LL* ans * binexp(den, M - 2, M)) % M;
    return ans % M;
}

int main(){
    fact[0] = 1;
    for (ll x = 1; x < N; ++x){
        fact[x] = (fact[x - 1] * 1LL * x) % M;
    }

    ll n, r;
    cin >> n >> r;
    cout << combination(n, r);
}