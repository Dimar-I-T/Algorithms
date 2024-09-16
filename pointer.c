#include <stdio.h>
#include <math.h>
#define maks 100000

void Tambah(int* a, int penambah){
    *a = *a + penambah;
}

int main(){
    printf("Masukan Nilai Mu: ");
    int nilai, penambah;
    scanf("%d", &nilai);
    printf("Masukan Angka Penambah: ");
    scanf("%d", &penambah);
    int* p = NULL;
    p = &nilai;
    Tambah(p, penambah);

    printf("Hasil penambahan: %d", nilai);
}