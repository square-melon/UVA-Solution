#include <iostream>
#include <iomanip>
#define MAX 501
#define MAX2 1005

// Maximum : 10^6
int nums[MAX2][MAX];
int sum[1005];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	for (int i = 0; i < MAX2; i++)
	{
		for (int j = 0; j < MAX; j++)
			nums[i][j] = 0;
	}
	nums[0][0] = 1;
	sum[0] = 1;
	for (int i = 1; i < MAX2; i++)
	{
		sum[i] = 0;
		int j;
		for (j = MAX - 1; j >= 0; j--)
		{
			if (nums[i - 1][j] != 0)
				break;
		}
		for (; j >= 0; j--)
			nums[i][j] = nums[i - 1][j] * i;
		for (j = 0; j < MAX - 1; j++)
		{
			if (nums[i][j] >= 1000000)
			{
				nums[i][j + 1] += nums[i][j] / 1000000;
				nums[i][j] %= 1000000;
			}
		}
		for (j = 0; j < MAX - 1; j++)
		{
			int cur = nums[i][j];
			while (cur != 0)
			{
				sum[i] += cur % 10;
				cur /= 10;
			}
		}
	}
	int buf;
	while (std::cin >> buf)
		std::cout << sum[buf] << '\n';
	return 0;
}