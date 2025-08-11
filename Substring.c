#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// pakai variabel ini sesudah memanggil substr untuk hasil substringnya
char sub[1000];

void substr(char str[100], int indexAwal, int panjang){
    int k = 0;
    char hasil[1000] = "";
    for (int x = indexAwal; x < panjang + indexAwal; x++){
        hasil[k] = str[x];
        k++;
    }

    strcpy(sub, hasil);
}

int main(){
    char str[] = "Hello World!";
    
    substr(str, 6, 5);
    printf("%s \n", sub);

    substr(str, 6, 4);
    printf("%s", sub);
    
    substr(str, 0, 3);
    printf("%s", sub);
}