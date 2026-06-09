#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int w1, w2, h1, h2;
    cin >> w1 >> w2 >> h1 >> h2;

    int lower = w1 * w1 * h1;
    int full = lower + w2 * w2 * h2;

    int total = 0;
    int prev = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;

        total += v;

        int curr;

        if (total <= lower) {
            curr = total / (w1 * w1);
        }
        else if (total <= full) {
            curr = h1 + (total - lower) / (w2 * w2);
        }
        else {
            curr = h1 + h2;
        }

        ans = max(ans, curr - prev);
        prev = curr;
    }

    cout << ans << '\n';
    return 0;
}