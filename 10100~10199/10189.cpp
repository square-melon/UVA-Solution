#include <iostream>
#include <cstring>

int main() {
    //std::ios_base::sync_with_stdio(false);
    //std::cin.tie(0);
    //std::cout.tie(0);
    int mineMap[102][102], n, m, testCase = 1;
    int first = 0;
    while (true) {
        std::cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        if (first == 0)
            first = 1;
        else
            std::cout << '\n';
        for (int i = 0; i < 102; i++) {
            for(int j = 0; j < 102; j++) {
                mineMap[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            std::string str;
            //std::cout << "test";
            std::cin >> str;
            for (unsigned int j = 0; j < str.size(); j++) {
                if (str[j] == '*')
                    mineMap[i + 1][j + 1] = -1;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (mineMap[i][j] == -1)
                    continue;
                int cnt = 0;
                for (int k = i - 1; k <= i + 1; k++) {
                    for (int l = j - 1; l <= j + 1; l++) {
                        if (k == i && l == j)
                            continue;
                        if (mineMap[k][l] == -1)
                            cnt++;
                    }
                }
                mineMap[i][j] = cnt;
            }
        }
        std::cout << "Field #" << testCase << ":\n";
        testCase++;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if(mineMap[i][j] == -1)
                    std::cout << "*";
                else
                    std::cout << mineMap[i][j];
            }
            std::cout << '\n';
        }
    }
    return 0;
}
