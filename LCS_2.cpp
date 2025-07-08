#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, string>>> arr;
string a;
string b;

pair<int, string> LCS(int m, int n) {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                arr[i][j].first = arr[i - 1][j - 1].first + 1;
                arr[i][j].second = arr[i-1][j-1].second + a[i-1];
            } else {
                if (arr[i - 1][j].first > arr[i][j - 1].first) {
                    arr[i][j] = arr[i - 1][j];
                } else {
                    arr[i][j] = arr[i][j - 1];
                }
            }
        }
    }
    return {arr[m][n].first, arr[m][n].second};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b;

    arr = vector<vector<pair<int, string>>>(a.size()+1, vector<pair<int, string>>(b.size()+1, {0, ""}));

    pair<int, string> result = LCS(a.size(), b.size());

    cout << result.first << "\n" << result.second << "\n";
    return 0;
}