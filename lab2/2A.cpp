#include <iostream>
#include <vector>
 
using namespace std;
 
void merge_sort(vector<int> &v, int begin, int end) {
    if (begin == end) return;
 
    int mid = (begin + end) / 2;
    merge_sort(v, begin, mid);
    merge_sort(v, mid + 1, end);
 
    vector<int> temp;
    for (int i = begin, j = mid + 1; i <= mid || j <= end;) {
        if (i > mid) {
            temp.push_back(v[j++]);
        } else if (j > end) {
            temp.push_back(v[i++]);
        } else if (v[i] <= v[j]) {
            temp.push_back(v[i++]);
        } else {
            temp.push_back(v[j++]);
        }
    }
 
    for (int i = 0; i < temp.size(); i++) {
        v[begin + i] = temp[i];
    }
}
 
int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
 
    vector<int> vec;
    int n, el;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> el;
        vec.push_back(el);
    }
    merge_sort(vec, 0, n - 1);
 
    cout << vec[0];
    for (int i = 1; i < n; i++) {
        cout << ' ' << vec[i];
    }
 
    return 0;
}