#include <iostream>
#include <vector>
 
using namespace std;
 
void stable_sort(vector<pair<string, string>> &v, int begin, int end) {
    if (begin == end) return;
 
    int mid = (begin + end) / 2;
    stable_sort(v, begin, mid);
    stable_sort(v, mid + 1, end);
 
    vector<pair<string, string>> temp;
    for (int i = begin, j = mid + 1; i <= mid || j <= end;) {
        if (i > mid) {
            temp.push_back(v[j++]);
        } else if (j > end) {
            temp.push_back(v[i++]);
        } else if (v[i].first <= v[j].first) {
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
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
 
    string country, surname;
    int n;
    cin >> n;
    vector<pair<string, string>> vec;
    for (int i = 0; i < n; i++) {
        cin >> country >> surname;
        vec.push_back(make_pair(country, surname));
    }
 
    stable_sort(vec, 0, n - 1);
    string current_country = vec[0].first;
    cout << "=== " << current_country << " ===\n";
    for (int i = 0; i < n; i++) {
        if (vec[i].first != current_country) {
            current_country = vec[i].first;
            cout << "=== " << current_country << " ===\n";
        }
        cout << vec[i].second;
        if (i != n - 1) {
            cout << '\n';
        }
    }
 
    return 0;
}