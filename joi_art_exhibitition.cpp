#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<pair<long long, long long>> art(n+1);
    for (long long i = 1; i <= n; i++) {
        cin >> art[i].first >> art[i].second;
    }
    sort(art.begin(), art.end()); // sort on the size of the arts
    vector<long long> pref_val(n+1, 0);
    vector<long long> size(n+1);
    for (long long i = 1; i <= n; i++) {
        size[i] = art[i].first;
        pref_val[i] = pref_val[i-1] + art[i].second;
    }

    long long ans = LLONG_MIN;
    long long minn = LLONG_MAX;

    for (long long i = 1; i <= n; i++) {
        minn = min(minn, pref_val[i-1] - size[i]);
        ans = max(ans, pref_val[i] - size[i] - minn);
    }
    
    cout << ans << endl;
}