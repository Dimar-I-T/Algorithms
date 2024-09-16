                    
                    
                    #include <stdio.h>
                    #include <string.h>

                    int main(){
                        long long n, p; // cari n pangkat p
                        scanf("%lld", &n); scanf("%lld", &p);
                        char binerKebalik[64] = "";
                        int k = p, panjangBiner = 0;
                        while (k > 0){
                            char tambahanC[2];
                            sprintf(tambahanC, "%d", k % 2);
                            strcat(binerKebalik, tambahanC);
                            k /= 2;
                        }

                        // Dimar's binary exponentiation algorithm
                        while (binerKebalik[panjangBiner] == '1' ||
                            binerKebalik[panjangBiner] == '0'){
                            panjangBiner++;
                        }

                        long long nPDuaPangkat[panjangBiner];
                        nPDuaPangkat[0] = n;
                        for (int x = 1; x < panjangBiner; x++){
                            nPDuaPangkat[x] = nPDuaPangkat[x - 1]*
                                              nPDuaPangkat[x - 1];
                        }

                        long long hasilPangkat = 1;
                        for (int x = 0; x < panjangBiner; x++){
                            if (binerKebalik[x] == '1'){
                                hasilPangkat *= nPDuaPangkat[x];
                            }
                        }

                        printf("%lld", hasilPangkat);
                    }


                    