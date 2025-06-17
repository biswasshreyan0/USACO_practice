#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    for (long long z = 0; z < t; z++) { // iterate over test cases
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        vector<pair<long long,long long>> b; // pair of <element, index>
        long long suf_max = -1;
        
        long long cur_index = 0;
        for (long long i = n-1; i >= 0; i--) {
            if (a[i] >= suf_max) {
                b.push_back(make_pair(a[i], i));
                suf_max = a[i];        
            }
        }
        /*
        for (auto i : b) {
            cout << i.first << " ";
        }
        cout << endl;
        */
        reverse(b.begin(), b.end());

        b.insert(b.begin(), make_pair(n+1, -1));
        b.push_back(make_pair(-1, n));

        for (long long i = 1; i < n-1; i++) {
            vector<pair<long long, long long>> add;
            bool cont = true;
            for (long long j = b[i+1].second-1; j > b[i-1].second; j--) {
                
                if (j == b[i].second) continue;
                if (a[j] >= b[i+1].first) {
                    add.push_back(make_pair(a[j], j));
                    cont = false;
                }

            }

            if (!cont) {
                //cout << "add elements" << endl;
                //cout << "add size: " << add.size() << endl;
                /*
                for (auto k : add) {
                    cout << k.first << " ";
                }
                
                cout << endl;
                */
                reverse(add.begin(), add.end());
                b.insert(b.begin()+i+1, add.begin(), add.end());
                break;
            }
            
        }

        for (long long i = 1; i < b.size()-2; i++) {
            cout << b[i].first << " ";
        }
        if (b.size() > 0) {
            cout << b[b.size()-2].first << endl;
        }
    }

}