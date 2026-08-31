#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<int> cnt(k + 1, 0);
    for (int s = 0; s < n; s++) {
        int cl;
        cin >> cl;
        cnt[cl]++;
    }
    int maxi = *max_element(cnt.begin() + 1, cnt.end());
    int ans = 0;
    for (int clcnt = 1; clcnt <= k; clcnt++) {
        if (cnt[clcnt] >= maxi - 1) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}