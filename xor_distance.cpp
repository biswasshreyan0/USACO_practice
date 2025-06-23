#include <iostream>
#include <vector>
using namespace std;

bool get_bit(long long a, long long i) {
	return a & (1LL << i);
}

int main() {
	long long t;
	cin >> t;

	while (t--) {
		long long a, b, r;
		cin >> a >> b >> r;

		if (a > b) swap(a, b);

		long long x = 0;
		bool first = true;

		for (long long i = 59; i >= 0; i--) {
			long long a_bit = get_bit(a, i);
			long long b_bit = get_bit(b, i);

			if (a_bit != b_bit) {
				if (first) {
					first = false;
				} else {
					if (!a_bit and (x+(1LL << i)) <= r) {
						x += (1LL << i);
						a ^= (1LL << i);
						b ^= (1LL << i);
					}
				}
			}
		}

		cout << b-a << endl;
	}
}