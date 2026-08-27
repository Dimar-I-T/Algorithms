#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* sel = NULL;
};

void isiDQ(Node* sek, deque<int>& dq) {
    if (sek->sel != NULL) {
        isiDQ(sek->sel, dq);    
    }
    
    dq.push_back(sek->val);
}

void ubah(int x, deque<int>& dq) {
    while (dq.front() != x) {
        int bel = dq.back();
        dq.push_front(bel);
        dq.pop_back();
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    deque<int> dq;
    vector<int> A(n);
    for (int x = 0; x < n; x++) {
        int a;
        cin >> a;
        dq.push_back(a);
        A[x] = a;
    }
    
    pair<char, int> gTerakhir = {'G', '-'};
    vector<pair<char, int>> op(k);
    int indexGTerakhir = 0;
    for (int x = 0; x < k; x++) {
        char c;
        int xy;
        cin >> c >> xy;
        pair<char, int> p = {c, xy};
        op[x] = p;
        if (c == 'G') {
            indexGTerakhir = x;
        }
    }
    
    unordered_map<int, Node*> nodes;
    for (int x : A) {
        nodes[x] = new Node(x);
    }
    
    // kasus index pertama
    if (op[0].first == 'A') {
        int baru = op[0].second;
        nodes[baru] = new Node(baru);
        nodes[dq.front()]->sel = nodes[baru];
    } 
    
    for (int x = 1; x <= indexGTerakhir; x++) {
        pair<char, int> pSek = op[x];
        pair<char, int> pSeb = op[x - 1];
        if (pSek.first == 'A') {
            int baru = pSek.second;
            nodes[baru] = new Node(baru);
            if (nodes[pSeb.second]-> sel == NULL) {
                nodes[pSeb.second]->sel = nodes[baru];
            } else {
                Node* seb = nodes[pSeb.second]->sel;
                nodes[pSeb.second]->sel = nodes[baru];
                nodes[baru]->sel = seb;
            }
        } else {
            gTerakhir = pSek;
        }
    }
    
    deque<int> akhir;
    for (int x : A) {
        isiDQ(nodes[x], akhir);
    }
    
    if (gTerakhir.second != '-') {
        ubah(gTerakhir.second, akhir);
    }
    
    for (int x = indexGTerakhir + 1; x < k; x++) {
        akhir.push_front(op[x].second);
    }
    
    cout << akhir.size() << "\n";
    while (!akhir.empty()) {
        cout << akhir.front() << " ";
        akhir.pop_front();
    }
}