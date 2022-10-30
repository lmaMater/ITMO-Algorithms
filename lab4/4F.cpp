#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    freopen("garland.in", "r", stdin);
    freopen("garland.out", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    vector<double> h;
 
    cin >> n;
    h.resize(n);
 
    cin >> h[0];
    double left = 0, right = h[0];
 
    while (right - left > 1e-6) {
        bool ok = true;
        h[1] = (left + right) / 2;
 
        for (int i = 2; i < n; i++) {
            h[i] = 2 * (h[i - 1] + 1) - h[i - 2];
            if (h[i] < 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            right = h[1];
        } else {
            left = h[1];
        }
    }
    cout.precision(2);
    cout << fixed << h.back();
 
 
    return 0;
}