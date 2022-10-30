#include <iostream>
#include <vector>
 
using namespace std;
 
struct Vertex {
    int left = 0;
    int right = 0;
    int height = 1;
    int balance = 0;
};
 
vector<Vertex> tree;
 
void dfs(int index) {
    if (tree[index].left || tree[index].right) {
        dfs(tree[index].left);
        dfs(tree[index].right);
        tree[index].height = max(tree[tree[index].left].height,
                                 tree[tree[index].right].height) + 1;
        tree[index].balance = tree[tree[index].right].height -
                              tree[tree[index].left].height;
    } else {
        return;
    }
}
 
int main() {
    freopen("balance.in", "r", stdin);
    freopen("balance.out", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    tree = vector<Vertex>(n + 1);
    tree[0].height = 0;
 
    int k;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        cin >> tree[i].left >> tree[i].right;
    }
 
    dfs(1);
     
    for (int i = 1; i <= n; i++) {
        cout << tree[i].balance << '\n';
    }
    return 0;
}