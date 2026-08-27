#include <bits/stdc++.h>
using namespace std;

typedef struct node {
    int data;
    node* left;
    node* right;
} Node;

void preorder(Node* s) {
    cout << s->data << " ";
    if (s->left != NULL) {
        preorder(s->left);
    }
    
    if (s->right != NULL) {
        preorder(s->right);
    }
}

void inorder(Node* s) {
    if (s->left != NULL) {
        inorder(s->left);
    }
    
    cout << s->data << " ";
    
    if (s->right != NULL) {
        inorder(s->right);
    }
}

void postorder(Node* s) {
    if (s->left != NULL) {
        postorder(s->left);
    }
    
    if (s->right != NULL) {
        postorder(s->right);
    }
    
    cout << s->data << " ";
}


void bfs(Node* s) {
    queue<Node*> q;
    q.push(s);
    
    while (!q.empty()) {
        Node* sel = q.front();
        cout << sel->data << " ";
        if (sel->left != NULL) {
            q.push(sel->left);
        }
        
        if (sel->right != NULL) {
            q.push(sel->right);
        }
        
        q.pop();
    }
}

int main() {
    Node* satu = new Node();
    Node* dua = new Node();
    Node* tiga = new Node();
    Node* empat = new Node();
    Node* lima = new Node();
    Node* enam = new Node();
    Node* tujuh = new Node();
    satu->data = 1;
    satu->left = dua;
    satu->right = tiga;
    dua->data = 2;
    dua->left = empat;
    dua->right = lima;
    tiga->data = 3;
    empat->data = 4;
    empat->left = NULL;
    empat->right = NULL;
    lima->data = 5;
    lima->left = NULL;
    lima->right = NULL;
    tiga->left = enam;
    tiga->right = tujuh;
    enam->data = 6;
    enam->left = NULL;
    enam->right = NULL;
    tujuh->data = 7;
    tujuh->left = NULL;
    tujuh->right = NULL;
    
    bfs(satu);
}
