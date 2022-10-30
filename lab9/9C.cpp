#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
enum color {
    NO_COLOR,
    RED,
    BLACK
};
 
vector<color> vertexes;
vector<vector<int>> graph;
queue<int> q;
 
void bfs(int vertex, bool &ok) {
    for (int i: graph[vertex]) {
        if (vertexes[i] == NO_COLOR) {
            vertexes[i] = vertexes[vertex] == RED ? BLACK : RED;
            q.push(i);
        } else if (vertexes[i] == vertexes[vertex]) {
            ok = false;
            return;
        }
    }
}
 
int main() {
    int n, m;
    cin >> n >> m;
 
    graph = vector<vector<int>>(n);
 
    int beg, end;
    for (int i = 0; i < m; i++) {
        cin >> beg >> end;
        graph[--beg].push_back(--end);
        graph[end].push_back(beg);
    }
 
    vertexes = vector<color>(n, NO_COLOR);
 
    bool ok = true;
    for (int i = 0; i < n && ok; i++) {
        if (vertexes[i] == NO_COLOR) {
            vertexes[i] = RED;
            q.push(i);
 
            while (!q.empty() && ok){
                bfs(q.front(), ok);
                q.pop();
            }
        }
    }
 
    string ans = ok ? "YES" : "NO";
    cout << ans;
 
    return 0;
}