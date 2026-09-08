#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<ll> cnt(m + 1, 0);

    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        cnt[x]++;
    }

    vector<ll> suff(m + 2, 0);

    for (ll i = m; i >= 1; i--) {
        suff[i] = suff[i + 1] + cnt[i];
    }

    vector<ll> ans(m + 1, 0);

    for (ll k = 1; k <= m; k++) {
        if (k >= 19) {
            ans[k] = ans[k - 1];
            continue;
        }

        ll limit = (1LL << k) - 1;
        ll best = 0;

        for (ll x = 1; x <= m; x++) {
            ll cur = 0;

            for (ll j = 1; j <= limit && j * x <= m; j++) {
                cur += suff[j * x];
            }

            ll special = (limit + 1) * x;

            if (special <= m) {
                cur += cnt[special];
            }

            best = max(best, cur);
        }

        ans[k] = best;
    }

    for (ll k = 1; k <= m; k++) {
        cout << ans[k] << " ";
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}