#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 2147483647;
int dist[20001]; // k부터 인덱스까지 거리
vector<pair<int, int>> arr[20001];

void dijkstra(int start){
	priority_queue<pair<int, int>> pq;
	dist[start] = 0;
	pq.push(make_pair(0, start));
	while(!pq.empty()){
		int nowCost = -pq.top().first; // 꺼낸게 음수일테니까 양수로 바꿈
		int now = pq.top().second;
		pq.pop();
		// dist에 제일 작은 거리를 넣어줄 거임. 이미 dist값이 더 작으면 pass
		if (nowCost > dist[now]) continue;
		for(int i = 0; i < arr[now].size(); i++){
			int nextCost = arr[now][i].second;
			int next = arr[now][i].first;
			if (dist[next] > nowCost + nextCost){
				dist[next] = nowCost + nextCost;
				pq.push(make_pair(-dist[next], next));
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int v, e, k;
	cin >> v >> e >> k;
	for (int i = 1; i <= v; i++){
		dist[i] = INF;
	}
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a].push_back(make_pair(b, c));
	}
	dijkstra(k);
	for(int i = 1; i <= v; i++) {
		if (dist[i] == INF){
			cout << "INF\n";
		} else {
			cout << dist[i] << "\n";
		}
	}
}
