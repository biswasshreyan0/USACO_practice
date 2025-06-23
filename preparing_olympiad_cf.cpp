#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, r, x;
    cin >> n >> l >> r >> x;

    vector<int> diffs(n);
    for (int i = 0; i < n; i++) {
        cin >> diffs[i];
    }

    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        int sum = 0;
        int minn = INT_MAX;
        int maxx = -1;
        int no_of_bits = 0;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                int cur = diffs[i];
                sum += cur;
                no_of_bits++;
                minn = min(minn, cur);
                maxx = max(maxx, cur);
            }
        }

        if (no_of_bits >= 2 and l <= sum and r >= sum and (maxx-minn) >= x) {
            ans++;
        }
    }
    cout << ans << endl;
}
