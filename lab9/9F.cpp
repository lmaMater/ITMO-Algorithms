#include <iostream>
#include <vector>
 
using namespace std;
 
vector<vector<int>> graph;
vector<int> sorted;
vector<bool> used, pl;
 
void dfs(int vertex) {
    used[vertex] = true;
 
    for (int i: graph[vertex]) {
        if (!used[i]) {
            dfs(i);
        }
    }
    sorted.push_back(vertex);
}
 
void check_len(int vertex) {
    for (int i: graph[vertex]) {
        if (!pl[i]) {
            pl[vertex] = true;
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m, s;
    cin >> n >> m >> s;
 
    graph = vector<vector<int>>(n);
 
    int beg, end;
    for (int i = 0; i < m; i++) {
        cin >> beg >> end;
        graph[beg - 1].push_back(end - 1);
    }
 
    used = vector<bool>(n, false);
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }
 
    pl = vector<bool>(n, false);
 
    for (int i = 0; i < n; i++) {
        check_len(sorted[i]);
    }
 
    if (pl[s - 1]) {
        cout << "First player wins";
    } else {
        cout << "Second player wins";
    }
 
    return 0;
}