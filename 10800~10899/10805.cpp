// Using Minimum Diameter Spanning Tree(MDST)
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    int T;
    int casen = 1;
    cin >> T;
    while (T--) {
        int n, tracks;
        cin >> n >> tracks;
        vector<vector<int>> map;
        vector<int> emp(n, 0);
        for (int i = 0; i < n; i++) map.push_back(emp);
        for (int i = 0; i < tracks; i++) {
            int a, b;
            cin >> a >> b;
            map[a][b] = 1;
            map[b][a] = 1;
        }

        // Floyd Warshell
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (map[i][k] == 0 || map[k][j] == 0 || i == j) continue;
                    if (map[i][j] == 0) map[i][j] = map[i][k] + map[k][j];
                    else map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
                }
            }
        }

        vector<vector<int>> rank;
        // Descending shortest-path order
        for (int i = 0; i < n; i++) {
            vector<int> cur_rank;
            for (int j = 0; j < n; j++) cur_rank.push_back(j);

            for (int j = 0; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (map[i][cur_rank[j]] < map[i][cur_rank[k]]) {
                        int tmp = cur_rank[j];
                        cur_rank[j] = cur_rank[k];
                        cur_rank[k] = tmp;
                    }
                }
            }
            rank.push_back(cur_rank);
        }

        double ecc = numeric_limits<double>::max();

        // Find absolute center
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (map[i][j] != 1) continue;
                for (int a = 0, b = 1; b < n; b++) {
                    if (map[j][rank[i][a]] <= map[j][rank[i][b]]) {
                        ecc = min(ecc, (map[i][rank[i][b]] + map[j][rank[i][a]] + 1) / 2.0);
                        a = b;
                    }
                }
                // cout << ecc << "\n";
            }
        }

        cout << "Case #" << casen << ":\n";
        cout << (int)(ecc * 2) << "\n\n";
        casen++;
    }
}