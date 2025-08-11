#include <bits/stdc++.h>
using namespace std;

void permutasi(vector<int> v, vector<int> w, bool bisa){
    if (v.size() == 0){
        for (int x = 1; x < w.size() - 1; x++){
            if (!((w[x] > w[x - 1] && w[x] > w[x + 1]) || (w[x] < w[x - 1] && w[x] < w[x + 1]))){
                bisa = 0;
            }
        }
        
        if (bisa){
            for (auto x: w){
                cout << x;
            }
            
            cout << "\n";
        }
        
        return;
    }
    
    for (auto x: v){
        vector<int> v1, w1;
        for (auto y: w){
            w1.push_back(y);    
        }
        
        for (auto y: v){
            if (y != x){
                v1.push_back(y);
            }
        }
        
        w1.push_back(x);
        int selanjutnya = 1;
        if (w.size() > 2){
            for (int x = 1; x < w.size() - 1; x++){
                if (!((w[x] > w[x - 1] && w[x] > w[x + 1]) || (w[x] < w[x - 1] && w[x] < w[x + 1]))){
                    bisa = 0;
                }
            }
        }
        
        permutasi(v1, w1, bisa);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n), w;
    for (int x = 0; x < n; x++){
        v[x] = x + 1;
    }
    
    permutasi(v, w, 1);
}