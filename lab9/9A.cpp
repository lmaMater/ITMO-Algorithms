#include <iostream>
#include <vector>
 
using namespace std;
 
enum color {
    WHITE,  // not visited
    GRAY,   // visiting now
    BLACK   // exited
};
 
vector<color> vertexes;
vector<vector<int>> graph;
vector<int> ans;
 
void dfs(int vertex, bool &cycle) {
    vertexes[vertex] = GRAY;
 
    for (int i: graph[vertex]) {
        if (vertexes[i] == WHITE) {
            dfs(i, cycle);
        } else if (vertexes[i] == GRAY) {
            cycle = true;
            return;
        }
    }
    vertexes[vertex] = BLACK;
    ans.push_back(vertex);
}
 
int main() {
    int n, m;
    cin >> n >> m;
 
    graph = vector<vector<int>>(n);
 
    int beg, end;
    for (int i = 0; i < m; i++) {
        cin >> beg >> end;
        graph[--beg].push_back(--end);
    }
 
    vertexes = vector<color>(n, WHITE);
    bool cycle = false;
 
    for (int i = 0; i < n && !cycle; i++) {
        if (vertexes[i] == WHITE) {
            dfs(i, cycle);
        }
    }
 
    if (cycle) {
        cout << -1;
    } else {
        for (int i = n - 1; i >= 0; i--) {
            if (i != n - 1) {
                cout << ' ';
            }
            cout << ++ans[i];
        }
    }
 
    return 0;
}