#include <iostream>
#include <vector>
#include <set>
 
using namespace std;
 
vector<vector<pair<int, int>>> g;
multiset<pair<int, int>> edges;
set<int> connected;
 
void mst(int &last, long long &ans) {
    for (auto i: g[last]) {
        if (connected.find(i.second) == connected.end()) {
            edges.insert(i);
        }
    }
 
    while (connected.find(edges.begin()->second) != connected.end()) {
        edges.erase(*edges.begin());
    }
 
    last = edges.begin()->second;
    connected.insert(last);
    ans += edges.begin()->first;
    edges.erase(*edges.begin());
}
 
int main() {
    freopen("spantree3.in", "r", stdin);
    freopen("spantree3.out", "w", stdout);
 
    int n, m;
    cin >> n >> m;
 
    g = vector<vector<pair<int, int>>>(n);
    int u, v, w;
 
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        g[u - 1].push_back(make_pair(w, v - 1));
        g[v - 1].push_back(make_pair(w, u - 1));
    }
 
    connected.insert(0);
    int last = 0;
    long long ans = 0;
 
    while (connected.size() != n) {
        mst(last, ans);
    }
 
    cout << ans;
 
    return 0;
}