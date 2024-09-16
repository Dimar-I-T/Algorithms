#include <stdio.h>
#include <stdlib.h>
// Dimar's Algorithm

void EditTangga (char* t[1000][1000], char input, int banyak){
    int sizeT = 0;
    for (int x = 0; x < 1000; x++){
        if ((*t)[x][0] != '*'){
            break;
        }

        sizeT++;
    }

    // tambah
    if (input == '+'){
        for (int x = sizeT; x < banyak + sizeT; x++){
            strcpy((*t)[x], (*t)[x - 1]);
            strcat((*t)[x], "*");
        }
    }

    // kurang
    if (input == '-'){
        for (int x = sizeT - 1; x >= sizeT - banyak; x--){
            strcpy((*t)[x], "0");
        }
    }

    for (int x = 0; x < sizeT + banyak; x++){
        if ((*t)[x][0] != '*' || (*t)[x][0] == "0"){
            break;
        }

        printf("%s\n", (*t)[x]);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    getchar();
    char tangga[1000][1000];
    strcpy(tangga[0], "*");
    printf("%s\n", tangga[0]);
    for (int x = 1; x < n; x++){
        strcpy(tangga[x], tangga[x - 1]);
        strcat(tangga[x], "*");
        printf("%s\n", tangga[x]);
    }

    tanya:
    printf("Input 1 untuk mengedit tangga atau 0 untuk keluar dari program: ");
    int inp;
    scanf("%d", &inp);
    getchar();
    if (inp == 1){
        goto edit;
    }else{
        goto akhir;
    }

    edit:
    printf("Input berapa banyak tangga yang ingin ditambah(tambah + di depan angka)/dikurang(tambah - di depan angka): ");
    char inpStr[1000], angkaS[1000];
    gets(inpStr);
    for (int x = 1; x < strlen(inpStr); x++){
        angkaS[x - 1] = inpStr[x];
    }

    char* ptrT = &tangga;
    int angka = atoi(angkaS);
    EditTangga(ptrT, inpStr[0], angka);
    goto tanya;

    akhir:;
    return 0;
}