#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, hasil = 0;
    cin >> n;
    if (n == 1){
        hasil = 0;
    }else{
        vector<vector<int>> koneksi(n);
        vector<int> banyakSisiTetangga(n);
        vector<int> panjang(n);
        queue<int> q;
        for (int x = 0; x < n - 1; x++){
            int a, b;
            cin >> a >> b;
            koneksi[a].push_back(b);
            koneksi[b].push_back(a);
            banyakSisiTetangga[a]++;
            banyakSisiTetangga[b]++;
        }
        
        for (int x = 0; x < n; x++){
            if (banyakSisiTetangga[x] == 1){
                q.push(x);
            }
        }
        
        while (n > 2){
            int sek = q.front();
            banyakSisiTetangga[sek]--;
            for (auto x: koneksi[sek]){
                if (banyakSisiTetangga[x] > 0){
                    panjang[x] = max(panjang[x], panjang[sek] + 1);
                    banyakSisiTetangga[x]--;
                }    
                
                if (banyakSisiTetangga[x] == 1){
                    q.push(x);
                }
            }
            
            q.pop();
            n--;
        }
        
        while (!q.empty()){
            hasil += panjang[q.front()];
            q.pop();
        }
        
        cout << hasil + 1;
    }
}