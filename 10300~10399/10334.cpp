#include <iostream>

// if ray reflect from first panel or third panel, two choices: thrid/first, second
// if ray reflect from second panel, only one choice: one or three

int ref13[1001][1000] = { 0 };
int ref2[1001][1000] = { 0 };
int sum[1001][1000] = { 0 };

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	ref13[0][0] = 1;
	int i, j;
	for (i = 1; i < 1001; i++) {
		for (j = 0; j < 1000; j++) {
			ref2[i][j] = ref13[i - 1][j];
			ref13[i][j] += ref2[i - 1][j] + ref13[i - 1][j];
			if (ref13[i][j] >= 10) {
				ref13[i][j + 1]++;
				ref13[i][j] %= 10;
			}
		}
	}
	for (i = 0; i < 1001; i++) {
		for (j = 0; j < 1000; j++) {
			sum[i][j] += ref13[i][j] + ref2[i][j];
			if (sum[i][j] >= 10) {
				sum[i][j + 1]++;
				sum[i][j] %= 10;
			}
		}
	}
	int buf;
	while (std::cin >> buf) {
		i = 999;
		while (sum[buf][i] == 0)
			i--;
		for (; i >= 0; i--)
			std::cout << sum[buf][i];
		std::cout << '\n';
	}
	return 0;
}