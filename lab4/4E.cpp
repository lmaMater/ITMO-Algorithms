#include <iostream>
#include <cstdio>
 
using namespace std;
 
int leftBinSearch(int a[], int len, int key) {
    int left = -1, right = len;
 
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (key > a[mid]) {
            left = mid;
        } else {
            right = mid;
        }
    }
    if (a[right] == key) {
        return right + 1;
    } else {
        return -1;
    }
}
 
int rightBinSearch(int a[], int len, int key) {
    int left = -1, right = len;
 
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (key >= a[mid]) {
            left = mid;
        } else {
            right = mid;
        }
    }
    if (a[left] == key) {
        return left + 1;
    } else {
        return -1;
    }
}
 
int main() {
    freopen("binsearch.in", "r", stdin);
    freopen("binsearch.out", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m, key;
    cin >> n;
    int *arr = new int[n];
 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
 
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> key;
        cout << leftBinSearch(arr, n, key) << ' ';
        cout << rightBinSearch(arr, n, key) << '\n';
    }
 
    return 0;
}