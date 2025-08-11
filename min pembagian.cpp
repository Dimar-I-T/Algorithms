#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t > 0){
        unsigned long long l, r, banyak3 = 0;
        cin >> l >> r;
        if(l % 2 == 1){
            if (r % 2 == 0){
                if (((r - l) / 2) % 2 == 0){
                    cout << (r ^ l) << "\n";
                }else{
                    cout << (l ^ (r + 1)) << "\n";
                }
            }else{
                if (((r - l) / 2) % 2 == 0){
                    cout << l << "\n";
                }else{
                    cout << (l ^ 1) << "\n";
                }
            }
        }else{
            if (r % 2 == 0){
                if (((r - l + 1) / 2) % 2 == 0){
                    cout << r << "\n";
                }else{
                    cout << r + 1 << "\n";
                }
            }else{
                if (((r - l + 1) / 2) % 2 == 0){
                    cout << 0 << "\n";
                }else{
                    cout << 1 << "\n";
                }
            }
        }
        
        t--;
    }
}
