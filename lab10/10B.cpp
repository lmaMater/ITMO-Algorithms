#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
 
using namespace std;
 
struct MinHeap {
public:
    vector<pair<float, int>> vec;
 
    MinHeap() = default;
 
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
 
    void insert(pair<float, int> element) {
        vec.push_back(element);
        siftUp(vec.size() - 1);
    }
 
    pair<float, int> getMin() {
        return vec[0];
    }
 
    void extractMin() {
        swap(vec[0], vec[vec.size() - 1]);
        vec.pop_back();
        siftDown(0);
    }
 
    // void decreaseKey() {}
};
 
int n;
vector<pair<int, int>> graph;
MinHeap q;
vector<bool> taken;
 
float count_distance(pair<int, int> p1, pair<int, int> p2) {
    return (float) sqrt(pow(p1.first - p2.first, 2)
                        + pow(p1.second - p2.second, 2));
}
 
void mst(int &last, double &ans) {
    for (int i = 1; i < n; i++) {
        if (!taken[i]) {
            q.insert(make_pair(count_distance(graph[last], graph[i]), i));
        }
    }
 
    while (taken[q.getMin().second]) {
        q.extractMin();
    }
 
    auto cur = q.getMin();
    last = cur.second;
    taken[last] = true;
    ans += cur.first;
    q.extractMin();
}
 
int main() {
    freopen("spantree.in", "r", stdin);
    freopen("spantree.out", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n;
 
    taken.resize(n, false);
    graph.resize(n);
    int x, y;
 
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        graph[i] = make_pair(x - 1, y - 1);
    }
 
    // begin with 0-vertex
    double ans = 0;
    taken[0] = true;
    int last = 0;
 
    for (int i = 0; i < n - 1; i++) {
        mst(last, ans);
    }
 
    cout << setprecision(20) << ans;
 
    return 0;
}