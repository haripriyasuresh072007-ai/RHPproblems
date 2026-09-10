#include <iostream>
using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;

    int s = x + y;
    int rx = 0, ry = 0;

    for (int sh = 30; sh >= 0; sh--) {
        if ((s & (1 << sh)) != 0) {
            if ((rx | (1 << sh)) <= x) {
                rx = rx | (1 << sh);
            } else {
                ry = ry | (1 << sh);
            }
        }
    }
    cout << s << " " << x - rx << endl;
}
int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}