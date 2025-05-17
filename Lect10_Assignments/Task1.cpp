// Exercise 1: Connected components
// Given an undirected computer network with n nodes (numbered from 1 to n) and m
// edges, your task is to write a program to calculate the number of connected
// components.
// Input:
// ● The first line contains two number n and m separated by spaces
// ● The next m lines, each contains two numbers x and y (separated by spaces)
// indicating an edge between x and y.
// Output: The output consists of the number of connected components.
// Example:
// Input
// 5 3
// 1 2
// 2 3
// 3 5

// Output
// 2
#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, adj, visited);
        }
    }
}
// Đánh dấu đỉnh hiện tại đã được thăm
// Duyệt qua tất cả các đỉnh kề chưa được thăm và gọi đệ quy DFS

int countConnectedComponents(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n + 1, false); // Các đỉnh được đánh số từ 1 đến n
    int count = 0;
    
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            DFS(i, adj, visited);
            count++;
        }
    }    
    return count;
}
// Khởi tạo mảng visited để theo dõi các đỉnh đã thăm
// Với mỗi đỉnh chưa thăm, thực hiện DFS và tăng biến đếm

int main() {
    int n, m;
    cin >> n >> m; 
    vector<vector<int>> adj(n + 1); // Danh sách kề (adjacency list)   
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x); // Đồ thị vô hướng
    }
    cout << countConnectedComponents(n, adj);
    return 0;
}
