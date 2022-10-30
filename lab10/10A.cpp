#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
     
    int n, m;
    cin >> n >> m;
 
    vector<int> deg(n, 0);
 
    int b, e;
    for (int i = 0; i < m; i++) {
        cin >> b >> e;
        deg[b - 1]++;
        deg[e - 1]++;
    }
 
    for (int i = 0; i < n; i++) {
        cout << deg[i] << ' ';
    }
 
    return 0;
}