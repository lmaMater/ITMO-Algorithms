#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
struct Vertex {
    int key;
    int left;
    int right;
    int height = 0;
};
 
vector<Vertex> vec;
 
int countHeight(int i) {
    if (i < 0) {
        return 0;
    } else {
        int leftHeight = countHeight(vec[i].right);
        int rightHeight = countHeight(vec[i].left);
        vec[i].height = max(leftHeight, rightHeight) + 1;
 
        return vec[i].height;
    }
}
 
int getHeight(int index) {
    if (index < 0) {
        return 0;
    } else {
        return vec[index].height;
    }
}
 
int rotateLeft(int index) {
    int new_root = vec[index].right;
    vec[index].right = vec[new_root].left;
    vec[new_root].left = index;
 
    countHeight(index);
    countHeight(new_root);
 
    return new_root;
}
 
int rotateRight(int index) {
    int new_root = vec[index].left;
    vec[index].left = vec[new_root].right;
    vec[new_root].right = index;
 
    countHeight(index);
    countHeight(new_root);
 
    return new_root;
}
 
int bigRotateLeft(int index) {
    vec[index].right = rotateRight(vec[index].right);
    return rotateLeft(index);
}
 
void printTree(int begin_vertex) {
    int counter = 1;
    queue<int> q;
 
    q.push(begin_vertex);
    cout << vec.size() << '\n';
 
    while (!q.empty()) {
        int left = 0, right = 0;
        int cur = q.front();
        q.pop();
 
        if (vec[cur].left != -1) {
            counter++;
            left = counter;
 
            q.push(vec[cur].left);
        }
        if (vec[cur].right != -1) {
            counter++;
            right = counter;
 
            q.push(vec[cur].right);
        }
        cout << vec[cur].key << ' ';
        cout << left << ' ';
        cout << right << '\n';
    }
}
 
 
int main() {
    freopen("rotation.in", "r", stdin);
    freopen("rotation.out", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, k, l, r;
    cin >> n;
    vec = vector<Vertex>(n);
 
    for (int i = 0; i < n; i++) {
        cin >> k >> l >> r;
        vec[i].key = k;
        vec[i].left = l - 1;
        vec[i].right = r - 1;
    }
 
    countHeight(0);
    int left_h = getHeight(vec[vec[0].right].left);
    int right_h = getHeight(vec[vec[0].right].right);
 
    if (right_h - left_h == -1) {
        printTree(bigRotateLeft(0));
    } else {
        printTree(rotateLeft(0));
    }
 
    return 0;
}