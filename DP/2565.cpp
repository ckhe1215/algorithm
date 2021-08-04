#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> list;
int dp[101] = {0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	list.push_back(make_pair(0, 0));
	for(int i = 1; i <= n; i++){
		int a, b;
		cin >> a >> b;
		list.push_back(make_pair(a, b));
	}
	sort(list.begin(), list.end());
	dp[1] = 1;
	for(int i = 2; i <= n; i++) {
		int max = 0;
		for(int j = 1; j < i; j++) {
			if (list[j].second < list[i].second && dp[j] > max)
				max = dp[j];
		}
		dp[i] = max + 1;
	}
	int res = 0;
	for(int i = 1; i <= n; i++){
		if (res < dp[i])
			res = dp[i];
	}
	cout << n - res;
}
