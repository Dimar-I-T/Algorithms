#include <iostream>
#include <vector>
#define mp make_pair
#define f first
#define s second

using namespace std;
vector<int> a(100001), seg(4*100001);
vector<pair<int, pair<int, int>>> itv(100001); // 0 kiri 1 kanan
vector<pair<int, int>> idxUjung(100001); // 0 kiri 1 kanan
int hasil = 0;

void Seg(int idx, int kiri, int kanan, int letak){
      itv[idx] = mp(letak, mp(kiri, kanan));
      if (kiri == kanan){
            seg[idx] = a[kiri];
            idxUjung[kiri] = mp(letak, idx); 
            return;
      }
      
      int tengah = (kiri + kanan)/2;
      Seg(2*idx + 1, kiri, tengah, 0);
      Seg(2*idx + 2, tengah + 1, kanan, 1);
      seg[idx] = seg[2*idx + 1] + seg[2*idx + 2];
}

int S(int idx, int tKiri, int tKanan){
      if (itv[idx].s.f >= tKiri && itv[idx].s.s <= tKanan){
            return seg[idx];
      }else if (itv[idx].s.f > tKanan || itv[idx].s.s < tKiri){
            return 0;
      }else{
            return S(2*idx + 1, tKiri, tKanan) + S(2*idx + 2, tKiri, tKanan);
      }
}

void Update(int idx, int tambah){
      seg[idx] += tambah;
      if (idx == 0){
            return;
      }else{
            // kanan
            if (itv[idx].f){
                  Update((idx - 1)/2, tambah);
            }else{
                  Update(idx/2, tambah);
            }
      }
}

int main(){
      int n, t;
      cin >> n >> t;
      for (int x = 0; x < n; x++){
            cin >> a[x];
      }
      
      Seg(0, 0, n - 1, 0);
      for (int x = 0; x < t; x++){
            int kiri, kanan;
            cin >> kiri >> kanan;
            int idx = idxUjung[kiri - 1].s;
            Update(idx, kanan - seg[idx]);
      }
      
      for (int x = 0; x < 2*n; x++){
            cout << seg[x] << " ";
      }
}