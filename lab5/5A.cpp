#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    freopen("height.in", "r", stdin);
    freopen("height.out", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, max_h = 0;
    cin >> n;
 
    // vertex= [key, left, right, height]
    vector<vector<int>> tree(n, vector<int>(4, 0));
 
    int k, l, r;
    for (int i = 0; i < n; i++) {
        cin >> k >> l >> r;
        tree[i][0] = k;
        tree[i][1] = l;
        tree[i][2] = r;
        if (l != 0) {
            tree[l - 1][3] = tree[i][3] + 1;
            max_h = max(max_h, tree[l - 1][3]);
        }
        if (r != 0) {
            tree[r - 1][3] = tree[i][3] + 1;
            max_h = max(max_h, tree[r - 1][3]);
        }
    }
 
    if (n == 0) {
        cout << 0;
    } else {
        cout << max_h + 1;
    }
 
    return 0;
}