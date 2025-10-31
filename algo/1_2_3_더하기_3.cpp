#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000009
int main(){
    int t; scanf("%d", &t);
    while(t--){
        int num; scanf("%d", &num);
        long long dp[1000001];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        if(num > 3) {
            for(int i{4};i<=num;++i){
                dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % MOD;
            }
            printf("%lld\n", dp[num] % MOD);
        }
        else{
            printf("%lld\n", dp[num]%MOD);
        }
        
        

    }
}