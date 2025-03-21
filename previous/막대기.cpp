#include<bits/stdc++.h>
using namespace std;

int main() {
    int x;
    scanf("%d", &x);
    int count = 0;
    int n = 1;

    while(x > 0){
        if(n & x) {
            count++;
        }
        x >>= 1;
    }

    printf("%d", count);
}