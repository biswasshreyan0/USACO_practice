#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cards(n*2);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cards[a] = 1;
    }
    
    vector<int> a(n); // elsie cards
    vector<int> b(n); // bessie cards

    for (int i = 0; i < 2*n; i++) {
        if (cards[i] == 1) {
            a.push_back(i);
        } else {
            b.push_back(i);
        }
    }

    int j, k = 0;
    int ans = 0;

    while (j < n and k < n) {
        while (k < n and a[j] > b[k]) {
            k++;
        }

        if (k < n and a[j] < b[k]) {
            k++;
            ans++;
        }
        j++;
    }

    cout << ans << endl;
}