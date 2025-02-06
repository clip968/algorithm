#include<bits/stdc++.h>
using namespace std;
int d[501];
int dp[501][501];

void reset_dp(int n){
    for(int i{};i<=n;i++){
        for(int j{};j<=n;j++){
            if(j == i) dp[i][j] = 0;
            else dp[i][j] = INT_MAX;
        }
    }
}

int main(){
    int n; scanf("%d", &n);
    for(int i{};i<n;i++){
        scanf("%d%d", &d[i], &d[i+1]);
    }

    reset_dp(n);

    for(int ln{1};ln<=n;ln++){
        for(int i{1};i<=n-ln;i++){
            int j = i + ln;
            for(int k{i};k<j;k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + d[i-1]*d[k]*d[j]);
            }

        }
    }

    printf("%d\n", dp[1][n]);

}