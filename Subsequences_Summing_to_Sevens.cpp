#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cows(n);
    int dif_sum = 0;
    vector<int> dif_vec(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i];
        dif_sum += cows[i];
        dif_vec[i] = dif_sum;
    }
    vector<int> final_mod_7(n);
    for (int i = 0; i < n; i++) {
        final_mod_7[i] = dif_vec[i]%7;
    }
    vector<int> first(7, INT_MAX);
    vector<int> last(7, -1);
    for (int i = 0; i < n; i++) {
        int cur_mod = final_mod_7[i];
        first[cur_mod] = min(i, first[cur_mod]);
        last[cur_mod] = max(i, last[cur_mod]);
    }

    int result = -1;
    for (int i = 0; i < 7; i++) {
        result = max(result, last[i] - first[i]);
    }
    cout << result << endl;
}