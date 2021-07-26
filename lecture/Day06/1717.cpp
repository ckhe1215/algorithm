#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int find(int a) {
	if(parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

void f_union(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	parent[pa] = pb;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		parent.push_back(i);
	}
	for (int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0) {
			f_union(b, c);
		} else {
			if (find(b) == find(c)){
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}
}
