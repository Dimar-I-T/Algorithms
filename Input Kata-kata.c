#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Balik(char pengirim[], char **kata, int k){
    for (int x = 0; x < k; x++){
        if (strcmp(pengirim, kata[x]) == 0){
            continue;
        }

        int n = strlen(kata[x]);
        for (int y = 0; y < n / 2; y++){
            int a = kata[x][y], b = kata[x][n - y - 1];
            int A = (a >= 97 && a <= 122), B = (b >= 97 && b <= 122);
            if (A ^ B){
                if (A == 1){
                    kata[x][y] = a - 32;
                    kata[x][n - y - 1] = b + 32;
                }else{
                    kata[x][n - y - 1] = b - 32;
                    kata[x][y] = a + 32;
                }
            }   

            char temp = kata[x][y];
            kata[x][y] = kata[x][n - y - 1];
            kata[x][n - y - 1] = temp;
        }
    }
}

int main(){
    printf("Masukkan nama pengirim: ");
    char pengirim[6969], kalimat[6969];
    gets(pengirim);
    printf("Masukkan kalimat: ");
    gets(kalimat);
    int n = strlen(kalimat);
    printf("n = %d\n", n);
    char **kata = (char **)calloc(1, sizeof(char *));
    int k = 0, panjangKata = 0;
    kata[0] = (char *)calloc(1, sizeof(char));
    for (int x = 0; x < n; x++){
        if (kalimat[x] == ' '){
            kata[k][panjangKata] = '\0';
            panjangKata = 0;
            k++;
            kata = (char **)realloc(kata, (k + 1) * sizeof(char *));
            kata[k] = (char *)calloc(1, sizeof(char));
            continue;
        }

        kata[k] = (char *)realloc(kata[k], (panjangKata + 2) * sizeof(char));
        kata[k][panjangKata] = kalimat[x];
        panjangKata++;
        kata[k][panjangKata] = '\0';
    }

    Balik(pengirim, kata, k + 1);
    for (int x = 0; x < k + 1; x++){
        printf("%s ", kata[x]);
    }
}