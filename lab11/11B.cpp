#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
typedef long long ll;
 
ll MAX = 20000000000;
vector<vector<pair<ll, int>>> graph;
vector<ll> distances;
vector<bool> taken;
auto cmp = [](pair<ll, int> a, pair<ll, int> b) { return a.first > b.first; };
priority_queue<pair<ll, int>, std::vector<pair<ll, int>>, decltype(cmp)> q(cmp);
 
void dijkstra(int start, int n) {
    std::fill(taken.begin(), taken.end(), false);
    std::fill(distances.begin(), distances.end(), MAX);
    distances[start] = 0;
    q.push(make_pair(0, start));
 
    for (int i = 0; i < n; i++) {
        while (taken[q.top().second] && !q.empty()) {
            q.pop();
        }
        if (q.empty()) {
            break;
        }
 
        auto cur = pair<ll, int>(q.top());
        q.pop();
        if (distances[cur.second] == MAX) {
            break;
        }
 
        taken[cur.second] = true;
        for (auto edge: graph[cur.second]) {
            if (edge.first + distances[cur.second] < distances[edge.second]) {
                distances[edge.second] = edge.first + distances[cur.second];
                q.push(make_pair(distances[edge.second], edge.second));
            }
        }
    }
}
 
void clearQueue() {
    while (!q.empty()) {
        q.pop();
    }
}
 
void printRow() {
    for (auto elem: distances) {
        cout << elem << ' ';
    }
    cout << '\n';
}
 
int main() {
    freopen("pathsg.in", "r", stdin);
    freopen("pathsg.out", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m;
    cin >> n >> m;
 
    graph.resize(n);
    ll b, e, w;
    for (int i = 0; i < m; i++) {
        cin >> b >> e >> w;
        graph[b - 1].emplace_back(w, e - 1);
    }
 
    distances.resize(n);
    taken.resize(n);
    for (int i = 0; i < n; i++) {
        dijkstra(i, n);
        printRow();
        clearQueue();
    }
 
 
    return 0;
}