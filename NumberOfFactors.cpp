#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long 
// Dimar's Code for finding number of factors of a natural number

int main(){
    ull n;
    cin >> n;

    if (n == 1){
        cout << 1;
    }else{
        set<ull> F;
        for (ull x = 1; x <= sqrt(n); x++){
            if (n % x == 0){
                F.insert(x); F.insert(n / x);
            }
        }

        cout << F.size();
    }
}