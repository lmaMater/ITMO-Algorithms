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
    if (cycle) {
        return;
    }
 
    vertexes[vertex] = GRAY;
    ans.push_back(vertex);
 
    for (int i: graph[vertex]) {
        if (vertexes[i] == WHITE) {
            dfs(i, cycle);
        } else if (vertexes[i] == GRAY) {
            cycle = true;
            ans.push_back(i);
            return;
        }
 
        if (cycle) {
            return;
        }
    }
    vertexes[vertex] = BLACK;
    ans.pop_back();
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
        cout << "YES\n";
 
        int index = ans.size() - 2;
        for (; ans[index] != ans.back(); index--) {}
        for (; index < ans.size() - 1; index++) {
            cout << ans[index] + 1;
            if (index != ans.size() - 2) {
                cout << ' ';
            }
        }
 
 
    } else {
        cout << "NO";
    }
 
    return 0;
}