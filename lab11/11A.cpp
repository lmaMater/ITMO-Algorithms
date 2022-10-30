#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
struct MinHeap {
public:
    vector<pair<ll, int>> vec;
 
    MinHeap() = default;
 
    bool isEmpty() {
        return vec.empty();
    }
 
    void siftUp(int index) {
        while (vec[index] < vec[(index - 1) / 2]) {
            swap(vec[index], vec[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }
 
    void siftDown(int index) {
        while (2 * index + 1 < vec.size()) {
            int l = 2 * index + 1;
            int r = 2 * index + 2;
            int swap_index = -1;
 
            if (r < vec.size() && vec[r] < vec[l]) {
                swap_index = r;
            } else if (vec[l] < vec[index]) {
                swap_index = l;
            }
 
            if (swap_index != -1) {
                swap(vec[index], vec[swap_index]);
                index = swap_index;
            } else {
                break;
            }
        }
    }
 
    void insert(pair<ll, int> element) {
        vec.push_back(element);
        siftUp(vec.size() - 1);
    }
 
    pair<ll, int> getMin() {
        return vec[0];
    }
 
    void extractMin() {
        swap(vec[0], vec[vec.size() - 1]);
        vec.pop_back();
        siftDown(0);
    }
};
 
ll MAX = 2000000000000;
vector<vector<pair<ll, int>>> graph;
vector<ll> distances;
vector<bool> taken;
MinHeap q;
 
void dijkstra(int start, int n) {
    taken.resize(n, false);
    distances.resize(n, MAX);
    distances[start] = 0;
    q.insert(make_pair(0, start));
 
    for (int i = 0; i < n - 1 && !q.isEmpty(); i++) {
        while (taken[q.getMin().second] && !q.isEmpty()) {
            q.extractMin();
        }
        if (q.isEmpty()) {
            break;
        }
 
        pair<int, int> cur = q.getMin();
        q.extractMin();
        if (distances[cur.second] == MAX) {
            break;
        }
 
        taken[cur.second] = true;
        for (auto edge: graph[cur.second]) {
            if (edge.first + distances[cur.second] < distances[edge.second]) {
                distances[edge.second] = edge.first + distances[cur.second];
                q.insert(make_pair(distances[edge.second], edge.second));
            }
        }
    }
}
 
int main() {
    freopen("pathmgep.in", "r", stdin);
    freopen("pathmgep.out", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, s, f;
    cin >> n >> s >> f;
 
    ll rel;
    graph.resize(n);
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> rel;
            if (rel > 0) {
                graph[i].emplace_back(rel, j);
            }
        }
    }
 
    dijkstra(s - 1, n);
 
    if (distances[f - 1] == MAX) {
        cout << -1;
    } else {
        cout << distances[f - 1];
    }
 
 
    return 0;
}