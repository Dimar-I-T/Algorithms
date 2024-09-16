#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
// Dimar's Code for printing prime numbers from 1 - 1000000

int main(){
    int n;
    cin >> n;
    vector<ull> limit10(10);
    limit10[0] = 1;
    for (int x = 1; x < 10; x++){
        limit10[x] = limit10[x - 1] * 10;
    }

    vector<ull> primeNums;
    ull k = 1, nP = 2, nP2 = 2;
    primeNums.push_back(2); primeNums.push_back(3);
    for (int x = 4; x < 1000000; x++){
        if (x > limit10[k]){
            nP2 = nP;
            k++;
        }

        bool prime = 1;
        for (int y = 0; y < nP2; y++){
            if (x % primeNums[y] == 0){
                prime = 0;
                break;
            }
        }

        if (prime){
            primeNums.push_back(x);
            nP++;
        }
    }

    for (int x = 0; x < primeNums.size(); x++){
        cout << primeNums[x] << " ";
    }
}