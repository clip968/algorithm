#include<bits/stdc++.h>
using namespace std;
int dp[1005][10]{};
int main(){
    int n; scanf("%d", &n);
    int answer=0;
    for(int i=0;i<10;i++){
        dp[1][i] = 1;
    }
    for(int i=2;i<=n;i++){
        dp[i][0] = 1;
    }

    for(int i=2;i<=n;i++){
        for(int j=1;j<10;j++){
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 10007;
        }
    }
    for(int i=0;i<10;i++){
        answer += dp[n][i];
    }

    printf("%d", answer % 10007);

}