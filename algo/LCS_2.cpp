#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
string a;
string b;

int LCS(int m, int n) {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                if (dp[i-1][j] > dp[i][j-1]) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
    }
    return dp[m][n];
}

string Backtracking(int m, int n) {
    string result = "";
    while(m>0 && n>0) {
        if(a[m-1] == b[n-1]) {
            result = a[m-1] + result;
            m--;
            n--;
        }
        else if(dp[m-1][n] > dp[m][n-1]) {
            m--;
        }
        else n--;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b;

    int m=a.length(), n=b.length();
    dp = vector<vector<int>>(m+1, vector<int>(n+1, 0));

    int result = LCS(m, n);
    string s = Backtracking(m, n);

    cout << result << "\n";
    if(result > 0){
        cout << s << "\n" ;
    }
    
    return 0;
}