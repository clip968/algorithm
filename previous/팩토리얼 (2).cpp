#include<bits/stdc++.h>
using namespace std;

int f(int x){
    if(x == 0){
        return 1;
    }
    return x * f(x-1);
}

int main(){
    int n; scanf("%d", &n);
    printf("%d", f(n));
}