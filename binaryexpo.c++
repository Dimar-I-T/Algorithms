#include <bits/stdc++.h>

using namespace std;

string binerKebalik(int p){
    if (p == 0){
        return "";
    }else{
        return to_string(p % 2) + binerKebalik(p / 2);
    }
}

// Dimar's binary exponent
int main(){
    int n, p;
    cin >> n >> p;
    string binerKebalikSem = binerKebalik(p);
    int l = binerKebalikSem.length();
    int nPangkatDuaPangkat[l];
    nPangkatDuaPangkat[0] = n;
    for (int x = 1; x < l; x++){
        nPangkatDuaPangkat[x] = nPangkatDuaPangkat[x - 1]*nPangkatDuaPangkat[x - 1];
    }

    int hasilPangkat = 1;
    for (int x = 0; x < l; x++){
        if (binerKebalikSem[x] == '1'){
            hasilPangkat *= nPangkatDuaPangkat[x];
        }
    }

    cout << hasilPangkat;
}