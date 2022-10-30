#include <iostream>
#include <vector>
#include <stack>
 
using namespace std;
 
stack<int> out;
vector<bool> used;
vector<vector<int>> graph, reversed_graph;
vector<int> ans;
 
void dfs1(int vertex) {
    used[vertex] = true;
    for (int child: graph[vertex]) {
        if (!used[child]) {
            dfs1(child);
        }
    }
    out.push(vertex);
}
 
void dfs2(int vertex, int &component) {
    used[vertex] = true;
    ans[vertex] = component;
 
    for (int child: reversed_graph[vertex]) {
        if (!used[child]) {
            dfs2(child, component);
        }
    }
}
 
int main() {
    int n, m;
    cin >> n >> m;
 
    graph = vector<vector<int>>(n);
    reversed_graph = vector<vector<int>>(n);
 
 
    int beg, end;
    for (int i = 0; i < m; i++) {
        cin >> beg >> end;
        graph[--beg].push_back(--end);
        reversed_graph[end].push_back(beg);
    }
 
    used = vector<bool>(n, false);
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs1(i);
        }
    }
 
    used = vector<bool>(n, false);
    ans = vector<int>(n);
    int component = 0;
 
    while (!out.empty()) {
        int cur = out.top();
        if (!used[cur]) {
            component++;
            dfs2(cur, component);
        }
        out.pop();
    }
 
    cout << component << '\n';
    for (int comp : ans) {
        cout << comp << ' ';
    }
 
    return 0;
}