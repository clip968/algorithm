#include<bits/stdc++.h>
using namespace std;
long long l[51];
long long p[51];

long long func(int n, long long x){
    if(x >= l[n]) return p[n];

    if(n==0){
        if(x > 0){
            return 1;
        }
        else{
            return 0;
        }
    }

    if(x == 0) return 0;
    else if(x == 1) return 0;
    else if(x <= 1 + l[n-1]) return func(n-1, x-1);
    else if(x == 1 + l[n-1] + 1) return p[n-1] + 1;
    else if(x <= 1 + l[n-1] + 1 + l[n-1]) {
        return p[n-1] + 1 + func(n-1, x - (1+l[n-1]+1));
    }
    else{
        return 2 * p[n-1] + 1;
    }
    
    //A B C D E
    //'B' + dp[n-1] + 'P' + dp[n-1] + 'B'
}

int main(){
    int n;
    long long x;
    scanf("%d %lld", &n, &x);

    l[0] = 1;
    p[0] = 1;

    for(int i{1};i<=n;++i){
        l[i] = 2 * l[i-1] + 3;
        p[i] = 2 * p[i-1] + 1;
    }

    printf("%lld", func(n ,x));
}