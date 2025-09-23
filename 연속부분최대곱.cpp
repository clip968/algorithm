#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<double> values(n);
    for (double &x : values) cin >> x;

    double current = values[0];
    double best = values[0];

    for (int i = 1; i < n; ++i) {
        current = max(values[i], current * values[i]);
        best = max(best, current);
    }

    cout << fixed << setprecision(3) << best << '\n';
    return 0;
}
