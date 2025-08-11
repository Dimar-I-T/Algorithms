#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b, c = 1;
    scanf("%d", &a); scanf("%d", &b);
    int d = a;
    for (int x = b; x >= 1; x /= 2){
        if (x % 2 == 1){
            c *= d;
        }

        d *= d;
    }

    printf("%d", c);
}