#include <iostream>

int main()
{
	long long int dp[77];
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i < 77; i++)
		dp[i] = dp[i - 2] + dp[i - 3];
	int buf;
	while (std::cin >> buf)
	{
		if (buf == 1)
			std::cout << "1\n";
		else
			std::cout << dp[buf] + dp[buf - 1] << '\n';
	}
	return 0;
}