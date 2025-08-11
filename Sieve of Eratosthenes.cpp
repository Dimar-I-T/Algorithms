#include <bits/stdc++.h>

using namespace std;

vector<int> Prima(int n){
    vector<int> bilanganPrima;
    vector<bool> bukanPrima(n + 1);
    for (int x = 2; x <= n; x++){
        for (int y = x*x; y <= n; y += x){
            bukanPrima[y] = 1;
        }
    }

    for (int x = 0; x <= n; x++){
        if (!bukanPrima[x]){
            bilanganPrima.push_back(x);
            cout << x << " ";
        }
    }

    return bilanganPrima;
}

int main(){
    int n;
    cin >> n;

    vector<int> bilPrim = Prima(n);
}