#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &A, int l, int m, int r) {
    int l1 = l, m1 = m, k = 0;
    vector<int> tempV(r - l + 1);
    m++;
    while (l <= m1 && m <= r) {
        if (A[l] > A[m]) {
            tempV[k] = A[m];
            m++;
        }else{
            tempV[k] = A[l];
            l++;
        }
        
        k++;
    }
    
    while (l <= m1) {
        tempV[k] = A[l];
        l++;
        k++;
    }
    
    while (m <= r) {
        tempV[k] = A[m];
        m++;
        k++;
    }
    
    for (int x = 0; x < tempV.size(); x++) {
        A[l1 + x] = tempV[x];
    }
}

void mergeSort(vector<int> &A, int l, int r){
    if (l == r) {
        return;
    }
    
    int m = (l + r) / 2;
    mergeSort(A, l, m);
    mergeSort(A, m + 1, r);
    merge(A, l, m, r);
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int x = 0; x < n; x++){
        cin >> A[x];
    }
    
    mergeSort(A, 0, n - 1);
    for (auto x : A) {
        cout << x << " ";
    }
}
