#include <iostream>
#include <vector>

using namespace std;
#define ll unsigned long long int

void solve() {
    int n, m;
    ll k;
    if (!(cin >> n >> m >> k)) return;

    vector<ll> arr(n);
    vector<bool> eaten(n, false);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll curr = 0;
    for (int i = 0; i < n; i++) {
        if (i >= m) {
            if (eaten[i - m]) {
                curr -= arr[i - m];
            }
        }
        if (curr + arr[i] <= k) {
            eaten[i] = true;
            curr += arr[i];
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
