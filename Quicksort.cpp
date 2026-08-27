#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &A, int l, int r) {
    int l1 = l, l2 = l;
    int terakhir = A[r];
    while (l2 < r) {
        if (A[l2] < terakhir) {
            int temp = A[l1];
            A[l1] = A[l2];
            A[l2] = temp;
            l1++;
        }
        
        l2++;
    }
    
    if (A[l1] > terakhir) {
        int temp = A[l1];
        A[l1] = terakhir;
        A[r] = temp;
    }
    
    return l1;
}

void quickSort(vector<int> &A, int l, int r) {
    if (l >= r) {
        return;
    }
    
    int pivot = partition(A, l, r);
    quickSort(A, l, pivot - 1);
    quickSort(A, pivot + 1, r);
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int x = 0; x < n; x++){
        cin >> A[x];
    }
    
    quickSort(A, 0, n - 1);
    for (int a : A) {
        cout << a << " ";
    }
}