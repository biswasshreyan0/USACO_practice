#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	ifstream cin ("bcount.in");
	ofstream cout("bcount.out");
	int n, q;
	cin >> n >> q;
	vector<int> cows(n+1);
	vector<int> hol;
	hol.push_back(0);
	vector<int> guern;
	guern.push_back(0);
	vector<int> jers;
	jers.push_back(0);
	for (int i = 1; i <= n; i++) {
		cin >> cows[i];
	}

	for (int i = 1; i <= n; i++) {
		int cur = cows[i];
		if (cur == 1) {
			hol.push_back(hol[i-1] + 1);
			guern.push_back(guern[i-1]);
			jers.push_back(jers[i-1]);
		} else if (cur == 2) {
			guern.push_back(guern[i-1] + 1);
			jers.push_back(jers[i-1]);
			hol.push_back(hol[i-1]);
		} else if (cur == 3) {
			guern.push_back(guern[i-1]);
			hol.push_back(hol[i-1]);
			jers.push_back(jers[i-1] + 1);
		}
	}

	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		cout << hol[b] - hol[a-1] << " " << guern[b]-guern[a-1] << " " << jers[b] - jers[a-1] << endl;
	}
}