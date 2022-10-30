#include <iostream>
#include <vector>
 
using namespace std;
 
vector<int> visited;
vector<vector<int>> graph;
 
void dfs(int vertex, int component) {
    if (visited[vertex]) {
        return;
    }
 
    visited[vertex] = component;
 
    for (int i = 0; i < graph[vertex].size(); i++) {
        dfs(graph[vertex][i], component);
    }
}
 
int main() {
    freopen("components.in", "r", stdin);
    freopen("components.out", "w", stdout);
 
    int n, m, row, column;
    cin >> n >> m;
 
    visited = vector<int>(n, 0);
    graph = vector<vector<int>>(n, vector<int>());
 
    for (int i = 0; i < m; i++) {
        cin >> row >> column;
        graph[row - 1].push_back(column - 1);
        graph[column - 1].push_back(row - 1);
    }
 
    int counter = 0;
 
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, counter + 1);
            counter++;
        }
    }
 
    cout << counter << '\n';
 
    for (int i = 0; i < n; i++) {
        cout << visited[i] << ' ';
    }
 
    return 0;
}