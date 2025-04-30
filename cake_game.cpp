#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
	int t;
	cin >> t;

	for (int e = 0; e < t; e++) {
		int n;
		cin >> n;
		vector<int> cakes(n);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> cakes[i];
			sum += cakes[i];
		}

		long long p_sum = 0;
		long long mini = LONG_LONG_MAX;
		for (int i = 0; i < n; i++) {
			p_sum += cakes[i];
			if (i > n/2) {
				p_sum -= cakes[i - n/2 - 1];
			}

			if (i >= n/2) {
				mini = min(mini, p_sum);
			}
		}
		cout << mini << " " << sum - mini << endl;
	}
}