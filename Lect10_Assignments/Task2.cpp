// Exercise 2: Shortest path
// Given a directed computer network with n nodes (numbered from 1 to n) and m
// edges, your task is to write a program to find the shortest path that has the minimum
// number of edges between two node X and Y.
// Input:
// ● The first line contains four number n, m, X, Y separated by spaces
// ● The next m lines, each contains two numbers x and y (separated by spaces)
// indicating an edge from x to y.
// Output: The output consists of the number of edges in the shortest path from X to Y.
// Example:
// Input
// 5 5 1 5
// 1 2
// 2 3
// 3 4
// 4 5
// 2 5

//  Output
//   2

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int shortestPath(int n, vector<vector<int>>& adj, int X, int Y) {
    vector<int> distance(n + 1, -1); // Khoảng cách từ X đến các nút
    queue<int> q;
    // distance lưu số cạnh từ X đến mỗi nút (khởi tạo -1)
    // q là hàng đợi cho BFS
    
    distance[X] = 0; // Bắt đầu từ nút X với khoảng cách 0
    q.push(X);
    
    while (!q.empty()) { // Lấy nút đầu hàng đợi để xử lý
        int current = q.front();
        q.pop();
        // Với mỗi nút kề chưa thăm, cập nhật khoảng cách và thêm vào hàng đợi
        for (int neighbor : adj[current]) {
            if (distance[neighbor] == -1) { // Nếu chưa thăm
                distance[neighbor] = distance[current] + 1;
                q.push(neighbor);
                
                if (neighbor == Y) {
                    return distance[Y]; // Nếu tìm thấy Y, trả về khoảng cách ngay
                }
            }
        }
    }
    
    return -1; // Không có đường đi
}

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;   
    vector<vector<int>> adj(n + 1); // Danh sách kề  
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y); // Đồ thị có hướng
    }  
    int result = shortestPath(n, adj, X, Y);
    cout << result;  
    return 0;
}
