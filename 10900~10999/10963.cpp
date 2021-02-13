#include <iostream>

int main()
{
	int T, W, diff, buf1, buf2;
	bool flag, first = true;
	std::cin >> T;
	while (T--)
	{
		if (first)
			first = false;
		else
			std::cout << '\n';
		flag = true;
		std::cin >> W >> buf1 >> buf2;
		diff = buf1 - buf2;
		for (int i = 1; i < W; i++)
		{
			std::cin >> buf1 >> buf2;
			if (diff != buf1 - buf2)
				flag = false;
		}
		if (flag)
			std::cout << "yes" << '\n';
		else
			std::cout << "no" << '\n';
	}
	return 0;
}