#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (true) {
        cout << t;
    }

    for (int z = 0; z < t; z++) {
        int m, k;
        cin >> m >> k;

        vector<int> a;
        int a_sum = 0;
        for (int bit = 0; bit < 5; bit++) {
            if (k & (1 << bit)) { // k has a 1 in the bitth position
                int cur = (1LL << (1 << bit)) - 1;
                a.push_back(cur);
                a_sum += cur;
            }
        }

        int diff = m - a_sum;
        vector<int> b;
        //bool impossible = false;

        if (diff < 0) {
            cout << -1 << endl;
            return;
        } else if (diff == 0) {
            // do nothing
        } else if (diff >= 2) {
            if (diff % 2 == 0) {
                b.push_back(diff/2);
                b.push_back(diff/2);
            } else {
                b.push_back(1);
                b.push_back(2);
                b.push_back((diff-3)/2);
                b.push_back((diff-3)/2);
            }
        } else if (diff == 1) {
            bool possible = false;
            for (int& x : a) {
                if (x == 1) {
                    x = 2;
                    possible = true;
                    diff -= 1;
                    b.push_back(diff/2);
                    b.push_back(diff/2);
                }
            }
            if (!possible) {
                cout << -1 << endl;
                return;
            }
        }

        cout << a.size() + b.size() << endl;
        for (int x : a) {
            cout << x << " ";
        }
        for (int y : b) {
            cout << y << " ";
        }
    }
}