#include<bits/stdc++.h>
using namespace std;

int main(){
    int n{};
    while(true){
    n++;
    int l, p, v;
    scanf("%d %d %d", &l, &p, &v);
    if (v == 0 && l == 0 && p == 0){
        break;
    }
    if ((v % p) > l){
        int result = (v / p * l) + l;
        printf("Case %d: %d\n", n, result);
    }
    else{
        int result = (v / p * l) + (v % p);
        printf("Case %d: %d\n", n, result);
    }
    }
}