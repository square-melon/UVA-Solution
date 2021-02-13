#include <iostream>
#include <algorithm>
#include <vector>

void Perm(int a, int b);
std::vector<std::vector<int>> h;
int** dp;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int ma;
	int T, R, C;
	std::string name;
	std::cin >> T;
	while (T--) {
		h.clear();
		std::cin >> name >> R >> C;
		std::vector<int> buf;
		for (int i = 0; i < R; i++){
			for (int j = 0; j < C; j++) {
				int f;
				std::cin >> f;
				buf.push_back(f);
			}
			h.push_back(buf);
			buf.clear();
		}
		dp = new int* [R];
		for (int i = 0; i < R; i++)
			dp[i] = new int[C];
		Perm(0, 0);
		ma = 0;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++)
				ma = std::max(ma, dp[i][j]);
		}
		std::cout << name << ": " << ma << '\n';
		for (int i = 0; i < R; i++)
			delete[] dp[i];
		delete[] dp;
	}
	return 0;
}

void Perm(int a, int b) {
	if (a != 0)
		return;
}