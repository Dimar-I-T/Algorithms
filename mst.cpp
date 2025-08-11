#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    priority_queue<pair<int, pair<int, int>>> pq;
    for (int x = 0; x < m; x++){
        int a, b, jarak;
        cin >> a >> b >> jarak;
        pq.push({-jarak, {a, b}});
    }

    vector<set<int>> hubungan(n);
    for (int x = 0; x < n; x++){
        hubungan[x].insert(x);
    }

    int hasil = 0, banyak = 0;
    while (!pq.empty()){
        if (banyak == n - 1){
            break;
        }

        pair<int, pair<int, int>> p = pq.top();
        int a = p.s.f, b = p.s.s, j = -p.f;
        if (hubungan[a] != hubungan[b]){
            hasil += j;
            banyak++;
            set<int> temp = hubungan[a];
            hubungan[a].insert(hubungan[b].begin(), hubungan[b].end());
            hubungan[b].insert(temp.begin(), temp.end());
        }

        pq.pop();
    }

    cout << hasil;
}