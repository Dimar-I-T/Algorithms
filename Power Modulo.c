#include <stdio.h>

int main(){
    // input: a, b, m
    // output: a ^ b mod m
    unsigned long long a, b, m, c = 1;
    scanf("%lld", &a); scanf("%lld", &b); scanf("%lld", &m);
    unsigned long long d = a;
    for (unsigned long long x = b; x >= 1; x /= 2){
        if (x % 2 == 1){
            c *= d;
            c %= m;
        }

        d *= d % m;
    }

    printf("%lld", c % m);
}