#include <iostream>
#include <iomanip>
#include <string.h>

long long int dp[10001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	memset(dp, 0, 10001);
	dp[0] = 1;
	for (long long int i = 1; i < 10001; i++)
	{
		//std::cout << " : " << dp[i - 1] << '\n' << i;
		long long int buf = dp[i - 1] * i;
		while (buf % 10 == 0)
			buf /= 10;
		dp[i] = buf % 1000000;
	}
	int buf;
	while (std::cin >> buf)
		std::cout << std::setw(5) << buf << " -> " << dp[buf] % 10 << '\n';
	return 0;
}