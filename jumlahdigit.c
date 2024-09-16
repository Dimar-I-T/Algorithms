#include <stdio.h>
#include <string.h>

int Logaritma10(int n){
    if (n == 0){
        return 0;
    }else{
        return 1 + Logaritma10(n / 10);
    }
}

// Dimar's Algorithm
int main(){
    int a, b, n, k, jumlah = 0;
    int *pA = &a, *pB = &b;
    scanf("%d", &n);
    k = Logaritma10(n);
    int pangkat[k + 1];
    pangkat[0] = 1;
    for (int x = 1; x <= k; x++){
        pangkat[x] = pangkat[x - 1] * 10;
    }

    for (int x = k; x >= 1; x--){
        *pA = n % pangkat[x];
        *pB = n % pangkat[x - 1];
        jumlah += (a - b)/pangkat[x - 1];
    }

    printf("%d", jumlah);
}