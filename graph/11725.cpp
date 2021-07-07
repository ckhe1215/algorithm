#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[100001]; // graph[i] -> i와 연결된 노드들의 배열
int visited[100001]; // 각 노드 방문여부
int parents[100001]; // 각 노드의 부모노드를 저장

void dfs(int root) {
	visited[root] = 1;
	for(int i = 0; i < graph[root].size(); i++){
		// root와 연결된 것 중 방문하지 않은 것
		if (!visited[graph[root][i]]){
			parents[graph[root][i]] = root;
			dfs(graph[root][i]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		// 입력 순서가 부모-자식 순이 아니기 때문에 양방향 그래프를 이용
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1); //루트인 1부터 탐색

	for(int i = 2; i <= n; i++)
		cout << parents[i] << "\n";
}
