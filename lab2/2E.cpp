#include <iostream>
#include <vector>
 
using namespace std;
 
vector<int> a;
int n;
 
int find_order(int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        if (right <= left + 1) {
            if ((left == right - 1) && a[left] > a[right]) {
                swap(a[left], a[right]);
            }
            return a[key];
        }
 
        if (a[left] > a[right]) {
            swap(a[left], a[right]);
        }
        if (a[left + 1] > a[right]) {
            swap(a[left + 1], a[right]);
        }
        if (a[left] > a[left + 1]) {
            swap(a[left], a[left + 1]);
        }
 
        int pivot = a[left + 1];
        int i = left + 1, j = right;
        while (i <= j) {
            while (a[++i] < pivot) {}
            while (a[--j] > pivot) {}
            if (i > j) break;
            swap(a[i], a[j]);
        }
        swap(a[j], a[left + 1]);
        if (j >= key) right = j - 1;
        if (i <= key) left = i;
    }
}
 
int main() {
    freopen("kth.in", "r", stdin);
    freopen("kth.out", "w", stdout);
    int k, A, B, C, a1, a2;
    cin >> n >> k >> A >> B >> C >> a1 >> a2;
    a.push_back(a1);
    a.push_back(a2);
    for (int i = 2; i < n; i++) {
        a.push_back(A * a[i - 2] + B * a[i - 1] + C);
    }
 
    int ans = find_order(k - 1);
    cout << ans;
 
    return 0;
}