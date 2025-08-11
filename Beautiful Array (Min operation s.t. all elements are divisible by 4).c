#include <stdio.h>

int main(){
    int t;
    scanf("%d", &t);
    while (t > 0){
        int n, x = 0, s = 0, b1 = 0, b2 = 0, b3 = 0, hasil = 0;
        int C[100000] = {0};
        scanf("%d", &n);
        for (x = 0; x < n; x++){
            int inp;
            scanf("%d", &inp);
            C[x] = inp % 4;
            s += C[x];
        }
        
        if (s % 4 != 0){
            printf("-1\n");
            t--;
            continue;
        }
        
        for (x = 0; x < n; x++){
            switch(C[x]){
                case 1:
                    b1++;
                    break;
                case 2:
                    b2++;
                    break;
                case 3:
                    b3++;
                    break;
            }
        }
        
        int cs = 0;
        hasil += b2 / 2;
        if (b1 < b3){
            hasil += b1;
            cs = b3 - b1;
        }else{
            hasil += b3;
            cs = b1 - b3;
        }
        
        hasil += 3*(cs/4);
        
        if (b2 % 2 == 1){
            hasil += 2;
        }
        
        printf("%d\n", hasil);
        t--;
    }
}