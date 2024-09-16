#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define mp make_pair
#define f first
#define s second

using namespace std;
vector<vector<int>> tetangga(10001);
vector<int> jarak(10001);
vector<bool> pernah(10001);

void BFS(int dari, int target){
      queue<int> q;
      q.push(dari);
      bool selesai = false;
      while (!q.empty() || !selesai){
            pernah[q.front()] = 1;
            for (int x = 0; x < tetangga[q.front()].size(); x++){
                  int ke = tetangga[q.front()][x];
                  if (!pernah[ke]){
                        jarak[ke] = jarak[q.front()] + 1;
                        q.push(ke);
                  }
                  
                  if (ke == target){
                        jarak[ke] = jarak[q.front()] + 1;
                        selesai = true;
                        break;
                  }
            }
            
            q.pop();
      }
}

int main(){
      int n, a, b;
      cin >> n >> a >> b;
      
      for (int x = 0; x < n - 1; x++){
            int kiri, kanan;
            cin >> kiri >> kanan;
            tetangga[kiri].push_back(kanan);
            tetangga[kanan].push_back(kiri);
      }
      
      BFS(a, b);
      cout << jarak[b];
}