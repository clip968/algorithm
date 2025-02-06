#include<bits/stdc++.h>
using namespace std;

int main(){
    int N[51]{};
    int result{};
    int flag{};
    int t; scanf("%d", &t);
    for(int i{};i<t;i++){
        int temp;
        scanf("%d", &temp);
        N[temp]+=1;
    }

    // for(int i{};i<t;i++){
    //     printf("%d ", N[i]);
    // }
    for(int i{};i<=50;i++){
        // printf("%d ", N[i]);
        if(N[i] == i){
            result = N[i];
        }
    }
    if (result == 0 && N[0] != 0){
        printf("-1");
    }
    else printf("%d", result);
    
}