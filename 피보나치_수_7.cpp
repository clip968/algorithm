#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main(){
    int n; scanf("%d", &n);
    int fibo[1000005];
    fibo[1] = 1;
    fibo[2] = 1;
    for(int i{3};i<=n;++i){
        fibo[i] = (fibo[i-1] + fibo[i-2]) % MOD;
    }

    printf("%d", fibo[n]);
}