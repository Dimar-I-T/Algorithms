#include <stdio.h>

void t(int **p){
    p[0][0] = 1;
}

int main(){
    int A[2][2];
    t(A);
}