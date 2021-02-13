#include <iostream>

//  7! = 5040
//  8! = 40320
// 13! = 6227020800

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int buf;
	long long int num[14];
	num[0] = 1;
	for (long long int i = 1; i < 14; i++)
		num[i] = num[i - 1] * i;
	while (std::cin >> buf)
	{
		if (buf < 0)
		{
			if (buf % 2 == 0)
				std::cout << "Underflow!\n";
			else
				std::cout << "Overflow!\n";
		}
		else if (buf < 8)
			std::cout << "Underflow!\n";
		else if (buf > 13)
			std::cout << "Overflow!\n";
		else
			std::cout << num[buf] << '\n';
	}
	return 0;
}