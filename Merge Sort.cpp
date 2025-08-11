#include <bits/stdc++.h>
using namespace std;

vector<int> A(100);
// l1 -> r1 (kiri)
// l2 -> r2 (kanan)
// semua l1 -> r2
void merge(int l11, int r11, int l22, int r22){
    int l1 = l11, l2 = l22, r1 = r11, r2 = r22;
    vector<int> T(r2 - l1 + 1);
    int k = 0;
    while (l1 <= r1 && l2 <= r2){
        if (A[l1] < A[l2]){
            T[k] = A[l1];
            l1++;
        }else{
            T[k] = A[l2];
            l2++;
        }

        k++;
    }

    while (l1 <= r1){
        T[k] = A[l1];
        l1++;
        k++;
    }

    while (l2 <= r2){
        T[k] = A[l2];
        l2++;
        k++;
    }

    int i = 0;
    for (int x = l11; x <= r22; x++){
        A[x] = T[i];
        i++;
    }
}

void mergeSort(int l, int r){
    if (l == r){
        return;
    }else{
        int m = (l + r) / 2;
        mergeSort(l, m);
        mergeSort(m + 1, r);
        merge(l, m, m + 1, r);
    }
}

int main(){
    int n;
    cin >> n;
    for (int x = 0; x < n; x++){
        cin >> A[x];
    }

    mergeSort(0, n - 1);
    for (int x = 0; x < n; x++){
        cout << A[x] << " ";
    }
}