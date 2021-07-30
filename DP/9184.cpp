#include <iostream>
#include <vector>
using namespace std;

struct nums{
	int a;
	int b;
	int c;
};

vector<nums> list;
int dp[21][21][21] = {0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (1){
		int x, y, z;
		cin >> x >> y >> z;
		if (x == -1 && y == -1 && z == -1) break;
		nums tmp = {x, y, z};
		list.push_back(tmp);
	}
	for (int i = 0; i <= 20; i++) {
		for (int j = 0; j <= 20; j++) {
			for(int k = 0; k <= 20; k++) {
				if (i == 0 || j == 0 || k == 0)
					dp[i][j][k] = 1;
				else if (i < j && j < k)
					dp[i][j][k] = dp[i][j][k - 1] + dp[i][j - 1][k - 1] - dp[i][j - 1][k];
				else
					dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] - dp[i - 1][j - 1][k - 1];
			}
		}
	}
	for(int i = 0; i < list.size(); i++){
		int a, b, c, res;
		a = list[i].a;
		b = list[i].b;
		c = list[i].c;
		cout << "w(" << a << ", " << b << ", " << c << ") = ";
		if (a <= 0 || b <= 0 || c <= 0) {
			res = 1;
		} else if (a > 20 || b > 20 || c > 20) {
			res = dp[20][20][20];
		} else {
			res = dp[a][b][c];
		}
		cout << res << "\n";
	}
}
