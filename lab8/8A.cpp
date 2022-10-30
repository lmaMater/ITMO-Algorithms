#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int n, m, row, column;
    cin >> n >> m;
 
    vector<vector<int>> graph;
    graph = vector<vector<int>>(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        cin >> row >> column;
        graph[row - 1][column - 1] = 1;
    }
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }
 
    return 0;
}