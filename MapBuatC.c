#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct KeyValue{
    char key[100];
    int value;
};

int banyakKey = 0;
char keys[100][100];
struct KeyValue map[100];

void SetValue(char key[100], int value){
    int ada = 0, b = 0;
    for (int x = 0; x < banyakKey; x++){
        if (strcmp(keys[x], key) == 0){
            ada = 1;
            b = x;
            break;
        }
    }

    if (ada == 1){
        map[b].value = value;
    }else{
        struct KeyValue kv;
        strcpy(kv.key, key);
        kv.value = value;
        map[banyakKey] = kv;
        strcpy(keys[banyakKey], key);
        banyakKey++;
    }
}

int GetValue(char key[100]){
    int hasil = 0;
    for (int x = 0; x < banyakKey; x++){
        if (strcmp(keys[x], key) == 0){
            hasil = map[x].value;
        }
    }

    return hasil;
}

int main(){
    SetValue("a", 2);
    SetValue("badak", 4);
    printf("%d", GetValue("a"));
}