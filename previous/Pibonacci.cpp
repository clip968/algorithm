#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000000000000000
#define PI 3.14159265358979323846
long long dp[1005][1005]; 

long long fibo(int n, int pi_cnt){
    if(dp[n][pi_cnt] != -1) return dp[n][pi_cnt];
    if(n - PI * pi_cnt <= PI) return dp[n][pi_cnt] = 1;
    return dp[n][pi_cnt] = (fibo(n-1, pi_cnt) + fibo(n, pi_cnt + 1)) % MOD;
}

int main() {
    int n; scanf("%d", &n);
    memset(dp, -1, sizeof(dp));
    printf("%lld", fibo(n, 0));
}
