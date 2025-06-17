#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int z = 0; z < t; z++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (a > c or b > d or (gcd(a, b) != gcd(c, d))) {
            cout << -1 << endl;
            continue;
        }

        int A = c;
        int B = d;
        long long ops = 0;
        bool possible = true;
        while (A != a and B != b) {
            if (A < a or B < b) {
                possible = false;
                break;
            } else if (A < B) {
                swap(A, B);
                swap(a, b);
            } else if (A > a) {
                int amount = (A-a)/b;
                if (amount < 1) {
                    amount = 1;
                    A -= amount;
                } else {
                    A -= amount;
                    ops += amount;
                }
            } else {
                int amount = (B-b)/a;
                if (amount < 1) {
                    amount = 1;
                    B -= amount;
                } else {
                    B -= amount;
                    ops += amount;
                }
            }
        }
        cout << ops << endl;
    }
}