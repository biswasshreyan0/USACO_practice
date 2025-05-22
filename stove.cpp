#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int extra_need = n-k;
    vector<int> visitor(n);
    for (int i = 0; i < n; i++) {
        cin >> visitor[i];
    }

    vector<int> diff(n);
    for (int i = 1; i < n; i++) {
        diff[i] = visitor[i] - visitor[i-1];
    }
    sort(diff.begin(), diff.end());
    int ans = n;
    for (int i = 1; i <= extra_need; i++) {
        ans += diff[i]-1;
    }

    cout << ans << endl;
}