#include <bits/stdc++.h>
using namespace std;

const int MAXSIZE = 2 * 1e5;
vector<int> segTree(4 * MAXSIZE);
vector<int> A(MAXSIZE);
int n;
int sz;

void build(int l, int r, int i, int h) {
    // kalau di ujung
    if (l == r) {
        segTree[i] = A[(i + 1) % sz];
        return;
    }

    int m = (l + r) / 2;
    int kiri = 2 * i + 1;
    int kanan = 2 * i + 2;
    build(l, m, kiri, h + 1);
    build(m + 1, r, kanan, h + 1);
    if ((h + n) % 2 == 0) {
        segTree[i] = segTree[kiri] ^ segTree[kanan];
    } else {
        segTree[i] = segTree[kiri] | segTree[kanan];
    }
}

void update(int l, int r, int i, int p, int b, int h) {
    if (l == r && l == p) {
        segTree[i] = b;
        return;
    }

    int m = (l + r) / 2;
    int kiri = 2 * i + 1;
    int kanan = 2 * i + 2;
    if (p <= m) {
        // ke kiri
        update(l, m, kiri, p, b, h + 1);
    } else {
        update(m + 1, r, kanan, p, b, h + 1);
    }

    if ((h + n) % 2 == 0) {
        segTree[i] = segTree[kiri] ^ segTree[kanan];
    } else {
        segTree[i] = segTree[kiri] | segTree[kanan];
    }
}

int main() {
    int m;
    cin >> n >> m;
    sz = (1 << n);
    for (int x = 0; x < sz; x++) {
        cin >> A[x];
    }

    build(0, sz - 1, 0, 0);
    while (m--) {
        int p, b;
        cin >> p >> b;
        update(0, sz - 1, 0, p - 1, b, 0);
        cout << segTree[0] << "\n";
    }
}