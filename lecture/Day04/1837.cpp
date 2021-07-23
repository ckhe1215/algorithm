#include <iostream>
#include <vector>
using namespace std;

int eratos[1000001] = {0};
vector<int> prime;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string pw;
	int k;
	cin >> pw;
	cin >> k;
	eratos[0] = 1;
	eratos[1] = 1;
	for (int i = 2; i < k; i++) {
		if (eratos[i] == 0) {
			prime.push_back(i);
			for (int j = i * 2; j < k; j += i) {
				eratos[j] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < prime.size(); i++) {
		int ret = 0;
		for(int j = 0; j < pw.length(); j++) {
			ret = (ret * 10 + (pw[j] - '0')) % prime[i];
		}
		if (ret == 0) {
			ans = prime[i];
			break;
		}
	}
	if (ans == 0) {
		cout << "GOOD";
	} else {
		cout << "BAD " << ans;
	}
}
