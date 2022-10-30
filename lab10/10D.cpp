#include <iostream>
#include <vector>
#include <stack>
#include <set>
 
using namespace std;
 
struct Edge {
public:
    int begin{};
    int end{};
    int weight{};
 
    Edge() = default;
 
    Edge(int b, int e, int w) :
            begin(b), end(e), weight(w) {}
};
 
int n, m, root;
vector<Edge> edges;
vector<set<int>> graph, zero_graph, reversed_zero_graph;
vector<bool> used;
stack<int> out;
vector<int> components;
 
void DFS(int vertex, vector<set<int>> &g) {
    used[vertex] = true;
    for (int child: g[vertex]) {
        if (!used[child]) {
            DFS(child, g);
        }
    }
    out.push(vertex);
}
 
void reversedDFS(int vertex, int &component) {
    used[vertex] = true;
    components[vertex] = component;
 
    for (int child: reversed_zero_graph[vertex]) {
        if (!used[child]) {
            reversedDFS(child, component);
        }
    }
}
 
void condensation() {
    fill(used.begin(), used.end(), false);
    out = stack<int>();
    for (int i = 0; i < graph.size(); i++) {
        if (!used[i]) {
            DFS(i, zero_graph);
        }
    }
 
    fill(used.begin(), used.end(), false);
    components.resize(graph.size());
    int component = 0;
 
    while (!out.empty()) {
        int cur = out.top();
        if (!used[cur]) {
            reversedDFS(cur, component);
            component++;
        }
        out.pop();
    }
 
    vector<set<int>> new_graph(component);
    for (int i = 0; i < graph.size(); i++) {
        for (auto elem: graph[i]) {
            if (components[i] != components[elem]) {
                new_graph[components[i]].insert(components[elem]);
            }
        }
    }
 
    root = components[root];
    graph = new_graph;
}
 
long long twoChinese() {
    long long res = 0;
    vector<int> min_edges(graph.size(), 1e9 + 1);
 
    for (auto e: edges) {
        min_edges[e.end] = min(e.weight, min_edges[e.end]);
    }
 
    for (int i = 0; i < graph.size(); i++) {
        if (i != root) {
            res += min_edges[i];
        }
    }
 
    zero_graph = vector<set<int>>(graph.size());
    reversed_zero_graph = vector<set<int>>(graph.size());
    for (auto e: edges) {
        if (e.weight == min_edges[e.end]) {
            zero_graph[e.begin].insert(e.end);
            reversed_zero_graph[e.end].insert(e.begin);
        }
    }
 
 
    used = vector<bool>(graph.size(), false);
    DFS(root, zero_graph);
 
    bool ok = true;
    for (auto el: used) {
        if (!el) {
            ok = false;
            break;
        }
    }
    if (ok) {
        return res;
    }
 
    condensation();
 
    vector<Edge> new_edges;
    for (auto e: edges) {
        if (components[e.begin] != components[e.end]) {
            new_edges.emplace_back(components[e.begin], components[e.end],
                                   e.weight - min_edges[e.end]);
        }
    }
    edges = new_edges;
    res += twoChinese();
    return res;
}
 
int main() {
    freopen("chinese.in", "r", stdin);
    freopen("chinese.out", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n >> m;
 
    graph.resize(n);
 
    int b, e, w;    // begin, end, weight
    for (int i = 0; i < m; i++) {
        cin >> b >> e >> w;
        edges.emplace_back(b - 1, e - 1, w);
        graph[b - 1].insert(e - 1);
    }
 
    used.resize(n, false);
    root = 0;
    DFS(root, graph);
 
    for (auto el: used) {
        if (!el) {
            cout << "NO";
            return 0;
        }
    }
 
    cout << "YES" << '\n';
 
    components.resize(n);
    for (int i = 0; i < n; i++) {
        components[i] = i;
    }
 
    long long ans = twoChinese();
    cout << ans;
 
    return 0;
}