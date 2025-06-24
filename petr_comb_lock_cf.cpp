#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> rots(n);

    for (int i = 0; i < n; i++) {
        cin >> rots[i];
    }


    for (int mask = 0; mask < (1 << n); mask ++) {
        int total = 0;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                total -= rots[i];
            } else {
                total += rots[i];
            }
        }

        if (total % 360 == 0) {
            cout << "yes" << endl;
            return 0;
        }
    }
    cout << "no" << endl;
}