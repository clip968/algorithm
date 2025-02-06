#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> arr;
string a;
string b;

int LCS(int m, int n) {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                arr[i][j] = arr[i - 1][j - 1] + 1;
            } else {
                if (arr[i - 1][j] > arr[i][j - 1]) {
                    arr[i][j] = arr[i - 1][j];
                } else {
                    arr[i][j] = arr[i][j - 1];
                }
            }
        }
    }
    return arr[m][n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b;

    // 동적으로 arr의 크기 설정
    arr = vector<vector<int>>(1001, vector<int>(1001, 0));

    int result = LCS(a.size(), b.size());

    cout << result << "\n";
    return 0;
}
