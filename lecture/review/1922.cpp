#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
	int first;
	int second;
	int cost;
};

vector<node> arr;
vector<int> parent;

int compare(const node &one, const node &two){
	return one.cost < two.cost;
}

int find(int a){
	if (parent[a] == a) return a;
	return find(parent[a]);
}

void f_union(int a, int b){
	int pa = parent[a];
	int pb = parent[b];
	parent[pa] = pb;
}

int main() {
	int sum = 0;
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		node tmp = {a, b, c};
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end(), compare);
	for(int i = 0; i <= n; i++){
		parent.push_back(i);
	}
	for(int i = 0;  i < arr.size(); i++) {
		if (find(arr[i].first) == find(arr[i].second)) {
			continue;
		} else {
			f_union(arr[i].first, arr[i].second); // 연결안되어있으면 연결하기
			sum += arr[i].cost;
		}
	}
	cout << sum;
}
