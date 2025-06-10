#include <bits/stdc++.h>
using namespace std;

void print_matrix(vector<vector<int>> board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
}

void flood_fill(vector<vector<int>>& board, const int& i, const int& j, int& size, int& n, int& color) {
    if (!(i >= 0 && i < n && j >= 0 && j < 10 && board[i][j] == color))
        return;
    size++;
    board[i][j] = -color;
    flood_fill(board, i+1, j, size, n, color);
    flood_fill(board, i-1, j, size, n, color);
    flood_fill(board, i, j+1, size, n, color);
    flood_fill(board, i, j-1, size, n, color);
}

void gravity(vector<vector<int>>& board, int N) {
    for (int j = 0; j < 10; j++) {
        int top = N - 1, bottom = N - 1;
        while (top >= 0) {
            while (top >= 0 && board[top][j] == 0) top--;
            if (top >= 0)
                board[bottom--][j] = board[top--][j];
        }
        while (bottom >= 0) board[bottom--][j] = 0;
    }
}

int main() {
    ifstream inputFile("mooyomooyo.in");
    ofstream outputFile("mooyomooyo.out");
    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening files." << endl;
        return 1;
    }
    auto* cinBuf = cin.rdbuf(inputFile.rdbuf());
    auto* coutBuf = cout.rdbuf(outputFile.rdbuf());

    int n, k;
    cin >> n >> k;
    vector<vector<int>> board(n, vector<int>(10));
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < 10; j++)
            board[i][j] = row[j] - '0';
    }

    bool stop = false;
    while (!stop) {
        stop = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                int color = board[i][j];
                if (color == 0) continue;
                int size = 0;
                flood_fill(board, i, j, size, n, color);
                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < 10; y++) {
                        if (size >= k && board[x][y] == -color) {
                            board[x][y] = 0;
                            stop = false;
                        } else if (size < k && board[x][y] == -color) {
                            board[x][y] = color;
                        }
                    }
                }
            }
        }
        if (!stop) gravity(board, n);
    }

    print_matrix(board, n);

    cin.rdbuf(cinBuf);
    cout.rdbuf(coutBuf);
    return 0;
}
