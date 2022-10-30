#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int n, m;
    cin >> n >> m;
 
    vector<vector<bool>> field;
    field = vector<vector<bool>>(n, vector<bool>(m));
 
    string s;
    pair<int, int> start, finish;
 
    for (int i = 0; i < n; i++) {
 
        cin >> s;
        for (int j = 0; j < m; j++) {
            switch (s[j]) {
                case '#':
                    field[i][j] = false;
                    break;
                case 'S':
                    start = make_pair(i, j);
                    field[i][j] = true;
                    break;
                case 'T':
                    finish = make_pair(i, j);
                    field[i][j] = true;
                    break;
                default:
                    field[i][j] = true;
            }
        }
    }
 
    vector<vector<bool>> visited;
    visited = vector<vector<bool>>(n, vector<bool>(m, false));
 
    vector<vector<string>> commands;
    commands = vector<vector<string>>(n, vector<string>(m, ""));
 
    queue<pair<int, int>> to_visit;
    to_visit.push(start);
    visited[start.first][start.second] = true;
 
 
    while (!to_visit.empty()) {
        pair<int, int> cur = to_visit.front();
        to_visit.pop();
 
        // U
        if (cur.first > 0 && field[cur.first - 1][cur.second]
            && !visited[cur.first - 1][cur.second]) {
            to_visit.push(make_pair(cur.first - 1, cur.second));
            visited[cur.first - 1][cur.second] = true;
            commands[cur.first - 1][cur.second] = "U";
        }
        // D
        if (cur.first + 1 < n && field[cur.first + 1][cur.second]
            && !visited[cur.first + 1][cur.second]) {
            to_visit.push(make_pair(cur.first + 1, cur.second));
            visited[cur.first + 1][cur.second] = true;
            commands[cur.first + 1][cur.second] = "D";
        }
        // L
        if (cur.second > 0 && field[cur.first][cur.second - 1]
            && !visited[cur.first][cur.second - 1]) {
            to_visit.push(make_pair(cur.first, cur.second - 1));
            visited[cur.first][cur.second - 1] = true;
            commands[cur.first][cur.second - 1] = "L";
        }
        // R
        if (cur.second + 1 < m && field[cur.first][cur.second + 1]
            && !visited[cur.first][cur.second + 1]) {
            to_visit.push(make_pair(cur.first, cur.second + 1));
            visited[cur.first][cur.second + 1] = true;
            commands[cur.first][cur.second + 1] = "R";
        }
    }
 
    if (visited[finish.first][finish.second]) {
        string ans = "";
        pair<int, int> cur = finish;
 
        while (cur != start) {
            ans += commands[cur.first][cur.second];
            if (commands[cur.first][cur.second] == "D") {
                cur.first--;
            } else if (commands[cur.first][cur.second] == "U") {
                cur.first++;
            } else if (commands[cur.first][cur.second] == "L") {
                cur.second++;
            } else if (commands[cur.first][cur.second] == "R") {
                cur.second--;
            }
        }
 
        cout << ans.length() << '\n';
        for (int i = ans.length() - 1; i >= 0; i--) {
            cout << ans[i];
        }
    } else {
        cout << -1;
    }
 
 
    return 0;
}