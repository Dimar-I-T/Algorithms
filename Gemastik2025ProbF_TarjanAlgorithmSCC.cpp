#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node {
    ll id = 0;
    ll b = 0;
    vector<Node*> dipanahOleh{0};
    vector<Node*> memanah{0};
};

ll foundat=1;
vector<Node*> nodes;
vector<vector<ll>> scc;
vector<ll> disc, low; 
vector<bool> onstack;

void tarjan(Node* u){
    static stack<ll> st;

    disc[u->id]=low[u->id]=foundat++;
    st.push(u->id);
    onstack[u->id]=true;
    for(Node* i : nodes[u->id]->memanah){
        if(disc[i->id]==-1){
            tarjan(i);
            low[u->id]=min(low[u->id],low[i->id]);
        }
        else if(onstack[i->id])
            low[u->id]=min(low[u->id],disc[i->id]);
    }
    
    if(disc[u->id]==low[u->id]){
        vector<ll> scctem;
        while(1){
            ll v=st.top();
            st.pop();onstack[v]=false;
            scctem.push_back(v);
            if(u->id==v)
                break;
        }
        scc.push_back(scctem);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    nodes.resize(n + 1);
    disc.clear();disc.resize(n+1,-1);
    low.clear();low.resize(n+1);
    onstack.clear();onstack.resize(n + 1);
    for (ll x = 0; x < n; x++) {
        ll bi;
        cin >> bi;
        nodes[x + 1] = new Node(x + 1, bi, vector<Node*>(0), vector<Node*>(0));
    }

    vector<ll> K(k);
    for (ll x = 0; x < k; x++) {
        cin >> K[x];
    }

    sort(K.begin(), K.end());

    for (ll x = 0; x < m; x++) {
        ll u, v;
        cin >> u >> v;
        nodes[u]->memanah.push_back(nodes[v]);
        nodes[v]->dipanahOleh.push_back(nodes[u]);
    }

    for (ll x = 1; x <= n; x++) {
        if (disc[x] == -1) {
            tarjan(nodes[x]);
        }
    }
    
    // first id node, second b node
    vector<pair<ll, ll>> minNode; 
    minNode.resize(n + 1, {-1, INT_MAX});
    vector<ll> noSCC(n + 1);
    vector<ll> harusDijaga;
    int nos = 1;
    for (ll x = 0; x < scc.size(); x++) {
        ll banyakMasuk = 0;
        ll minB = INT_MAX;
        for (ll y = 0; y < scc[x].size(); y++) {
            noSCC[scc[x][y]] = nos;
        }
        
        for (ll y = 0; y < scc[x].size(); y++) {
            vector<Node*> masuk = nodes[scc[x][y]]->dipanahOleh;
            for (Node* in : masuk) {
                if (noSCC[in->id] != nos) {
                    banyakMasuk++;
                }
            }
            
            minB = min(minB, nodes[scc[x][y]]->b);
        }
        
        if (banyakMasuk == 0) {
            harusDijaga.push_back(minB);
        }
        
        nos++;
    }
    
    if (k < harusDijaga.size()) {
        cout << "-1";
    } else {
        sort(harusDijaga.rbegin(), harusDijaga.rend());
        ll sum = 0;
        for (int x = 0; x < harusDijaga.size(); x++) {
            sum += harusDijaga[x] * K[x];
        }
        
        cout << sum;
    }
}