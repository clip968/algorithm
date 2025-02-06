#include<bits/stdc++.h>
using namespace std;

int Uclidian(int a, int b){
     if(b == 0){
        return a;
    }
    else{
        return Uclidian(b, a%b);
    }
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        int a, b;
        scanf("%d%d", &a, &b);
        int result = Uclidian(a, b);
        printf("%d\n", result);
    }
}