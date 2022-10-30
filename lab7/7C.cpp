#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
struct Input {
    int key;
    int left;
    int right;
 
    Input(int k = 0, int l = -1, int r = -1) {
        key = k;
        left = l;
        right = r;
    }
};
 
vector<Input> vec;
int length;
 
struct Vertex {
    int key;
    Vertex *left;
    Vertex *right;
    int height;
 
    Vertex(int k = 0, Vertex *l = nullptr, Vertex *r = nullptr, int h = 1) {
        key = k;
        left = l;
        right = r;
        height = h;
    }
};
 
class AVL {
private:
    Vertex *root;
    int length;
 
    Vertex *fillTree(int index) {
        if (index < 0 || vec.empty()) {
            return nullptr;
        }
 
        Vertex *cur = new Vertex(vec[index].key);
        length++;
        cur->left = fillTree(vec[index].left);
        cur->right = fillTree(vec[index].right);
        cur->height = max(getHeight(cur->left),
                          getHeight(cur->right)) + 1;
        return cur;
    }
 
    int getHeight(Vertex *n) {
        if (n == nullptr) {
            return 0;
        } else {
            return n->height;
        }
    }
 
    int countBalance(Vertex *n) {
        if (n == nullptr) {
            return 0;
        } else {
            return getHeight(n->right) - getHeight(n->left);
        }
    }
 
    void updateHeight(Vertex *n) {
        n->height = max(getHeight(n->left), getHeight(n->right)) + 1;
    }
 
    Vertex *rotateLeft(Vertex *vertex) {
        if (vertex == nullptr) {
            return vertex;
        }
 
        Vertex *right_subtree = vertex->right;
        vertex->right = right_subtree->left;
        right_subtree->left = vertex;
 
        updateHeight(vertex);
        updateHeight(right_subtree);
 
        return right_subtree;
    }
 
    Vertex *rotateRight(Vertex *vertex) {
        if (vertex == nullptr)
            return vertex;
 
        Vertex *left_subtree = vertex->left;
        vertex->left = left_subtree->right;
        left_subtree->right = vertex;
 
        updateHeight(vertex);
        updateHeight(left_subtree);
 
        return left_subtree;
    }
 
 
    Vertex *balance(Vertex *n) {
        if (countBalance(n) == 2) {
            if (countBalance(n->right) == -1) {
                n->right = rotateRight(n->right);
            }
 
            return rotateLeft(n);
        } else if (countBalance(n) == -2) {
            if (countBalance(n->left) == 1) {
                n->left = rotateLeft(n->left);
            }
 
            return rotateRight(n);
        }
 
        return n;
    }
 
 
    Vertex *ins(int k, Vertex *n) {
        if (n == nullptr) {
            length++;
            return new Vertex(k);
        }
 
        if (k > n->key) {
            n->right = ins(k, n->right);
        } else if (k < n->key) {
            n->left = ins(k, n->left);
        } else {
            return n;
        }
 
        updateHeight(n);
        return balance(n);
    }
 
public:
    AVL() {
        length = 0;
        root = fillTree(0);
    }
 
    void insert(int k) {
        root = ins(k, root);
    }
 
    void print() {
        int counter = 1;
        queue<Vertex *> q;
 
        q.push(root);
        cout << length << '\n';
 
        while (!q.empty()) {
            int left = 0;
            int right = 0;
 
            Vertex *n = q.front();
            q.pop();
 
            if (n->left != nullptr) {
                q.push(n->left);
                left = ++counter;
            }
            if (n->right != nullptr) {
                q.push(n->right);
                right = ++counter;
            }
 
            cout << n->key << ' ';
            cout << left << ' ';
            cout << right << '\n';
        }
    }
};
 
 
int main() {
    freopen("addition.in", "r", stdin);
    freopen("addition.out", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int k, l, r;
    cin >> length;
    vec = vector<Input>(length);
 
    for (int i = 0; i < length; i++) {
        cin >> k >> l >> r;
        vec[i].key = k;
        vec[i].left = l - 1;
        vec[i].right = r - 1;
    }
 
    AVL avl_tree;
    int x;
    cin >> x;
 
    if (length == 0) {
        cout << "1\n" << x << " 0 0";
    } else {
        avl_tree.insert(x);
        avl_tree.print();
    }
 
    return 0;
}