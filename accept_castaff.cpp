#include <bits/stdc++.h>
using namespace std;

void trim(string& s) {
    int n = s.length();
    int l = 0;
    bool harusDitrim = 0;
    while (l < n - 1) {
        //cout << "s[l] = " << (int) s[l] << " dan s[l + 1] = " << (int) s[l + 1] << "\n";
        if ((s[l] == 9 || s[l] == 32) && (s[l + 1] == 9 || s[l + 1] == 32)) {
            harusDitrim = 1;
            break;
        }
        
        l++;
    }
    
    if (harusDitrim) {
        s = s.substr(0, l);
    }
    //cout << "\n";
}

int main() {
    int n;
    cin >> n;
    string divisi;
    cin >> divisi;
    getchar();
    for (int x = 0; x < n; x++) {
        string nama;
        getline(cin, nama);
        trim(nama);
        cout << "select * from accept(\'" << nama << "\', \'" << divisi << "\');\n";
    }
}
