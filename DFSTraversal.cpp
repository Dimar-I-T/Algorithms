#include <bits/stdc++.h>
using namespace std;
// Dimar's Code of DFS Traversal
vector<vector<int>> connection(696969);
vector<bool> visited(696969);

void DFS(int s){
    cout << s << " ";
    visited[s] = 1;
    for (int x = 0; x < connection[s].size(); x++){
        if (!visited[connection[s][x]]){
            DFS(connection[s][x]);
        }
    } 
}

int main(){
    int numberOfConnections, startsAt;
    cin >> numberOfConnections >> startsAt;
    for (int x = 0; x < numberOfConnections; x++){
        int l, r;
        cin >> l >> r;
        connection[l].push_back(r);
        connection[r].push_back(l);
    }

    DFS(startsAt);
}