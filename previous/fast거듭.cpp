#include<bits/stdc++.h>
using namespace std;

int recursive(int a, int b){
    if (b==0){
        return 1;
    }
    else if(b == 1){
        return a;
    }
    int result = recursive(a, b/2);

    if(b % 2 == 1){
        return (result * result * a) % 1000;
    }
    else{
        return (result * result) % 1000;
    }

}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        int a;
        long long b;
        scanf("%d %lld", &a, &b);
        int result = recursive(a, b);
        printf("%d\n", result);
    }
}