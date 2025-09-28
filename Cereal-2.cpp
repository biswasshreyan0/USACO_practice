#include <iostream>
using namespace std;

struct edge {
    int to;
    int cow_no;
    bool is_first_pref; // true if points to first pref, false if not
};

vector<int> eaten_cows(1e5);
int eating_cows = 0;
void find_cycle (int n, int& i, vector<vector<edge>>& adj, int& lucky_node, int& start_cereal, vector<bool>& visited_cycle) {
    visited_cycle[i] = true;

    for (int j = 1;  j <= n; j++) {
       if (visited_cycle[adj[i][j].to] == true) {
          lucky_node = adj[i][j].to;
          eaten_cows[i] = 1;
          start_cereal = lucky_node;
       }
    }

}

void dfs (int& cur_node, vector<bool>& visited, vector<vector<edge>>& adj) {
    visited[cur_node] = true;
    for (edge i : adj[cur_node]) {
       if (!visited[i.to]) {
          eating_cows++;
          eaten_cows[i.to] = 1;
          dfs(i.to, visited, adj);
       }
    }
}

vector<int> ans(1e5);
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<edge>> adj(n);

    for (int i = 0; i < n; i++) {
       int a, b;
       cin >> a >> b;
       adj[a].push_back(edge{b, i+1, true});
       adj[b].push_back(edge{a, i+1, false});
    }

    vector<bool> visited_cycle(n, false);
    vector<bool> visited(n, false);

    for (int i = 1; i <= n; i++) {
       int lucky_node = -1;
       int start_cereal = -1;
       if (!visited_cycle[i]) {
          find_cycle(n, i, adj, lucky_node, start_cereal, visited_cycle);

          if (lucky_node != -1) {
             dfs(lucky_node, visited, adj);
          } else {
             dfs(i, visited, adj);
          }
       }
    }

    cout << eating_cows << endl;
    for (int i = 0; i < n; i++) {
       cout << eaten_cows[i] << endl;
    }
}
