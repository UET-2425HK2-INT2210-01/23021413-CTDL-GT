#include <iostream>
#include <unordered_map> // Hash - map
using namespace std;

struct Node {
    int data;
    Node* firstChild;
    Node* nextSliding;
    Node(int val) : data(val), firstChild(nullptr), nextSliding(nullptr) {}
};

class Tree {
private:
    int height;
    Node* root;
    unordered_map<int, Node*> nodeMap; 
    unordered_map<int, bool> isChild;  

    Node* newNode(int val) {
        return new Node(val);
    }

    void AddChild(int u, int v) {
        if (nodeMap.find(u) == nodeMap.end()) {
            nodeMap[u] = newNode(u);
        }
        if (nodeMap.find(v) == nodeMap.end()) {
            nodeMap[v] = newNode(v);
        }

        Node* parent = nodeMap[u];
        Node* child = nodeMap[v];

        if (parent->firstChild == nullptr) {
            parent->firstChild = child;
        } else {
            Node* temp = parent->firstChild;
            while (temp->nextSliding != nullptr) {
                temp = temp->nextSliding;
            }
            temp->nextSliding = child;
        }
    }

    void UpdateRoot(int n) {
        for (int i = 1; i <= n; i++) {
            if (nodeMap.find(i) != nodeMap.end() && isChild.find(i) == isChild.end()) {
                root = nodeMap[i];
                break;
            }
        }
    }

    int calculateHeight(Node* node) {
        if (!node) return 0;
        int maxHeight = 0;
        Node* child = node->firstChild;
        while (child) {
            maxHeight = max(maxHeight, 1 + calculateHeight(child));
            child = child->nextSliding;
        }
        return maxHeight;
    }

    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        Node* child = node->firstChild;
        while (child) {
            preorder(child);
            child = child->nextSliding;
        }
    }

    void postorder(Node* node) {
        if (!node) return;
        Node* child = node->firstChild;
        while (child) {
            postorder(child);
            child = child->nextSliding;
        }
        cout << node->data << " ";
    }

    bool isBinary(Node* node) {
        if (!node) return true;
        int childCount = 0;
        Node* child = node->firstChild;
        while (child) {
            childCount++;
            if (childCount > 2) return false;
            if (!isBinary(child)) return false;
            child = child->nextSliding;
        }
        return true;
    }

    void inorder(Node* node) {
        if (!node) return;
        Node* child = node->firstChild;
        if (child) {
            inorder(child); 
            child = child->nextSliding;
        }
        cout << node->data << " ";
        if (child) {
            inorder(child); 
        }
    }

public:
    Tree(int n, int m) : height(0), root(nullptr) {
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            AddChild(u, v);
            isChild[v] = true; 
        }
        UpdateRoot(n);
        height = calculateHeight(root);
    }

    void process() {
        cout << height << endl;
        preorder(root);
        cout << endl;
        postorder(root);
        cout << endl;
        if (isBinary(root)) {
            inorder(root);
            cout << endl;
        } else {
            cout << "NOT BINARY TREE" << endl;
        }
    }

    ~Tree() {
        for (auto& pair : nodeMap) {
            deleteTree(pair.second);
        }
    }

private:
    void deleteTree(Node* node) {
        if (!node) return;
        Node* child = node->firstChild;
        while (child) {
            Node* next = child->nextSliding;
            deleteTree(child);
            child = next;
        }
        delete node;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Tree tree(n, m);
    tree.process();
    return 0;
}
