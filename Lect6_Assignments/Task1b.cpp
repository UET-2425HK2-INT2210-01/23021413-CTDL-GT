// Ban đầu:
//          2                                                   
//         / \
//        1   10
//           /  \
//          6    13
//         / \    \                               
//        3   8    20
//           /
//          7
// Đã chèn 14 0 35:
//         2
//        / \
//       1   10
//      /   /  \
//     0   6    13
//          / \    \
//         3   8    20
//            /    /  \
//           7    14   35

// ... (previous code remains the same)

int main() {
    int numbers[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    Node* root = nullptr;
    for (int num : numbers) {
        insert(root, num);
    }
    insert(root, 14);
    insert(root, 0);
    insert(root, 35);
    cout << "Inorder traversal of the updated BST: ";
    inorderTraversal(root);
    cout << endl;
    
    return 0;
}
