#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

using namespace std;

int main() {
    io;
    int k, x0, y0;
    while (cin >> k) {
        if (k == 0) break;
        cin >> x0 >> y0;
        while (k--) {
            int x, y;
            cin >> x >> y;
            if (x == x0 || y == y0) cout << "divisa\n";
            else if (x > x0 && y > y0) cout << "NE\n";
            else if (x < x0 && y > y0) cout << "NO\n";
            else if (x < x0 && y < y0) cout << "SO\n";
            else cout << "SE\n";
        }
    }
}