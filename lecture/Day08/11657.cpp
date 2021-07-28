#include <iostream>
#include <vector>
using namespace std;

struct bus{
	int start;
	int end;
	int time;
};

vector<bus> list;
long long dist[501] = {0}; // 1에서 N번 도시로 가는데 걸리는 (최소)시간
const int INF = 2147483647;
bool flag = false;

int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		bus tmp = {a, b, c};
		list.push_back(tmp);
	}
	for (int i = 2; i <= n; i++){
		dist[i] = INF;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < list.size(); j++){
			int s = list[j].start;
			int e = list[j].end;
			int t = list[j].time;
			if (dist[s] == INF) continue;
			dist[e] = min(dist[e], dist[s] +  t);
		}
	}
	for (int j = 0; j < list.size(); j++){
		int s = list[j].start;
		int e = list[j].end;
		int t = list[j].time;
		if (dist[s] == INF) continue;
		if (dist[e] > dist[s] + t){
			flag = true;
			break;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (flag){
			cout << "-1";
			break;
		} else if (dist[i] == INF) {
			cout << "-1\n";
		}
		else
			cout << dist[i] << '\n';
	}
}
