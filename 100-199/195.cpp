#include <iostream>
#include <algorithm>
#include <string>
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

using namespace std;

bool cmp(char a, char b) {
    char na = toupper(a), nb = toupper(b);
    if (na == nb) return (int)a < (int)b;
    else return (int)na < (int)nb;
}

int main() {
    io;
    int n;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        sort(s.begin(), s.end(), cmp);
        do {
            cout << s << '\n';
        }while (next_permutation(s.begin(), s.end(), cmp));
    }
}