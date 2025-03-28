#include<bits/stdc++.h>
using namespace std;
int cnt1{1}, cnt2;
int fibo1(int n){
    if(n == 1 || n == 2) {
        return 1;
    }
    else {
        cnt1++;
        return fibo1(n-1) + fibo1(n-2);
    }
}

int fibo2(int n){
    int f[42];
    f[1] = 1;
    f[2] = 1;
    for(int i{3};i<=n;++i){
        cnt2++;
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}

int main(){
    int n; scanf("%d", &n);
    fibo1(n);
    fibo2(n);
    printf("%d %d", cnt1, cnt2);
}