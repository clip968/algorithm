#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    scanf("%lld", &n);

    long long small{n};
    for(long long i{2};i*i<=n;++i){
        if(n%i==0){
            small=i; break;
        }
    }
    long long cnt{};
    if(small==n){
        cnt = n-1;
    }
    else {
        cnt = n - (n / small);
    }
    printf("%lld\n", cnt);
}
