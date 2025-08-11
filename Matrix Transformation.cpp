#include <bits/stdc++.h>
using namespace std;

void rotasi90(int **p, int m){
    int baru[m][m];
    int k = 0;
    for (int x = 0; x < m; x++){
        for (int y = m - 1; y >= 0; y--){
            baru[x][k] = p[y][x];
            k++;
        }

        k = 0;
    }

    for (int x = 0; x < m; x++){
        for (int y = 0; y < m; y++){
            p[x][y] = baru[x][y];
        }
    }
}

void rotasi180(int **p, int m){
    rotasi90(p, m);
    rotasi90(p, m);
}

void rotasi270(int **p, int m){
    rotasi180(p, m);
    rotasi90(p, m);
}

void refleksi(int **p, int m, int ver){
    int i = 0, j = 0, batasKanan = m, batasBawah = m;
    int **A1 = (int **)calloc(101, sizeof(int*));
    for (int x = 0; x < m; x++){
        A1[x] = (int *)calloc(101, sizeof(int));
    }
    
    for (int x = 0; x < m; x++){
        if (p[x][m - 1] == 0 && p[x][0] == 0){
            continue;
        }

        for (int y = 0; y < m; y++){
            if (p[x][y] == 0){
                continue;
            }

            A1[i][j] = p[x][y];
            j++;
        }

        j = 0;
        i++;
    }

    if (A1[0][m - 1] == 0){
        for (int x = 0; x < m - 1; x++){
            if (A1[0][x + 1] == 0){
                batasKanan = x + 1;
                break;
            }
        }
    }

    if (A1[m - 1][0] == 0){
        for (int x = 0; x < m - 1; x++){
            if (A1[x + 1][0] == 0){
                batasBawah = x + 1;
                break;
            }
        }
    }

    if (ver == 1){
        for (int x = 0; x < m; x++){
            if (A1[x][0] == 0){
                break;
            }
    
            for (int y = 0; y < batasKanan/2; y++){
                int temp = A1[x][y];
                A1[x][y] = A1[x][batasKanan - y - 1];
                A1[x][batasKanan - y - 1] = temp;
            }
        }
    }else{
        for (int x = 0; x < batasBawah/2; x++){
            for (int y = 0; y < m; y++){
                int temp = A1[x][y];
                A1[x][y] = A1[batasBawah - x - 1][y];
                A1[batasBawah - x - 1][y] = temp;
            }
        }
    }

    for (int x = 0; x < m; x++){
        for (int y = 0; y < m; y++){
            p[x][y] = 0;
            p[x][y] = A1[x][y];
        }
    }

    free(A1);
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    int maks = max(n, m);
    int **A = (int**)calloc(101, sizeof(int));
    for (int x = 0; x < maks; x++){
        A[x] = (int *)calloc(101, sizeof(int));
        if (x >= n){
            continue;
        }

        for (int y = 0; y < m; y++){
            cin >> A[x][y];
        }
    }
    
    for (int x = 0; x < k; x++){
        string inp;
        cin >> inp;
        if (inp == "90"){
            rotasi90(A, maks);
        }else if (inp == "180"){
            rotasi180(A, maks);
        }else if (inp == "270"){
            rotasi270(A, maks);
        }else if (inp == "|"){
            refleksi(A, maks, 1);
        }else if (inp == "_"){
            refleksi(A, maks, 0);
        }
    }

    for (int x = 0; x < maks; x++){
        for (int y = 0; y < maks; y++){
            if (A[x][y] == 0){
                continue;
            }

            cout << A[x][y] << " ";
        }

        cout << "\n";
    }

    free(A);
}
