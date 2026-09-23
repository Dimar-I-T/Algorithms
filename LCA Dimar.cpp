#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val = 0;
    int depth = 0;
    int idxAtWalkArr = 0;
    TreeNode* left = NULL;
    TreeNode* right = NULL;
};

struct DepthNode {
    int depth = 0;
    int node = 0;
};

const int MAXN = 1e5;
const int LOG = 18;

vector<TreeNode*> nodes(MAXN + 1);
vector<int> binTree(4 * MAXN); 
vector<DepthNode> walkArr;
vector<bool> visited(MAXN + 1);
vector<int> idxAtWalkArr(MAXN + 1);
vector<vector<DepthNode>> st(MAXN, vector<DepthNode>(LOG));

void dfs(TreeNode* root, int d) {
    if (visited[root->val]) {
        return;
    }

    visited[root->val] = 1;
    idxAtWalkArr[root->val] = walkArr.size();
    walkArr.push_back({d, root->val});
    root->depth = d;
    if (root->left != NULL) {
        dfs(root->left, d + 1);
        walkArr.push_back({d, root->val});
    }

    if (root->right != NULL) {
        dfs(root->right, d + 1);
        walkArr.push_back({d, root->val});
    }
}

DepthNode minn(DepthNode a, DepthNode b) {
    if (a.depth < b.depth) {
        return a;
    } else {
        return b;
    }
}

void buildSparseTable(const vector<DepthNode>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) st[i][0] = arr[i];
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = minn(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

DepthNode querySparseTable(int L, int R) {
    int j = __lg(R - L + 1); 
    return minn(st[L][j], st[R - (1 << j) + 1][j]);
}

int main() {
    // input: n, array 2n + 1 isinya array dari binary tree
    int n, m;
    cin >> n >> m;
    for (int x = 0; x <= n; x++) {
        nodes[x] = new TreeNode(x);
    }

    for (int x = 0; x < m; x++) {
        cin >> binTree[x];
    }

    TreeNode* root = nodes[binTree[0]];
    for (int x = 1; x < m; x++) {
        if (binTree[x] == -1) {
            continue;
        }

        int parentIdx = (x - 1) / 2;
        if (x % 2 == 0) {
            nodes[binTree[parentIdx]]->right = nodes[binTree[x]];
        } else {
            nodes[binTree[parentIdx]]->left = nodes[binTree[x]];
        }
    }

    dfs(root, 0);
    buildSparseTable(walkArr);
    int lNode = 6;
    int rNode = 8;
    cout << "coba l node: " << lNode << "\n";
    cout << "coba r node: " << rNode << "\n";

    int l = min(idxAtWalkArr[lNode], idxAtWalkArr[rNode]);
    int r = max(idxAtWalkArr[lNode], idxAtWalkArr[rNode]);
    cout << "LCA: " << querySparseTable(l, r).node;
}