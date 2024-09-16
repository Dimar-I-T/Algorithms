#include <bits/stdc++.h>
using namespace std;
// Dimar's Code for finding GCD of Multiple Numbers

long GCD(vector<long> A){
    if (A.size() == 1){
        return A[0];
    }

    bool oneDetected = 0;
    long minn = LONG_MAX, idxMinn;
    for (int x = 0; x < A.size(); x++){
        if (A[x] != 0){
            if (A[x] < minn){
                minn = A[x];
                idxMinn = x;
            }
        }
    }

    vector<long> A1;
    A1.push_back(minn);
    for (int x = 0; x < A.size(); x++){
        if (A[x] == 1){
            oneDetected = 1;
            break;
        }

        if (A[x] != 0 && x != idxMinn){
            A1.push_back(A[x] % minn);
        }
    }

    if (oneDetected){
        return 1;
    }else{
        return GCD(A1);
    }
}

int main(){
    int nElements;
    cin >> nElements;
    vector<long> A(nElements);
    for (int x = 0; x < nElements; x++){
        cin >> A[x];
    }

    cout << GCD(A);
}