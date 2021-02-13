#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int dp[51];
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	int i;
	for (i = 3; i < 51; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	int buf;
	std::cin >> buf;
	while (buf != 0)
	{
		std::cout << dp[buf] << '\n';
		std::cin >> buf;
	}
	return 0;
}