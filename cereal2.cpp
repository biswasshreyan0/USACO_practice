#include <bits/stdc++.h>
using namespace std;

struct edge {
    int cow_id;
    int to;
    bool first; //true if points to first preference and vice versa
};

const int max_m = 1e5;
int n, m;
vector<vector<edge>> adj_list(max_m+1);

vector<bool> visited_cycle(max_m+1);
vector<bool> normal_visited(max_m+1);
vector<bool> cow_to_cereal(max_m+1); // T if cow gets a cereal, F if not

int start_cereal;
int lucky_cow;
int starve = 0;
queue<int> ans;

void reset() {
    // visited_cycle.clear();
    normal_visited.clear();
}

void find_cycle (int cur_cereal, int parent = -1) {
    visited_cycle[cur_cereal] = true;
    for (edge e : adj_list[cur_cereal]) {
        if (visited_cycle[e.to]) {
            if (e.to != parent and start_cereal == -1) {
                start_cereal = e.first ? e.to : cur_cereal;
                lucky_cow = e.cow_id;
                ans.push(lucky_cow);
                cow_to_cereal[lucky_cow] = true;
            }
        } else {
            find_cycle(e.to, cur_cereal);
        }
    }
}

void dfs_build_order (int cur_cereal) {
    normal_visited[cur_cereal] = true;
    for (edge e : adj_list[cur_cereal]) {
        if (normal_visited[e.to] != true and e.to != lucky_cow) {
            ans.push(e.to);
            cow_to_cereal[e.to] = true;
            dfs_build_order(e.to);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(edge{i, b, true});
        adj_list[b].push_back(edge{i, a, false});
    }

    for (int cur_cereal = 1; cur_cereal <= m; cur_cereal++) {
        start_cereal = -1;
        lucky_cow = -1;
        reset();
        if (!visited_cycle[cur_cereal]) {
            find_cycle(cur_cereal);
            if (start_cereal > 0) {
                dfs_build_order(start_cereal);
            } else {
                dfs_build_order(cur_cereal);
            }
        }
    }

    for (int cow = 1; cow <= n; cow++) {
        if (!cow_to_cereal[cow]) {
            starve++;
            ans.push(cow);
        }
    }

    cout << starve << endl;
    while (!ans.empty()) {
        cout << ans.front() << endl;
        ans.pop();
    }

}