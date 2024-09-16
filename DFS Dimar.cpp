#include <iostream>
#include <map>
#include <vector>
#define ll unsigned long long
// Dimar's Code
using namespace std;

map<ll, ll> waktuMaks;
map<ll, map<ll, ll>> waktu;
map<ll, vector<ll>> hub;
map<ll, bool> visited;

ll DFS(ll di){
    if (visited[di]) {
        return waktuMaks[di];
    }
    
    visited[di] = true;
    
    vector<ll> tetangga = hub[di];
    for (ll x = 0; x < tetangga.size(); x++){
        waktuMaks[di] = max(waktuMaks[di], waktu[di][tetangga[x]] + DFS(tetangga[x]));
    }
    
    return waktuMaks[di];
}

int main(){
    ll n, m;
    cin >> n >> m;
    for (ll x = 0; x < m; x++){
        ll kiri, kanan, t;
        cin >> kiri >> kanan >> t;
        hub[kiri].push_back(kanan);
        waktu[kiri][kanan] = t;
    }
    
    waktuMaks[1] = 0;
    ll hasil = DFS(1);
    if (!visited[n]){
          cout << -1;
    }else{
          cout << hasil;
    }
    
    return 0;
}
