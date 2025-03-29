#include <iostream>
using namespace std;
struct Node {
    int data;       // Lưu giá trị của node
    Node* left;     // Con trỏ trỏ tới node con bên trái
    Node* right;    // Con trỏ trỏ tới node con bên phải
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
    // khởi tạo node với giá trị val, left và right trỏ tới nullptr
};

void insert(Node* &root, int val) {
    if (root == nullptr) {          // Nếu cây rỗng (hoặc đến vị trí cần chèn)
        root = new Node(val);       // Tạo node mới với giá trị val
        return;                     // Kết thúc hàm
    }
    
    if (val < root->data) {         // Nếu giá trị cần chèn nhỏ hơn giá trị node hiện tại
        insert(root->left, val);    // Đệ quy chèn vào cây con bên trái
    } else {                        // Ngược lại (lớn hơn hoặc bằng)
        insert(root->right, val);   // Đệ quy chèn vào cây con bên phải
    }
}

void inorderTraversal(Node* root) {
    if (root == nullptr) return;    // Nếu node hiện tại rỗng thì dừng
    inorderTraversal(root->left);   // Đệ quy duyệt cây con bên trái
    cout << root->data << " ";      // In giá trị node hiện tại
    inorderTraversal(root->right);  // Đệ quy duyệt cây con bên phải
}

int main() {
    int numbers[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};  // Mảng số đầu vào
    Node* root = nullptr;            // Khởi tạo cây rỗng
    for (int num : numbers) {        // Duyệt qua từng số trong mảng
        insert(root, num);           // Chèn số vào BST
    }
    cout << "Inorder traversal of the BST: ";
    inorderTraversal(root);         // Duyệt cây theo thứ tự in-order
    cout << endl;
    return 0;
}
