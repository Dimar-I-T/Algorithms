#include <bits/stdc++.h>
using namespace std;
// Dimar's Code for sorting numbers

int main(){
    int nElements; 
    cin >> nElements;
    vector<int> A(nElements), isMinIdx(nElements);
    for (int x = 0; x < nElements; x++){
        cin >> A[x];
    }

    vector<int> res;
    for (int x = 0; x < nElements; x++){
        int minn = INT_MAX, minIdx = 0;
        for (int y = 0; y < nElements; y++){
            if (isMinIdx[y] == 1){
                continue;
            }

            if (minn > A[y]){
                minn = A[y];
                minIdx = y;
            }
        }

        isMinIdx[minIdx] = 1;
        res.push_back(minn);
    }

    for (int x = 0; x < nElements; x++){
        cout << res[x] << " ";
    }
}