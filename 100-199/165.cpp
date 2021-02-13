// stamp continuous prob - using dfs and backtracking
#include <iostream>
#include <iomanip>
#include <cstring>
#define MAXN 200

int maxVal[MAXN], stampVal[MAXN], sol[MAXN], res;
bool checkSum[MAXN];
int h, k;

void dfs(int cur, int n, int sum) {
    if (cur >= h) {
        checkSum[sum] = true;
        return;
    }
    checkSum[sum] = true;
    for (int i = 0; i <= n; i++)
        dfs(cur + 1, n, sum + stampVal[i]);
}

void search(int cur) {
    if (cur >= k) {
        if (maxVal[cur-1] > res) {
            res = maxVal[cur-1];
            memcpy(sol, stampVal, sizeof(stampVal));
        }
        return;
    }
    for (int i = stampVal[cur-1] + 1; i <= maxVal[cur-1] + 1; i++)
    {
        memset(checkSum, false, sizeof(checkSum));
        stampVal[cur] = i;
        dfs(0, cur, 0);
        int tmp = 0, j = 1;
        while (checkSum[j++] == true)
            tmp++;
        maxVal[cur] = tmp;
        search(cur + 1);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> h >> k;
    while (h != 0 && k != 0) {
        stampVal[0] = 1;
        maxVal[0] = h;
        res = -1;
        search(1);
        for (int i = 0; i < k; i++) {
            std::cout << std::fixed << std::setw(3) << sol[i];
        }
        std::cout << " ->" << std::fixed << std::setw(3) << res << '\n';
        std::cin >> h >> k;
    }
    return 0;
}
