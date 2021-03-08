#include <iostream>

using namespace std;

int dp[251][10000];

int* Double(int* a);
void Plus(int* a, int* b, int* res);
void Print(int* a);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i < 10000; i++) dp[0][i] = 0;
    dp[0][0] = 1;
    for (int i = 1; i < 10000; i++) dp[1][i] = 0;
    dp[1][0] = 1;
    for (int i = 2; i <= 250; i++) Plus(dp[i-1], Double(dp[i-2]), dp[i]);
    int n;
    while (cin >> n) Print(dp[n]);
}

int* Double(int* a) {
    int* res = new int[10000];
    for (int i = 0; i < 10000; i++) res[i] = a[i] * 2;
    for (int i = 0; i < 9999; i++) {
        if (res[i] >= 10) {
            res[i+1] += res[i] / 10;
            res[i] %= 10;
        }
    }
    return res;
}

void Plus(int* a, int* b, int* res) {
    for (int i = 0; i < 10000; i++) res[i] = a[i] + b[i];
    for (int i = 0; i < 9999; i++) {
        if (res[i] >= 10) {
            res[i+1] += res[i] / 10;
            res[i] %= 10;
        }
    }
}

void Print(int* a) {
    int i;
    for (i = 9999; i >= 0; i--) if (a[i] != 0) break;
    for (; i >= 0; i--) cout << a[i];
    cout << '\n';
}