#include <iostream>
#include <vector>
#define mp make_pair
#define f first
#define s second

using namespace std;
vector<int> a(100001), seg(4*100001);
vector<pair<int, int>> itv(100001); 
int hasil = 0;

void Seg(int idx, int kiri, int kanan){
      itv[idx] = mp(kiri, kanan);
      if (kiri == kanan){
            seg[idx] = a[kiri];
            return;
      }
      
      int tengah = (kiri + kanan)/2;
      Seg(2*idx + 1, kiri, tengah);
      Seg(2*idx + 2, tengah + 1, kanan);
      seg[idx] = seg[2*idx + 1] + seg[2*idx + 2];
}

int S(int idx, int tKiri, int tKanan){
      if (itv[idx].f >= tKiri && itv[idx].s <= tKanan){
            return seg[idx];
      }else if (itv[idx].f > tKanan || itv[idx].s < tKiri){
            return 0;
      }else{
            return S(2*idx + 1, tKiri, tKanan) + S(2*idx + 2, tKiri, tKanan);
      }
}

int main(){
      int n, t;
      cin >> n >> t;
      for (int x = 0; x < n; x++){
            cin >> a[x];
      }
      
      Seg(0, 0, n - 1);
      for (int x = 0; x < t; x++){
            int kiri, kanan;
            cin >> kiri >> kanan;
            int h = S(0, kiri - 1, kanan - 1);
            cout << h << "\n";
      }
}