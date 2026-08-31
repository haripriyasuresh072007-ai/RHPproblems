#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

void solve() {
    int R, C, K; 
    if (!(cin >> R >> C >> K)) return;
    
    vector<string> g(R);
    for (int row = 0; row < R; row++) {
        cin >> g[row];
    }

    vector<bool> br(R, false), bc(C, false);
    for (int row = 0; row < R; row++) {
        for (int col = 0; col < C; col++) {
            if (g[row][col] == '#') {
                br[row] = true;
                bc[col] = true;
            }
        }
    }

    queue<pair<int, int>> q;
    vector<vector<int>> dist(R, vector<int>(C, -1));

    // Push all safe empty cells into the BFS queue as starting sources
    for (int row = 0; row < R; row++) {
        for (int col = 0; col < C; col++) {
            if (!br[row] && !bc[col] && g[row][col] == '.') {
                q.push({row, col});
                dist[row][col] = 0;
            }
        }
    }

    int reachable_count = 0;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    // Run multi-source BFS up to distance K
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        reachable_count++;

        if (dist[r][c] == K) continue;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                if (g[nr][nc] == '.' && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    cout << reachable_count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}