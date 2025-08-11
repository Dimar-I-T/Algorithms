#include <stdio.h>
#include <math.h>

// fpb(a, b) = fpb(a mod b, b)
int max(int a, int b){
    return (a > b) ? a : b;
}

int min(int a, int b){
    return (a > b) ? b : a;
}

int fpb(int a, int b){
    if (a == 0){
        return b;
    }else{
        int a1 = max(a, b), b1 = min(a, b);
        return fpb(a1 % b1, b1);
    }
}

int main(){
    // input: a, b
    // output: fpb(a, b);
    int a, b;
    scanf("%d", &a); scanf("%d", &b);
    int c = fpb(a, b);
    printf("%d", c);
}