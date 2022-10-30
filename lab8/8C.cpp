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
 
    bool ans = false;
    for (int i = 0; i < m; i++) {
        cin >> row >> column;
        if (graph[row - 1][column - 1]) {
            ans = true;
        } else {
            graph[row - 1][column - 1] = 1;
            graph[column - 1][row - 1] = 1;
        }
    }
 
    if (ans) {
        cout << "YES";
    } else {
        cout << "NO";
    }
 
    return 0;
}