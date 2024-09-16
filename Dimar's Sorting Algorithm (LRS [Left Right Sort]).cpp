#include<bits/stdc++.h>
// Dimar's Code
using namespace std;

vector<int> LRS(vector<int> A){
    bool kika = 1, kaki = 1;
    int n = A.size();
    int minn = A[0], maks = A[0];
    for (int x = 1; x < n; x++){
        if (A[x - 1] > A[x]){
            kika = 0;
        }else{
            kaki = 0;
        }

        minn = min(minn, A[x]);
        maks = max(maks, A[x]);
    }

    if (kika == 1){
        return A;
    }else if (kaki == 1){
        int lRev = 0, rRev = n - 1;
        while (lRev < rRev){
            int temp = A[lRev];
            A[lRev] = A[rRev];
            A[rRev] = temp;
            lRev++;
            rRev--;
        }

        return A;
    }else{
        vector<int> lV = {minn}, rV = {maks};
        for (int x = 0; x < n; x++){
            if (A[x] == minn || A[x] == maks){
                continue;
            }

            if (abs(A[x] - minn) <= abs(A[x] - maks)){
                lV.push_back(A[x]);
            }else{
                rV.push_back(A[x]);
            }
        }

        vector<int> l = LRS(lV), r = LRS(rV);
        for (int x = 0; x < r.size(); x++){
            l.push_back(r[x]);
        }

        return l;
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for (int x = 0; x < n; x++){
        cin >> A[x];
    }

    vector<int> SortA = LRS(A);
    for (int x = 0; x < n; x++){
        cout << SortA[x] << " ";
    }
}
