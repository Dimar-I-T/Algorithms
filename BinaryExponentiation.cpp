#include <bits/stdc++.h>
using namespace std;
// Dimar's Code for finding a to the power of b using binary exponentiation

int main(){
    unsigned long long a, b;
    cin >> a >> b;
    string reversedBinary = "";
    while (b > 0){
        reversedBinary += to_string(b % 2);
        b /= 2;
    }

    int lBinary = reversedBinary.length();
    unsigned long long multiplier = a, res = 1;
    for (int x = 0; x < lBinary; x++){
        if (reversedBinary[x] == '1'){
            res *= multiplier;
        }   

        multiplier *= multiplier;
    }

    cout << res;
}