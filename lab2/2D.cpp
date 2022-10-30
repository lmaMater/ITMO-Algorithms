#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    freopen("antiqs.in", "r", stdin);
    freopen("antiqs.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> vec;
 
    for (int i = 1; i <= n; i++) {
        vec.push_back(i);
    }
    for (int i = 0; i < n; i++) {
        swap(vec[i], vec[i / 2]);
    }
    cout << vec[0];
    for (int i = 1; i < n; i++) {
        cout << ' ' << vec[i];
    }
    return 0;
}