#include <iostream>
#include <vector>
 
using namespace std;
 
vector<int> lengths;
vector<vector<int>> graph;
 
void dfs(int vertex, int &maximum) {
    int max_child = 0;
    for (int i : graph[vertex]) {
        if (lengths[i] == -1) {
            dfs(i, maximum);
        }
        max_child = max(max_child, lengths[i]);
    }
    lengths[vertex] = max_child + 1;
    maximum = max(maximum, max_child + 1);
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
 
    lengths = vector<int>(n, -1);
    int maximum = 0;
 
    for (int i = 0; i < n; i++) {
        if (lengths[i] == -1) {
            dfs(i, maximum);
        }
    }
 
    string ans = maximum == n ? "YES" : "NO";
    cout << ans;
 
    return 0;
}