#include <iostream>
#include <vector>
using namespace std;

int arr[1000000] = {0};
int LtoR[1000000] = {0};
int RtoL[1000000]  = {0};

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		int m;
		cin >> m;
		arr[i] = m;
	}
	LtoR[0] = arr[0];
	for(int i = 1; i < n; i++) {
		LtoR[i] = gcd(LtoR[i - 1], arr[i]);
	}
	RtoL[n - 1] = arr[n - 1];
	for(int i = n - 2; i >= 0; i--) {
		RtoL[i] = gcd(RtoL[i + 1], arr[i]);
	}
	int max = 0;
	int kRes = 0;
	for (int i = 0; i < n; i++){
		int k = arr[i];
		int result;
		if (i == 0)
			result = RtoL[1];
		else if (i == n - 1)
			result = LtoR[n - 2];
		else
			result = gcd(LtoR[i - 1], RtoL[i + 1]);
		if (max < result) {
			max = result;
			kRes = arr[i];
		}
	}
	if (kRes % max == 0)
		cout << -1;
	else
		cout << max << " " << kRes;
}
