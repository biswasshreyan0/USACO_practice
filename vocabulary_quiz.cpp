#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> adj_list;
vector<long long> rep;
vector<long long> ans;
vector<long long> pos;
long long no_of_leaves;

void find_leaves(long long cur) {
    if (adj_list[cur].empty()) {
        no_of_leaves++;
        return;
    } else {
        for (long long i : adj_list[cur]) {
            find_leaves(i);
        }
    }
}

void dfs_2(long long cur, long long depth) {
    if (adj_list[cur].empty()) {
        rep[cur] = cur;
        return;
    }

    for (long long a : adj_list[cur]) {
        dfs_2(a, depth+1);
    }
    
    
    vector<pair<long long, long long>> vec;
    for (long long a : adj_list[cur]) {
        vec.push_back(make_pair(pos[a], rep[a]));
    }

    sort(vec.begin(), vec.end());
    for (long long i = 0; i < vec.size()-1; i++) {
        ans[vec[i].second] = depth+1;
    }
    
    rep[cur] = vec[vec.size()-1].second;
    
}

int main() {
    long long n;
    cin >> n;
    adj_list.assign(n+1, vector<long long>());

    for (long long i = 1; i <= n; i++) {
        long long a;
        cin >> a;
        adj_list[a].push_back(i);
    }
    /*
    for (long long i = 0; i < n; i++) {
        cout << i << ": ";
        for (long long j = 0; j < adj_list[i].size(); j++) {
            cout << adj_list[i][j] << " ";
        }
        cout << "\n";
    }
    */
    
    find_leaves(0);
    
    // cout << "no of leaves = " << no_of_leaves << endl;
    pos.assign(no_of_leaves, 0);
    rep.assign(n+1, 0);
    ans.assign(n+1, 0);
    vector<long long> order;
    for (long long i = 0; i < no_of_leaves; i++) {
        long long a;
        cin >> a;
        pos[a] = i;
        order.push_back(a);
    }
    
    dfs_2(0, 0);
    
    for (long long i = 0; i < order.size(); i++) {
        cout << ans[order[i]] << endl;
    }
    
}