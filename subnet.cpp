#include <bits/stdc++.h>
using namespace std;

int biner(string s) {
    return stoi(s, nullptr, 2);
}

string subnetS(int n) {
    string awal = "11111111000000000000000000000000";
    string hasil = "";
    int batas = n - 8;
    for (int x = 0; x < batas; x++) {
        awal[8 + x] = '1';
    }

    //cout << awal << "\n";
    for (int x = 0; x < awal.length(); x += 8) {
        string sek = awal.substr(x, 8);
        int bin = biner(sek);
        hasil += to_string(bin) + ".";
    }

    return hasil.substr(0, hasil.length() - 1);
}

int main() {
    int n = 3;
    char X = '9';
    char Y = '4';
    string subnetE = subnetS(24);
    cout << subnetE;
}
