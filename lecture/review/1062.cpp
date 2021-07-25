#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int visited[26] = {0};
string words[51];
int res = 0;

void recursive(int a, int cnt) {
	if (cnt == k) {
		int tmp = 0;
		for (int i = 0; i < n; i++){
			int able = 1;
			for (int j = 0; j < words[i].length(); j++) {
				if (!visited[words[i][j] - 'a']) {
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
	for (int i = a; i < 26; i++) {
		if(!visited[i]){
			visited[i] = 1;
			recursive(i, cnt + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> words[i];
	}
	if (k < 5) {
		cout << "0";
		return 0;
	}
	k -= 5;
	visited['a' - 'a'] = 1;
	visited['n' - 'a'] = 1;
	visited['t' - 'a'] = 1;
	visited['i' - 'a'] = 1;
	visited['c' - 'a'] = 1;
	recursive(0, 0);
	cout << res;
	return 0;
}
