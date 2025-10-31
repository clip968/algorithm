#include<bits/stdc++.h>
using namespace std;

int main(){
    int sum= 0;
    int n = 20;
    for(int i{1};i<=n;i++){
        for(int j = i;j > 1;j /=2){
            sum++;
        }
    }

    printf("%d",sum);
}