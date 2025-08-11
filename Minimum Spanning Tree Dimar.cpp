class Solution {
public:
#define f first
#define s second
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> sudah(n);
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<pair<int, int>> banyakDanParent(n);
        vector<vector<int>> anak(n);
        for (int x = 0; x < n; x++) {
            banyakDanParent[x].s = x;
            anak[x].push_back(x);
            for (int y = x + 1; y < n; y++) {
                //cout << x << " <-> " << y << " + " << abs(points[x][0] - points[y][0]) + abs(points[x][1] - points[y][1]) << "\n";
                pq.push({-(abs(points[x][0] - points[y][0]) +
                           abs(points[x][1] - points[y][1])),
                         {x, y}});
            }
        }
        
        int hasil = 0, banyak = 0;
        int k = 0;
        while (!pq.empty()) {
            if (banyak == n - 1){
                break;
            }

            pair<int, pair<int, int>> p = pq.top();
            int a = p.second.first, b = p.second.second, j = -p.first;
            //cout << a << " <-> " << b << " + " << j << "\n";
            int parentA = banyakDanParent[a].s;
            int parentB = banyakDanParent[b].s;
            int banyakParentA = anak[parentA].size();
            int banyakParentB = anak[parentB].size();
            // cout << "parentnya " << a << " = " << parentA << "\n";
            // cout << "parentnya " << b << " = " << parentB << "\n";
            if (parentA == parentB){
                //cout << "sama\n";
                pq.pop();
                continue;
            }else{
                if (banyakParentA > banyakParentB){
                    //cout << "Anaknya " << parentA << " = ";
                    for (auto x: anak[parentB]){
                        //cout << x << " ";
                        banyakDanParent[x].s = parentA;
                        anak[parentA].push_back(x);
                        banyakDanParent[parentA].f++;
                    }

                    //cout << "\n";
                }else{
                    //cout << "Anaknya " << parentB << " = ";
                    for (auto x: anak[parentA]){
                        //cout << x << " ";
                        banyakDanParent[x].s = parentB;
                        anak[parentB].push_back(x);
                        banyakDanParent[parentB].f++;
                    }

                    //cout << "\n";
                }
                
                hasil += j;
                banyak++;
            }
            
            pq.pop();
        }

        return hasil;
    }
};