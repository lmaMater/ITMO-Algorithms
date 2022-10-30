#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int n, x;
    cin >> n;
 
    vector<vector<int>> graph;
    graph = vector<vector<int>>(n, vector<int>(n));
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;
            graph[i][j] = x;
        }
    }
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (graph[i][j] != graph[j][i] ||
                (i == j && graph[i][j] != 0)) {
                cout << "NO";
                return 0;
            }
        }
    }
 
    cout << "YES";
 
    return 0;
}