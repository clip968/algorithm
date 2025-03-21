#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        int dp[n+1];

        for(int i{};i<=n;++i){
            dp[i]=i;
        }
        
        dp[0] = 0;
        dp[1] = 1;
        dp[m] = 1e9/2; //마스킹
        for(int i{2};i<=n;++i){
            if(i == m) continue;
            dp[i] = min(dp[i-2]+1, dp[i-1]+1);
            // printf("%d\n", dp[i]);
        }
        printf("%d\n", dp[n]);
    }
}