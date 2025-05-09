#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> ki = {-2, 2, -1, 1, -2, 2, -1, 1};
vector<int> kj = {1, -1, 2, -2, -1, 1, -2, 2};

const int N = 8;

bool inside(int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < N;
}

bool handle_pawn(vector<vector<char>> &board, int i, int j) {
    int nx1 = i - 1, ny1 = j - 1, nx2 = i - 1, ny2 = j + 1;
    if (inside(nx1, ny1)) {
        if (board[nx1][ny1] == 'q') {
            return true;
        }
    } else if (inside(nx2, ny2)) {
        if (board[nx2][ny2] == 'q') {
            return true;
        }
    }
    return false;
}

bool process_row_or_column_or_diagonal(vector<vector<char>> &board, int i, int j, pair<int, int> dir, char cur_piece) {
    while (inside(i, j)) {
        if (board[i][j] != '.' and board[i][j] != 'q' and board[i][j] != cur_piece) {
            break;
        }

        if (board[i][j] == 'q') {
            return true;
        }

        i += dir.first;
        j += dir.second;
    }
    return false;
}


bool handle_rook(vector<vector<char>>& board, int i, int j) {
	vector<pair<int, int>> dirs = {make_pair(0, 1), make_pair(1, 0), make_pair(-1, 0), make_pair(0, -1)};
    // check whole row to see if attacks queen
	for (auto dir : dirs) {
		if (process_row_or_column_or_diagonal(board, i, j, dir, 'R'))
			return true;
	}

	return false;
}

bool handle_bishop(vector<vector<char>>& board, int i, int j) {
	vector<pair<int, int>> dirs = {make_pair(1, 1), make_pair(-1, 1), make_pair(-1, -1), make_pair(1, -1)};
	// check whole row to see if attacks queen
	for (auto dir : dirs) {
		if (process_row_or_column_or_diagonal(board, i, j, dir, 'B'))
			return true;
	}
	return false;
}

bool handle_queen(vector<vector<char>>& board, int i, int j) {
    if (handle_rook(board, i, j) or handle_pawn(board, i, j)) {
        return true;
    }
    return false;
}

bool handle_knight(vector<vector<char>>& board, int i, int j) {
    int init_i = i, init_j = j;
    for (int k = 0; k < 8; k++) {
        int ni = i + ki[k];
        int nj = j + kj[k];
        if (inside(ni, nj) and board[ni][nj] == 'q') {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        vector<vector<char>> board(N, vector<char> (N));
        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < N; j++) {
                board[i][j] = s[j];
            }
        }
		/*
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        */
        bool attacked = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                switch (board[i][j]) {
	                case 'P':
                		if (handle_pawn(board, i, j)) {
                			attacked = true;
                		}
                		break;
                	case 'N':
                		if (handle_knight(board, i, j)) {
                			attacked = true;
                		}
                		break;
                	case 'Q':
                		if (handle_queen(board, i, j)) {
                			attacked = true;
                		}
                		break;
                	case 'R':
                		if (handle_rook(board, i, j)) {
                			attacked = true;
                		}
                		break;
                	case 'B':
                		if (handle_bishop(board, i, j)) {
                			attacked = true;
                		}
                		break;
                	default:
                		continue;
                }

                if (attacked) break;
            }
            if (attacked) break;
        }

        if (!attacked) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}