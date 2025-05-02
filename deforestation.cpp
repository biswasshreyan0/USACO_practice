#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> order_set;

int main() {
    int t;
    cin >> t;
    for (int p = 0; p < t; p++) {
        int n, k;
        cin >> n >> k;
        vector<int> tree_loc(n);
        for (int i = 0; i < n; i++) {
            cin >> tree_loc[i];
        }
        multiset<int> unvisited;
        order_set visited;
        sort(tree_loc.begin(), tree_loc.end());
        vector<pair<int, pair<int, int>>> rest(k);
        for (int i = 0; i < k; i++) {
            int start, end, no;
            cin >> start >> end >> no;
            rest[i] = make_pair(end, make_pair(start, no));
        }

        sort(rest.begin(), rest.end());
        int pos = 1;
        for (int i = 0; i < k; i++) {
            while (pos <= n and tree_loc[pos] < rest[i].first) {
                unvisited.insert(tree_loc[pos]);
                pos++;
            }

            int cnt = visited.size() - visited.order_of_key(rest[i].second.first);

            while (cnt < rest[i].second.second) {
                int cur = *unvisited.rbegin();
                unvisited.erase(unvisited.lower_bound(cur));
                visited.insert(cur);
                cnt++;
            }
        }
        cout << unvisited.size() + n - pos + 1 << endl;
    }
}