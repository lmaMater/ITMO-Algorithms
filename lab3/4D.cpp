#include <iostream>
 
using namespace std;
 
int parent(int i) {
    return i / 2;
}
 
int left(int i) {
    return 2 * i;
}
 
int right(int i) {
    return 2 * i + 1;
}
 
void siftDown(int a[], int index, int n) {
    int l = left(index);
    int r = right(index);
    int smallest = index;
 
    if (l <= n && a[l] < a[smallest]) {
        smallest = l;
    }
 
    if (r <= n && a[r] < a[smallest]) {
        smallest = r;
    }
 
    if (smallest != index) {
        swap(a[index], a[smallest]);
 
        siftDown(a, smallest, n);
    }
}
 
void queueExtractMin(int a[], int &n) {
    if (n < 1) {
        cout << "*\n";
    } else {
        int min = a[1];
        a[1] = a[n];
        n--;
        siftDown(a, 1, n);
        cout << min << "\n";
    }
}
 
void queueDecreaseKey(int a[], int i, int key) {
    a[i] = key;
    while (i > 1 && a[parent(i)] > a[i]) {
        swap(a[i], a[parent(i)]);
        i = parent(i);
    }
}
 
void queueInsert(int a[], int key, int &n) {
    n++;
    a[n] = INT_MAX;
    queueDecreaseKey(a, n, key);
}
 
int main() {
    freopen("priorityqueue.in", "r", stdin);
    freopen("priorityqueue.out", "w", stdout);
 
    int commands[100000], queue[100000];
    string command;
    int x, y;
    int n = 0, counter = 0;
 
    while (cin >> command) {
        if (command == "push") {
            cin >> x;
            queueInsert(queue, x, n);
        } else if (command == "extract-min") {
            x = -1;
            queueExtractMin(queue, n);
        } else if (command == "decrease-key") {
            cin >> x >> y;
            int i;
            for (i = 1; i <= n; i++) {
                if (commands[x] == queue[i]) {
                    break;
                }
            }
            queueDecreaseKey(queue, i, y);
            commands[x] = y;
        }
 
        counter++;
        commands[counter] = x;
    }
 
    return 0;
}