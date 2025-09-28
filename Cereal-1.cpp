#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("cereal.in");
    ofstream fout("cereal.out");
    int n, m;
    fin >> n >> m;
    vector<pair<int, int>> preferences(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        fin >> a >> b;
        preferences[i].first = a-1;
        preferences[i].second = b-1;
    }

    vector<int> cereals(m, -1); // for a cereal, which cow is eating it
    vector<int> cows(n, -1); // for a cow, which cereal it is eating
    cows[n-1] = preferences[n-1].first;
    int counter = 1;
    vector<int> counters(n);
    counters[n-1] = 1;

    for (int i = n-2; i >= 0; i--) {
        cows[i] = preferences[i].first;
        counter++;
        // cereals[preferences[cows[i]].first] = i;
        int removed_cow = 0;
        int cur_cow = i;
        while (true) {
            if (cereals[preferences[cur_cow].first] != -1) {
                removed_cow = cereals[preferences[cur_cow].first];
                cereals[preferences[cur_cow].first] = cur_cow;
                if (preferences[removed_cow].second == preferences[cur_cow].first) {
                    counter--;
                    break;
                } else if (cereals[preferences[removed_cow].second] < removed_cow) {
                    counter--;
                    break;
                } else if (cereals[preferences[removed_cow].second] > removed_cow) {
                    cows[removed_cow] = preferences[removed_cow].second;
                    cur_cow = removed_cow;
                }
            } else {
                cereals[preferences[cur_cow].first] = i;
                break;
            }
        }
        counters[i] = counter;
    }

    for (int i = 0; i < n; i++) {
        fout << counters[i] << endl;
    }
}
