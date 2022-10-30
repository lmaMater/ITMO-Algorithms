#include <iostream>
 
using namespace std;
 
int main() {
 
    freopen("smallsort.in", "r", stdin);
    freopen("smallsort.out", "w", stdout);
 
    int n;
    cin >> n;
    int A[n];
 
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
 
    // bubble sort
    int counter;
    for (int i = 0; i < n; ++i) {
        counter = 0;
        for (int j = 0; j < n - 1; ++j) {
            if (A[j] > A[j + 1]) {
                counter++;
                swap(A[j], A[j + 1]);
            }
        }
        if (counter == 0) {
            break;
        }
    }

    cout << A[0];
    for (int i = 1; i < n; ++i) {
        cout << ' ' << A[i];
    }
 
    return 0;
}