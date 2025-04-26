#include <bits/stdc++.h>
using namespace std;

bool angry_cow_check(int n, int k, vector<int>& hay, int r) {
    int i = 0;
    int cows = 0;
    while (i < n) {
        cows++;
        int coverage = hay[i] + 2*r;
        while (i < n && hay[i] <= coverage) {
            i++;
        }
    }
    return cows <= k;
}

void solve_angry_cows(int n, int k, vector<int>& hay) {
    int start = 1;
    int end = hay[hay.size() - 1] - hay[0];

    while (start < end) {
        int mid = (start + end) / 2;
        cout << "mid = " << mid << endl;
        bool possible = angry_cow_check(n, k, hay, mid);
        if (possible) {
            end = mid;
        } else {
            start = mid+1;
        }
    }
    cout << end << endl;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> hay(n);
    for (int i = 0; i < n; i++) {
        cin >> hay[i];
    }

    sort(hay.begin(), hay.end());
    solve_angry_cows(n, k,hay);
}