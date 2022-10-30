#include <iostream>
#include <vector>
 
using namespace std;
 
void input_vec(vector<int> &vec, int size) {
    int elem;
    for (int i = 0; i < size; i++) {
        cin >> elem;
        vec.push_back(elem);
    }
}
 
bool is_heap(vector<int> vec) {
    for (int i = 0; 2 * i + 1 < vec.size(); i++) {
        if (vec[i] > vec[2 * i + 1]) {
            return false;
        }
        if (2 * i + 2 < vec.size() && vec[i] > vec[2 * i + 2]) {
            return false;
        }
    }
    return true;
}
 
int main() {
    freopen("isheap.in", "r", stdin);
    freopen("isheap.out", "w", stdout);
    vector<int> vec;
    int n;
    cin >> n;
    input_vec(vec, n);
    if (is_heap(vec)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
 
    return 0;
}