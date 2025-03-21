#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long pow_x (long long x, long long n) {
    long long result = 1;
    while(n > 0){
        if(n & 1) result = (result * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;
    }

    return result;
}

int main(){
    int n;
    int answer{};
    scanf("%d", &n);

    for(int i{};i<n;++i){
        long long a, b;
        scanf("%lld %lld", &a, &b);
        
        if(b == 0) continue;

        long long first = (a * b) % MOD;
        long long second = pow_x(2, b-1);

        answer = (answer + (first * second) % MOD) % MOD;
    }

    printf("%lld", answer);
    return 0;
}