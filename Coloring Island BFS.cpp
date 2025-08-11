#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

int arr[1000][1000] = {-1};
bool sudah[1000][1000] = {0};
int batasR = 0, batasC = 0; 

void BFS(int r, int c, int p){
    queue<pair<int, int>> q;
    q.push({r, c});
    while (!q.empty()){
        pair<int, int> pa = q.front();
        sudah[pa.f][pa.s] = 1;
        // atas, bawah, kanan, kiri
        int pr[] = {-1, 1, 0, 0};
        int pc[] = {0, 0, 1, -1};
        for (int x = 0; x < 4; x++){
            int r_ = pa.f + pr[x], c_ = pa.s + pc[x];
            if (arr[r_][c_] == arr[pa.f][pa.s] && !sudah[r_][c_] && r_ > 0 && c_ > 0 && r_ <= batasR && c_ <= batasC){
                q.push({r_, c_});
            }
        }
        
        arr[pa.f][pa.s] = p;
        q.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, r, c, p;
    cin >> n >> m >> r >> c >> p;
    batasR = n;
    batasC = m;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            int a;
            cin >> a;
            arr[x + 1][y + 1] = a;
        }
    }
    
    BFS(r + 1, c + 1, p);
    
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            cout << arr[x + 1][y + 1];
        }
        
        cout << "\n";
    }
}
