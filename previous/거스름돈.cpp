#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; scanf("%d", &n);
    int answer{};
    
    vector<int> dp(n+1, INT_MAX);

    dp[0] = 0;

    for(int i{1};i<=n;++i){
        if(i >= 2 && dp[i-2] != INT_MAX) {
            dp[i] = min(dp[i], dp[i-2]+1);
        }

        if(i >= 5 && dp[i-5] != INT_MAX) {
            dp[i] = min(dp[i], dp[i-5]+1);
        }
    }

    if(dp[n] == INT_MAX) {
        printf("-1");
    }
    else {
        printf("%d", dp[n]);
    }

    
}