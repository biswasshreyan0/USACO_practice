#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, x;
        cin >> n >> x;
        if ((n&x) != x) {
            cout << -1 << endl;
            continue;
        }

        long long m_0 = 0;
        long long m_1 = LLONG_MAX;

        for (int i = 0; i < 61; i++) {
            bool bit_n = (n >> i) & 1LL;
            bool bit_x = (x >> i) & 1LL;

            if (bit_n && !bit_x) {
                long long m_i = ((n >> (i+1)) +1) << (i+1);
                m_0 = max(m_0, m_i);
            }

            if (bit_x) {
                long long m_i = ((n >> (i+1)) +1) << (i+1);
                m_1 = min(m_1, m_i);
            }
        }

        if (m_0 < m_1) {
            cout << max(m_0, n) << endl;
        } else {
            cout << -1 << endl;
        }
    }
}