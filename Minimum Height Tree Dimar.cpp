class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> koneksi(n);
        vector<int> banyakSisi(n);
        vector<int> hasil;
        if (n == 1){
            hasil.push_back(0);
            return hasil;
        }

        vector<int> panjang(n);
        queue<int> q;
        for (int x = 0; x < n - 1; x++){
            koneksi[edges[x][0]].push_back(edges[x][1]);
            koneksi[edges[x][1]].push_back(edges[x][0]);
            banyakSisi[edges[x][0]]++;
            banyakSisi[edges[x][1]]++;
        }
        
        for (int x = 0; x < n; x++){
            if (banyakSisi[x] == 1){
                q.push(x);
            }
        }
        
        while (n > 2){
            int sek = q.front();
            banyakSisi[sek]--;
            for (auto x: koneksi[sek]){
                if (banyakSisi[x] > 0){
                    panjang[x] = max(panjang[x], panjang[sek] + 1);
                    banyakSisi[x]--;
                }

                if (banyakSisi[x] == 1){
                    q.push(x);
                }
            }

            n--;
            q.pop();
        }
        
        while (!q.empty()){
            hasil.push_back(q.front());
            q.pop();
        }

        if ((panjang[hasil[0]] + panjang[hasil[1]]) % 2 != 0){
            hasil.erase(hasil.begin() + 0);
        }

        return hasil;
    }
};