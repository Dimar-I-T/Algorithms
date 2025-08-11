#include <bits/stdc++.h>
using namespace std;

int memo[1000][1000] = {0};

int kombinasi(int n, int r){
    if (memo[n][r] == 0){
        if (n == r || r == 0){
            memo[n][r] = 1;
        }else{
            memo[n][r] = kombinasi(n - 1, r) + kombinasi(n - 1, r - 1);
        }
    }

    return memo[n][r];
}

int main(){
    // input: n, r
    // output: nCr
    int n, r;
    cin >> n >> r;
    cout << kombinasi(n, r);
}