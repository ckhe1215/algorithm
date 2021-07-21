#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<pair<int,int>> jewerly;
	vector<int> bag;
	priority_queue<int> q; // 보석 가격만 넣기

	long long sum = 0;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int m, v;
		cin >> m >> v;
		jewerly.push_back(make_pair(m, v)); //무게, 가격순
	}
	for (int i = 0; i < k; i++) {
		int c;
		cin >> c;
		bag.push_back(c);
	}
	sort(bag.begin(), bag.end());
	sort(jewerly.begin(), jewerly.end());
	int pj = 0;
	for(int i = 0; i < bag.size(); i++) {
		while (pj < n && jewerly[pj].first <= bag[i])
			q.push(jewerly[pj++].second);
		if (!q.empty()) {
			sum += q.top();
			q.pop();
		}
	}
	cout << sum;
}
