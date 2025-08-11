#include <bits/stdc++.h>
using namespace std;

int fpb(int a, int b){
    int a1 = max(a, b), b1 = min(a, b);
    if (b1 == 0){
        return a1;
    }else{
        return fpb(a1 % b1, b1);
    }
}

int main(){
    int a, b;
    cin >> a >> b;
    int c = fpb(a, b);
    cout << c;
}