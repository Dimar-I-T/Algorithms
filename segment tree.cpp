#include <bits/stdc++.h>

using namespace std;

int ST[1000] = {0};

int constructST(int si, vector<int> arr, int l, int r){
    if (l == r){
        ST[si] = arr[l];
        return arr[l];
    }
    
    int mid = (l + r) / 2;
    ST[si] = constructST((2*si + 1), arr, l, mid) + constructST((2*si + 2), arr, mid + 1, r);
    return ST[si];
}

int getSum(int si, int sl, int sr, int l, int r){
    if (l <= sl && r >= sr){
        return ST[si];
    }
    
    if (sr < l || sl > r){
        return 0;
    }
    
    int mid = (sl + sr) / 2;
    return getSum(2*si + 1, sl, mid, l, r) + getSum(2*si + 2, mid + 1, sr, l, r);
}

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for (int x = 0; x < n; x++){
        cin >> A[x];   
    }
    
    constructST(0, A, 0, n - 1);
    
    for (int x = 0; x < 2* (n + 1); x++){
        cout << ST[x] << " ";
    }
    
    cout << "\n";
    cout << getSum(0, 0, n - 1, 1, 3);
}