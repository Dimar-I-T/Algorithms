#include <bits/stdc++.h>
using namespace std;

void permutasi(vector<int> v, vector<int> w){
    if (v.size() == 0){
        for (auto x: w){
            cout << x << " ";
        }
        
        cout << "\n";
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
        permutasi(v1, w1);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n), w;
    for (int x = 0; x < n; x++){
        v[x] = x + 1;
    }
    
    permutasi(v, w);
}