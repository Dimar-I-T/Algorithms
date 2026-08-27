#include <bits/stdc++.h>
using namespace std;

vector<int> A;
int n;
vector<int> segTree(10000);

void build(int l, int r, int i) {
    if (l > r) {
        return;
    }

    if (l == r) {
        segTree[i] = A[l];
        return;
    }

    int m = (l + r) / 2;
    // ke kiri bawah
    build(l, m, 2*i + 1);
    // ke kanan bawah
    build(m + 1, r, 2*i + 2);

    // setelah selesai build
    // lakukan operasi dari bawah kiri dan bawah kanan
    segTree[i] = segTree[2*i + 1] + segTree[2*i + 2];
}

int query(int l, int r, int lq, int rq, int i) {
    if (l == lq && r == rq) {
        return segTree[i];
    } 
    
    int m = (l + r) / 2;
    // harus kebagi dua
    if (lq <= m && rq > m) {
        return query(l, m, lq, m, 2*i + 1) + query(m + 1, r, m + 1, rq, 2*i + 2);
    } else {
        if (lq > m) {
            // di kanan
            return query(m + 1, r, lq, rq, 2*i + 2);
        } else {
            // di kiri
            return query(l, m, lq, rq, 2*i + 1);
        }
    }
}

int main() {
    cin >> n;
    A.clear(); A.resize(n);
    for (int x = 0; x < n; x++) {
        cin >> A[x];
    }

    build(0, n - 1, 0);

    cout << "A:\n";
    for (int x = 0; x < n; x++) {
        cout << A[x] << " ";
    }

    cout << "\nhasil seg tree:\n";
    for (int x = 0; x <= 2*n + 1; x++) {
        cout << segTree[x] << " ";
    }

    int lq = 0;
    int rq = 2;
    cout << "hasil query: " << query(0, n - 1, lq, rq, 0);
}