#include <iostream>
#include <iomanip>

int bignum[5001][2000] = { 0 };

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int i, j;
	bignum[1][0] = 1;
	for (i = 2; i < 5001; i++) {
		for (j = 0; j < 2000; j++) {
			bignum[i][j] += bignum[i - 1][j] + bignum[i - 2][j];
			if (bignum[i][j] >= 10) {
				bignum[i][j + 1] += bignum[i][j] / 10;
				bignum[i][j] %= 10;
			}
		}
	}
	int buf;
	while (std::cin >> buf) {
		i = 1999;
		while (bignum[buf][i] == 0)
			i--;
		std::cout << "The Fibonacci number for " << buf << " is ";
		for (; i >= 0; i--)
			std::cout << bignum[buf][i];
		std::cout << '\n';
	}
	return 0;
}