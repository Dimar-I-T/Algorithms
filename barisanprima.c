#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    // Dimar's Prime Generator Algorithm
    long long batas;
    scanf ("%lli", &batas);
    long long barisanPrima[1000000], pangkat[1000000], k = 0, idxPangkat = 1, idxPrima = 2, tambah = 0;
    barisanPrima[0] = 2; barisanPrima[1] = 3;
    pangkat[0] = 1;
    while (pangkat[k] < batas){
        pangkat[k + 1] = pangkat[k]*10;
        k++;
    }

    for (long long x = 4; x <= batas; x++){
        if (x == pangkat[idxPangkat]){
            idxPangkat++;
            idxPrima += tambah;
            tambah = 0;
        }

        int primaBukan = 1;
        for (int y = 0; y < idxPrima; y++){
            if (x % barisanPrima[y] == 0){
                primaBukan = 0;
                break;
            }
        }

        if (primaBukan == 1){
            tambah++;
            barisanPrima[idxPrima - 1 + tambah] = x;
        }
    }

    int banyak = 0;
    for (int x = 0; x < 100000; x++){
        if (barisanPrima[x] == 0){
            break;
        }

        printf ("%d ", barisanPrima[x]);
        banyak++;
    }

    printf("\n%d", banyak);
}
