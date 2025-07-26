#include<bits/stdc++.h>
using namespace std;

int main(){
    long n; scanf("%ld", &n);

    if(n < 0) {
        printf("32\n");
        return 0;
    }

    else {
        if(n == 0) {
        printf("1\n");
        return 0;
    }

    int bits{};
    while(n){
        ++bits;
        n >>= 1;
    }
    printf("%d\n", bits);
    }
}