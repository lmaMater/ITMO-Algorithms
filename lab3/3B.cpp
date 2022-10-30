#include <iostream>
#include <vector>
 
using namespace std;
 
void inputHeap(vector<int> &heap, int size) {
    int elem;
    for (int i = 0; i < size; i++) {
        cin >> elem;
        heap.push_back(elem);
    }
}
 
void printVec(vector<int> vec) {
    int size = vec.size();
    cout << vec[0];
    for (int i = 1; i < size; i++) {
        cout << ' ' << vec[i];
    }
}
 
void heapify(vector<int> &heap, int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
 
    if (left < size && heap[largest] < heap[left]) {
        largest = left;
    }
 
    if (right < size && heap[largest] < heap[right]) {
        largest = right;
    }
 
    if (largest != i) {
        swap(heap[largest], heap[i]);
 
        heapify(heap, size, largest);
    }
}
 
void heapSort(vector<int> &heap, int size) {
    for (int i = (size / 2) - 1; i >= 0; i--) {
        heapify(heap, size, i);
    }
 
    for (int i = size - 1; i >= 0; i--) {
        swap(heap[0], heap[i]);
        heapify(heap, i, 0);
    }
}
 
int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    vector<int> heap;
    int n;
    cin >> n;
    inputHeap(heap, n);
    heapSort(heap, n);
    printVec(heap);
 
    return 0;
}