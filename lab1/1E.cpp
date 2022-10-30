#include <iostream>
#include <vector>
 
using namespace std;
 
//pair (value, citizen_number)
typedef pair<double, int> citizen;
 
int main() {
    freopen("sortland.in", "r", stdin);
    freopen("sortland.out", "w", stdout);
 
    int n;
    double value;
    vector<citizen> vec;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> value;
        vec.push_back(make_pair(value, i));
    }
 
    //sorting vector by value
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (vec[j].first > vec[j + 1].first) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
 
    cout << vec[0].second << ' ';
    cout << vec[n / 2].second << ' ';
    cout << vec[n - 1].second;
 
    return 0;
}