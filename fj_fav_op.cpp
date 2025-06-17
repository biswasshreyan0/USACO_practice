#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        vector<long long> a(n);

        for (long long i = 0; i < n; i++) {
            cin >> a[i];
            a[i] = a[i] % m;
        }

        sort(a.begin(), a.end());

        vector<long long> b(2*n);
        for (long long i = 0; i < n; i++) {
            b[i] = a[i];
            b[i+n] = a[i] + m;
        }

        vector<long long> ps(2*n+1, 0);
        for (long long i = 0; i < 2*n; i++) {
            ps[i+1] = ps[i] + b[i];
        }

        long long k = n/2;
        long long ans = LLONG_MAX;

        for (long long i = 0; i < n; i++) {
            long long small = ps[i+k] - ps[i];
            long long big = ps[i+n] - ps[i+n-k];
            ans = min(ans, big-small);
        }
        cout << ans << endl;
    }

}