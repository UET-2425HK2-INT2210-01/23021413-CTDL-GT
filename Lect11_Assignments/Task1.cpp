// Given n cities (numbered from 1 to n) and m roads connecting cities. The dirty level between two cities u, v is D[u,v] (D[u,v] might be negative). You have two tasks:
// a. Write a program to find a path from a starting point s to the end point e such that the total dirty level on the path is the smallest.
// b. Write a program to find the shortest paths for all pairs of vertices
// Input: Data come from file dirty.txt in the following format:
// - The first line contains four integer numbers n, m, s, e
// - m following lines each contains 3 integer numbers u, v, d indicating that the dirty level of road from u to v is d.
// Output: Results are written to file “dirty.out” in the following format:
// - The first line contains the total dirty level of the path from s to e.
// - The second line contains cities on the path from s to e.
// - The next n lines each contains n integer numbers are the shortest distance matrix for all pairs of vertices. (output INF if there is no path between two cities).
// Example:
// dirty.txt
// 5 9 3 2
// 1 2 5
// 2 3 2
// 4 3 4
// 4 5 1
// 5 1 1
// 5 2 3
// 3 5 7
// 1 4 2
// 3 1 3

// dirty.out
// 8
// 3 1 2
// 0 5 6 2 3
// 5 0 2 7 8
// 3 8 0 5 6
// 2 4 4 0 1
// 1 3 5 3 0

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX / 2;

void printPath(vector<int>& parent, int e, ofstream& out) {
    if (parent[e] == -1) { // parent là mảng lưu vết đường đi, e là đỉnh đích cần in đường đi tới
        out << e << " ";
        return;
    } // Nếu parent[e] == -1 nghĩa là đã đến điểm bắt đầu thì in ra
    printPath(parent, parent[e], out); // Ngược lại gọi đệ quy để in đường đi tới đỉnh trước đó rồi mới in đỉnh hiện tại
    out << e << " ";
}

void task_a(int n, vector<vector<pair<int, int>>>& adj, int s, int e, ofstream& out) {
    vector<int> dist(n + 1, INF);    // Mảng khoảng cách
    vector<int> parent(n + 1, -1);   // Mảng lưu vết đường đi
    vector<bool> visited(n + 1, false); // Mảng đánh dấu đỉnh đã thăm
    
    dist[s] = 0;  // Khoảng cách từ điểm bắt đầu đến chính nó = 0
    
     for (int i = 1; i <= n; ++i) {
        int u = -1;
        for (int j = 1; j <= n; ++j) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;  // Chọn đỉnh có khoảng cách nhỏ nhất chưa xét
            }
        }
        
        if (dist[u] == INF) break;  // Không còn đỉnh nào có thể đến được
        visited[u] = true;  // Đánh dấu đỉnh u đã xét
        
       for (auto edge : adj[u]) {
            int v = edge.first;
            int d = edge.second;
            if (dist[v] > dist[u] + d) {
                dist[v] = dist[u] + d;  // Cập nhật khoảng cách
                parent[v] = u;  // Lưu vết đường đi
            }
        }
    }
    
    out << dist[e] << endl;  // In tổng độ bẩn nhỏ nhất
    printPath(parent, e, out);  // In đường đi
    out << endl;
}

void task_b(int n, vector<vector<int>>& dist) {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j]; // Cập nhật khoảng cách
                }
            }
        }
    }
} // Thuật toán 3 vòng lặp lồng nhau
  // Kiểm tra nếu đi qua đỉnh trung gian k sẽ cho đường đi ngắn hơn
  // Cập nhật ma trận khoảng cách dist

int main() {
    ifstream in("dirty.txt");
    ofstream out("dirty.out");
    
    int n, m, s, e;
    in >> n >> m >> s >> e;  // Đọc số thành phố, số đường, điểm đầu, điểm cuối
    
    vector<vector<pair<int, int>>> adj(n + 1);  // Danh sách kề
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));  // Ma trận khoảng cách
    
    for (int i = 1; i <= n; ++i) {
        dist[i][i] = 0;  // Khoảng cách từ 1 đỉnh đến chính nó = 0
    }
    // Đọc các thông số cơ bản
    // Khởi tạo danh sách kề và ma trận khoảng cách
    // Đặt khoảng cách từ 1 đỉnh đến chính nó bằng 0
    for (int i = 0; i < m; ++i) {
        int u, v, d;
        in >> u >> v >> d;  // Đọc thông tin mỗi con đường
        adj[u].push_back({v, d});  // Thêm vào danh sách kề
        dist[u][v] = d;  // Cập nhật vào ma trận khoảng cách
    }   
    // Task a
    task_a(n, adj, s, e, out);
    // Task b
    task_b(n, dist);
    
    // Output distance matrix
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dist[i][j] == INF) {
                out << "INF ";  // Không có đường đi
            } else {
                out << dist[i][j] << " ";  // In khoảng cách
            }
        }
        out << endl;
    }
    in.close();
    out.close();
    return 0;
}
