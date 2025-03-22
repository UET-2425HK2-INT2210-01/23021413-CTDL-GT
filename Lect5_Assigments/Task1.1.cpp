#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Tree {
private:
    vector<vector<int>> adj;  // Adjacency list
    int n;                    // Number of nodes
    
    // Calculate height starting from node u
    int getHeight(int u, vector<bool>& visited) {
        visited[u] = true;
        int height = 0;
        for(int v : adj[u]) {
            if(!visited[v]) {
                height = max(height, 1 + getHeight(v, visited));
            }
        }
        return height;
    }
    
    // Preorder traversal
    void preorder(int u, vector<bool>& visited, vector<int>& result) {
        visited[u] = true;
        result.push_back(u);
        for(int v : adj[u]) {
            if(!visited[v]) {
                preorder(v, visited, result);
            }
        }
    }
    
    // Postorder traversal
    void postorder(int u, vector<bool>& visited, vector<int>& result) {
        visited[u] = true;
        for(int v : adj[u]) {
            if(!visited[v]) {
                postorder(v, visited, result);
            }
        }
        result.push_back(u);
    }
    
    // Inorder traversal (for binary tree)
    void inorder(int u, vector<bool>& visited, vector<int>& result) {
        visited[u] = true;
        int childCount = adj[u].size();
        
        if(childCount > 0) {
            inorder(adj[u][0], visited, result);  // Left child
        }
        result.push_back(u);
        if(childCount > 1) {
            inorder(adj[u][1], visited, result);  // Right child
        }
    }
    
    // Check if binary tree (max 2 children per node)
    bool isBinary() {
        for(int i = 1; i <= n; i++) {
            if(adj[i].size() > 2) {
                return false;
            }
        }
        return true;
    }
    
    // Find root (node with no parent)
    int findRoot(vector<int>& parentCount) {
        for(int i = 1; i <= n; i++) {
            if(parentCount[i] == 0) {
                return i;
            }
        }
        return 1;  // Default to 1 if no root found
    }

public:
    Tree(int nodes) : n(nodes) {
        adj.resize(n + 1);
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    
    void processTree() {
        // Find root
        vector<int> parentCount(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            for(int v : adj[i]) {
                parentCount[v]++;
            }
        }
        int root = findRoot(parentCount);
        
        // Calculate height
        vector<bool> visited(n + 1, false);
        cout << getHeight(root, visited) << endl;
        
        // Preorder traversal
        vector<int> pre_result;
        visited.assign(n + 1, false);
        preorder(root, visited, pre_result);
        for(int i = 0; i < pre_result.size(); i++) {
            cout << pre_result[i];
            if(i < pre_result.size() - 1) cout << " ";
        }
        cout << endl;
        
        // Postorder traversal
        vector<int> post_result;
        visited.assign(n + 1, false);
        postorder(root, visited, post_result);
        for(int i = 0; i < post_result.size(); i++) {
            cout << post_result[i];
            if(i < post_result.size() - 1) cout << " ";
        }
        cout << endl;
        
        // Check binary and do inorder if applicable
        if(isBinary()) {
            vector<int> in_result;
            visited.assign(n + 1, false);
            inorder(root, visited, in_result);
            for(int i = 0; i < in_result.size(); i++) {
                cout << in_result[i];
                if(i < in_result.size() - 1) cout << " ";
            }
        } else {
            cout << "NOT BINARY TREE";
        }
        cout << endl;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    
    Tree tree(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        tree.addEdge(u, v);
    }
    
    tree.processTree();
    return 0;
}
