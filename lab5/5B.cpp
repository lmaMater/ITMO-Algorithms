#include <iostream>
#include <vector>
 
using namespace std;
 
vector<vector<int>> tree;
 
bool checkTree(int index, int lower_bound, int upper_bound) {
    if (tree[index][1] != 0) {
        int new_upper_bound = min(tree[index][0], upper_bound);
        int child_value = tree[tree[index][1]][0];
        if (child_value < new_upper_bound && child_value > lower_bound) {
            if (!checkTree(tree[index][1], lower_bound, new_upper_bound)) {
                return false;
            }
        } else {
            return false;
        }
    }
 
    if (tree[index][2] != 0) {
        int new_lower_bound = max(tree[index][0], lower_bound);
        int child_value = tree[tree[index][2]][0];
        if (child_value < upper_bound && child_value > new_lower_bound) {
            if (!checkTree(tree[index][2], new_lower_bound, upper_bound)) {
                return false;
            }
        } else {
            return false;
        }
    }
 
    return true;
}
 
int main() {
    freopen("check.in", "r", stdin);
    freopen("check.out", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin >> n;
 
    // vertex= [key, left, right]
    tree = vector<vector<int>>(n, vector<int>(3, 0));
 
    int k, l, r;
    for (int i = 0; i < n; i++) {
        cin >> k >> l >> r;
        tree[i][0] = k;
        if (l > 0) {
            tree[i][1] = l - 1;
        }
        if (r > 0) {
            tree[i][2] = r - 1;
        }
    }
 
    if (n == 0 || checkTree(0, -1e9, 1e9)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
 
    return 0;
}