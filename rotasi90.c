#include <stdio.h>
#include <stdlib.h>

int main(){
    // Dimar's Algorithm of rotating 2d array
    int n, m;
    scanf ("%d", &n); scanf ("%d", &m);
    int mat[n][m], inp;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            scanf ("%d", &inp);
            mat[x][y] = inp;
        }
    }

    int hasil[m][n];
    for (int x = 0; x < m; x++){
        for (int y = 0; y < n; y++){
            hasil[x][y] = mat[n - 1 - y][x];
            printf ("%d ", hasil[x][y]);
        }

        printf ("\n");
    }
}