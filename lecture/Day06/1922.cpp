#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	int first;
	int second;
	int cost;
};

vector<node> edge;
int parent[1001];

int compare(const node &one, const node &two){
	return one.cost < two.cost;
}

int find(int a){
	if (parent[a] == a) return a;
	return find(parent[a]);
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

	int sum = 0;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		node tmp = {a, b, c};
		edge.push_back(tmp);
	}
	sort(edge.begin(), edge.end(), compare);
	for(int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for(int i = 0; i < edge.size(); i++){
		if (edge[i].first == edge[i].second) continue;
		if (find(edge[i].first) != find(edge[i].second)) {
			f_union(edge[i].first, edge[i].second);
			sum += edge[i].cost;
		}
	}
	cout << sum;
}
