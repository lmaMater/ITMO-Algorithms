#include <iostream>
#include <vector>
 
using namespace std;
 
typedef long long ll;
ll counter = 0;
 
void merge_sort(vector<ll>& v, ll begin, ll end) {
    if (begin == end) {
        return;
    }
 
    ll mid = (begin + end) / 2;
 
    merge_sort(v, begin, mid);
    merge_sort(v, mid + 1, end);
 
    vector<ll> temp;
    for (ll i = begin, j = mid + 1; i <= mid || j <= end;) {
        if (i > mid) {
            temp.push_back(v[j++]);
        } else if (j > end) {
            temp.push_back(v[i++]);
        } else if (v[i] > v[j]) {
            temp.push_back(v[j++]);
            counter += mid - i + 1;
        } else {
            temp.push_back(v[i++]);
        }
    }
 
    for (ll i = 0; i < temp.size(); i++) {
        v[begin + i] = temp[i];
    }
}
 
int main() {
    freopen("inversions.in", "r", stdin);
    freopen("inversions.out", "w", stdout);
 
    vector<ll> vec;
    ll n, el;
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> el;
        vec.push_back(el);
    }
    merge_sort(vec, 0, n - 1);
 
    cout << counter;
 
    return 0;
}