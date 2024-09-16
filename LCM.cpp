#include <bits/stdc++.h>
using namespace std;
// Dimar's Code for finding LCM of multiple numbers

long LCM(vector<long> A){
    long divisor = LONG_MAX;
    for (int x = 0; x < A.size(); x++){
        
        if (A[x] == 1){
            continue;
        }

        divisor = min(divisor, A[x]);
    }

    if (divisor == LONG_MAX){
        return 1;
    }

    for (int x = 2; x <= sqrt(divisor); x++){
        if (divisor % x == 0){
            divisor = x;
            break;
        }
    }

    for (int x = 0; x < A.size(); x++){
        if (A[x] % divisor == 0){
            A[x] /= divisor;
        }
    }

    return divisor * LCM(A);
}

int main(){
    int nElements;
    cin >> nElements;
    vector<long> A(nElements);
    for (int x = 0; x < nElements; x++){
        cin >> A[x];
    }

    cout << LCM(A);
}