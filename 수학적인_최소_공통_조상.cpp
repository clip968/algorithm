#include<bits/stdc++.h>
using namespace std;

long long find_p(long long n){
    if(n <= 1) return 1;
    else if(n % 2 == 0) return 2;
    for(long long i{3}; i <= (long long)sqrt(n)+1; i+=2){
        if(n % i == 0) return i;
    }
    
    return n; 
}

int main(){
    long long a, b; 
    scanf("%lld %lld", &a, &b);
    
    while(a != b){
        long long a_p = find_p(a);
        long long b_p = find_p(b);
        if(a > b){
            a = a / a_p;
        }
        else{
            b = b / b_p;
        }
    }

    printf("%lld", a);
    return 0;
}