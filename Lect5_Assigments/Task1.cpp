#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* firstChild;
    Node* nextSibling;
    Node(int val) : data(val), firstChild(nullptr), nextSibling(nullptr) {}
};

class Tree {
private:
    int height;
    Node* root;
    Node** nodes; // Array to store pointers to nodes
    bool* isChild; // Array to track if a node is a child of another node

    Node* newNode(int val) {
        return new Node(val);
    }

    void AddChild(int u, int v) {
        if (nodes[u] == nullptr) {
            nodes[u] = newNode(u);
        }
        if (nodes[v] == nullptr) {
            nodes[v] = newNode(v);
        }

        Node* parent = nodes[u];
        Node* child = nodes[v];

        if (parent->firstChild == nullptr) {
            parent->firstChild = child;
        } else {
            Node* temp = parent->firstChild;
            while (temp->nextSibling != nullptr) {
                temp = temp->nextSibling;
            }
            temp->nextSibling = child;
        }

        isChild[v] = true; // Mark v as a child
    }

    void UpdateRoot(int n) {
        for (int i = 1; i <= n; i++) {
            if (nodes[i] != nullptr && !isChild[i]) {
                root = nodes[i];
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
            child = child->nextSibling;
        }
        return maxHeight;
    }

    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        Node* child = node->firstChild;
        while (child) {
            preorder(child);
            child = child->nextSibling;
        }
    }

    void postorder(Node* node) {
        if (!node) return;
        Node* child = node->firstChild;
        while (child) {
            postorder(child);
            child = child->nextSibling;
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
            child = child->nextSibling;
        }
        return true;
    }

    void inorder(Node* node) {
        if (!node) return;
        Node* child = node->firstChild;
        if (child) {
            inorder(child);
            child = child->nextSibling;
        }
        cout << node->data << " ";
        if (child) {
            inorder(child);
        }
    }

public:
    Tree(int n, int m) : height(0), root(nullptr) {
        nodes = new Node*[n + 1]; // Allocate memory for nodes
        isChild = new bool[n + 1]; // Allocate memory for isChild array
        for (int i = 0; i <= n; i++) {
            nodes[i] = nullptr; // Initialize all nodes to nullptr
            isChild[i] = false; // Initialize all isChild flags to false
        }

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            AddChild(u, v);
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
        for (int i = 1; nodes[i] != nullptr; i++) {
            deleteTree(nodes[i]);
        }
        delete[] nodes; // Free memory for nodes array
        delete[] isChild; // Free memory for isChild array
    }

private:
    void deleteTree(Node* node) {
        if (!node) return;
        Node* child = node->firstChild;
        while (child) {
            Node* next = child->nextSibling;
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
