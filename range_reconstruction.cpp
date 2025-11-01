#include <bits/stdc++.h>
using namespace std;

bool ok(vector<long long> ans, vector<vector<long long>> difs, long long i, long long n) {
    long long maxx = LLONG_MIN;
    long long minn = LLONG_MAX;

    for (long long j = i; j < n; j++) {
        maxx = max(maxx, ans[j]);
        minn = min(maxx, ans[j]);
        if (maxx - minn != difs[i][j - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    long long n;
    cin >> n;
    //cout << "hello world" << endl;
    vector<vector<long long>> difs(n, vector<long long>(n));
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n - i; j++) {
            cin >> difs[i][j];
            //cout << difs[i][j] << " ";
        }
        //cout << endl;
    }

    vector<long long> ans(n, 0);

    for (long long i = n - 2; i >= 0; i--) {
        ans[i] = ans[i+1] + difs[i][1];
        if (!ok(ans, difs, i, n)) {
            ans[i] = ans[i+1] - difs[i][1];
        }
    }

    for (long long i = 0; i < n-1; i++) {
        cout << ans[i] << " ";
    }
    cout << ans[n-1];
}
