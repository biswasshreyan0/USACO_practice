#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(2005, vector<int>(2005, 0));
    // 0 is water, 1 is fence or visited
    map<char, pair<int, int>> dirs{{'N', make_pair(0, 1)}, {'S', make_pair(0, -1)}, {'E', make_pair(1, 0)}, {'W', make_pair(-1, 0)}};
    matrix[1001][1001] = 1;
    int cur_x = 1001;
    int cur_y = 1001;
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        cur_x += dirs[c].first;
        cur_y += dirs[c].second;
        matrix[cur_x][cur_y] = 1;

        cur_x += dirs[c].first;
        cur_y += dirs[c].second;
        matrix[cur_x][cur_y] = 1;

    }

    // flood fill
    int islands = -1;
    vector<int> dir_x {-1, 1,  0, 0};
    vector<int> dir_y { 0, 0, -1, 1};

    for (int i = 0; i < 2005; i++) {
        for (int j = 0; j < 2005; j++) {
            if (matrix[i][j] == 1) {
                continue;
            }
            queue<pair<int, int>> q;
            islands++;
            q.push(make_pair(i, j));
            matrix[i][j] = 1;
            while (!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int nx = cur.first + dir_x[k];
                    int ny = cur.second + dir_y[k];
                    if (nx >= 0 && nx < 2001 && ny >= 0 && ny < 2001 && matrix[nx][ny] == 0) {
                        matrix[nx][ny] = 1;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
    cout << islands << endl;
}