#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool check(int n, int m, int c, vector<int> cows, int limit) {
	int buses = 0;
	int first_element = cows[0];
	int first_index = 0;

	for (int i = 0; i < n; i++) {
		if (i - first_element > limit or first_index > m) {
			buses++;
			first_element = cows[i];
			first_index = i;
		}
	}
	return buses < m;
}

int bin_search(int n, int m, int c, vector<int> cows, int lo, int hi) {
	if (lo == hi) return lo;
	if (check(n, m, c, cows, lo)) return lo;
	int mid = (lo + hi) / 2;
	if (check(n, m, c, cows, mid)) {
		bin_search(n, m, c, cows, lo, mid);
	} else {
		bin_search(n, m, c, cows, mid, hi);
	}
}

int main() {
	int n, m, c;
	cin >> n >> m >> c;
	vector<int> cows;
	for (int i = 0; i < n; i++) {
		cin >> cows[i];
	}
	sort(cows.begin(), cows.end());
	int lo = 1, hi = cows[n-1];
	while (lo < hi) {
		if (check(n, m, c, cows, lo)) {
			cout << lo << endl;
			break;
		}

		int mid = (lo + hi) / 2;
		if (check(n, m, c, cows, mid)) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
}