#include <stdio.h>
#include <stdlib.h>

void isiPrima(int *p, int n){
    int *eliminated = (int *)calloc(n + 1, sizeof(int));
    int k = 0;
    for (int x = 2; x <= n; x++){
        int j = x * x;
        if (eliminated[x] == 0){
            p[k] = x;
            k++;
            for (int y = j; y <= n; y += x){
                eliminated[y] = 1;
            }
        }
    }

    p[k] = -1;
}

int main(){
    int n;
    int *prima = (int *)calloc(n + 1, sizeof(int));
    scanf("%d", &n);
    int k = 0;
    isiPrima(prima, n);
    while (prima[k] != -1){
        printf("%d ", prima[k]);
        k++;
    }
}