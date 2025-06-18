#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, a, b;
    cin >> n >> a >> b;
    map<long long, long long> freq; // key: id, val: # of cows with that id

    for (long long i = 0; i < n; i++) {
        long long di, ni;
        cin >> di >> ni;
        freq[ni] = di;
    }

    long long ans = 0;
    for (auto x : freq) {
        long long complement1 = a - x.first;
        long long complement2 = b - x.first;

        long long no_cows = x.second;
        if (complement2 > x.first and complement2 >= 0) {
            long long diff = min(no_cows, freq[complement2]);
            ans += diff;
            no_cows -= diff;
            freq[complement2] -= diff;
        }

        if (complement1 > x.first and complement1 >= 0) {
            long long diff = min(no_cows, freq[complement1]);
            ans += diff;
            no_cows -= diff;
            freq[complement1] -= diff;
        }
        freq[x.first] = no_cows;
    }

    for (auto x : freq) {
        if (x.first*2 == a or x.first*2 == b) {
            ans += x.second/2;
        }
    }

    cout << ans << endl;
}

int main() {
    solve();
}