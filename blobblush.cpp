#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    scanf("%lld", &n);

    long long m = 1;
    while(n > m) m = m * 2 + 1;
    if(n == m) printf("1\n%lld", n);
    else{
        printf("2\n%lld\n%lld", (m ^ n), n);
    }
}