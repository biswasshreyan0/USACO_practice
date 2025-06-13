#include <bits/stdc++.h>

using namespace std;

int main() {
	long long t;
	cin >> t;

	for (long long z = 0; z < t; z++) {
		long long m, k;
		cin >> m >> k;

		vector<long long> a;
		long long a_sum = 0;
		for (long long bit = 0; bit < 5; bit++) {
			if (k & (1 << bit)) { // k has a 1 in the bitth position
				long long cur = (1LL << (1 << bit)) - 1;
				a.push_back(cur);
				a_sum += cur;
			}
		}

		long long diff = m - a_sum;
		// cout << "for " << z << " test case, diff = " << diff << endl;
		vector<long long> b;
		//bool impossible = false;

		if (diff < 0) {
			cout << -1 << endl;
			continue;
		} else if (diff == 0) {
			// do nothing
		} else if (diff >= 2) {
			if (diff % 2 == 0) {
				b.push_back(diff/2);
				b.push_back(diff/2);
			} else {
				b.push_back(1);
				b.push_back(2);
				b.push_back((diff-3)/2);
				b.push_back((diff-3)/2);
			}

		} else if (diff == 1) {
			bool possible = false;
			for (long long& x : a) {
				if (x == 1) {
					x = 2;
					possible = true;
					diff -= 1;

					b.push_back(diff/2);
					b.push_back(diff/2);
					break;
				}
			}
			if (!possible) {
				cout << -1 << endl;
				continue;
			}
		}

		cout << a.size() + b.size() << endl;
		for (long long x : a) {
			cout << x << " ";
		}
		for (long long y : b) {
			cout << y << " ";
		}
		cout << endl;
	}
}
