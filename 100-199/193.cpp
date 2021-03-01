#include <iostream>
#include <algorithm>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

using namespace std;

int backtrack(int n) {
    int w, b;
    
}

vector<int> adjList[100];
int color[100];
int visited[100];

int main() {
    io;
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        while (n--) {
            int a, b;
            cin >> a >> b;
            adjList[a-1].push_back(b-1);
            adjList[b-1].push_back(a-1);
        }

    }
}