#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> a2(n);
    vector<long long> b(n);
    for (long long i = 0; i < n; i++) {
        long long cur;
        cin >> cur;
        a2[i] = cur*(n-i)*(i+1);
    }

    for (long long i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    sort(a2.begin(), a2.end(), greater<long long>());
    sort(b.begin(), b.end());

    long long sum = 0;
    for (long long i = 0; i < n; i++) {
        sum += a2[i]*b[i];
    }

    cout << sum << endl;
}