#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int N, K;
using combo = array<int, 10>;
vector<combo> ans;

void dfs(int slot, int bal, combo arr) {
    if (slot == N) {
        // The last element A[N] must satisfy N * A[N] = bal
        if (bal % N == 0) {
            arr[N - 1] = bal / N;
            ans.push_back(arr);
        }
        return;
    }
    // Try all possible non-negative values for A[slot]
    int val = 0;
    while (bal >= 0) {
        arr[slot - 1] = val;
        dfs(slot + 1, bal, arr);
        val++;
        bal -= slot; // Each increment of A[slot] reduces bal by slot
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    combo arr{};
    // Fast path for N = 1
    if (N == 1) {
        cout << K << "\n";
        return 0;
    }
    dfs(1, K, arr);
    for (const combo& c : ans) {
        for (int i = 0; i < N; i++) {
            cout << c[i] << (i + 1 == N ? "\n" : " ");
        }
    }
    return 0;
}