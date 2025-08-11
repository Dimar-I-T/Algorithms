#include <bits/stdc++.h>
using namespace std;
void runtuh(char **p, int n, int m, int k);
void cariPenuh(char **p, int n, int m);

void runtuh(char **p, int n, int m, int k){
    int b[m];
    for (int kolom = 0; kolom < m; kolom++){
        for (int baris = k; baris < n; baris++){
            if (p[baris][kolom] == '1' || p[baris][kolom] == '2'){
                b[kolom] = baris;
                break;
            }
        }
    }
    
    for (int kolom = 0; kolom < m; kolom++){
        int ba = b[kolom] - 1;
        for (int baris = b[kolom] - 1; baris >= 0; baris--){
            if (p[baris][kolom] == '1'){
                p[baris][kolom] = '0';
                p[ba][kolom] = '1';
                ba--;
            }
        }
    }
    
    cariPenuh(p, n, m);
}

void cariPenuh(char **p, int n, int m){
    int ada = 0, k = 0;
    for (int x = 0; x < n; x++){
        int banyakSatu = 0;
        for (int y = 0; y < m; y++){
            if (p[x][y] == '1'){
                banyakSatu++;
            }
        }
        
        if (banyakSatu == m){
            ada = 1;
            k = x;
            for (int y = 0; y < m; y++){
                p[x][y] = '0';
            }
        }
    }
    
    if (ada == 1){
        runtuh(p, n, m, k);
    }
}

int main(){
    int r, c;
    cin >> r >> c;
    getchar();
    char **A = new char*[r + 1];
    for (int x = 0; x < r; x++){
        A[x] = new char[c + 1];
        cin.getline(A[x], c + 1); 
    }
    
    A[r] = (char *)calloc(c, sizeof(char));
    for (int x = 0; x < c; x++){
        A[r][x] = '2';
    }
    
    cariPenuh(A, r + 1, c);
    for (int x = 0; x < r; x++){
        cout << A[x] << "\n";
    }
}