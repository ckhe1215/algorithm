#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string str[50];
int visited[26] = {0};
int n, k;
int res = 0;

void recursion(int alpha, int cnt) {
	if (cnt == k) {
		int tmp = 0;
		for (int i = 0; i < n; i++) {
			int able = 1;
			for (int j = 0; j < str[i].length(); j++) {
				if (!visited[str[i][j] - 'a']) {
					able = 0;
					break;
				}
			}
			if (able)
				tmp++;
		}
		res = max(res, tmp);
		return ;
	}
	for(int i = alpha; i < 26; i++){
		if (!visited[i]){
			visited[i] = 1;
			recursion(i, cnt + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	if (k < 5) {
		cout << 0;
		return 0;
	}
	visited['a' - 'a'] = 1;
	visited['n' - 'a'] = 1;
	visited['t' - 'a'] = 1;
	visited['i' - 'a'] = 1;
	visited['c' - 'a'] = 1;
	k -= 5;

	recursion(0, 0);
	cout << res;
	return 0;
}
