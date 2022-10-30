#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
int main() {
    freopen("pathbge1.in", "r", stdin);
    freopen("pathbge1.out", "w", stdout);
 
    vector<vector<int>> graph;
    vector<int> distances;
 
    int n, m, row, column;
    cin >> n >> m;
 
    graph = vector<vector<int>>(n, vector<int>());
    distances = vector<int>(n, 0);
 
    for (int i = 0; i < m; i++) {
        cin >> row >> column;
        graph[row - 1].push_back(column - 1);
        graph[column - 1].push_back(row - 1);
    }
 
    vector<bool> visited = vector<bool>(n, false);
    queue<int> to_visit;
    to_visit.push(0);
 
    while(!to_visit.empty()) {
        int vertex = to_visit.front();
        visited[vertex] = true;
        to_visit.pop();
 
        for (int i = 0; i < graph[vertex].size(); i++) {
            if (!visited[graph[vertex][i]] && !distances[graph[vertex][i]]) {
                to_visit.push(graph[vertex][i]);
                distances[graph[vertex][i]] = distances[vertex] + 1;
            }
        }
    }
 
    for (int i = 0; i < n; i++) {
        cout << distances[i] << ' ';
    }
 
    return 0;
}