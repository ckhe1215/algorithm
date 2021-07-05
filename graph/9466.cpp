#include <iostream>
#include <vector>
using namespace std;

vector<int> student;
vector<int> visited;
vector<int> done;
int ans;

void dfs(int s) {
	visited[s] = 1;
	if (!visited[student[s]])
		dfs(student[s]);
	else if(!done[student[s]]) {
		int start = student[s];
		while (start != s){
			start = student[start];
			ans++;
		}
		ans++;
	}
	done[s] = 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		ans = 0;
		student.clear();
		visited.clear();
		done.clear();
		student.push_back(0);
		for(int j = 0; j <= n; j++){
			visited.push_back(0);
			done.push_back(0);
		}
		for (int j = 0; j < n; j++) {
			int s;
			cin >> s;
			student.push_back(s);
		}
		for (int j = 1; j <= n; j++) {
			if (!visited[j]){
				dfs(j);
			}
		}
		cout << n - ans << "\n";
	}

	return 0;
}
