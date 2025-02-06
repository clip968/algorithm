#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; scanf("%d", &t);

    while(t--){
        int n; scanf("%d", &n);
        if(n <= 3){
            printf("1\n");
            continue;
        }
        vector<long long> arr(n+1);
        arr[1] = 1;
        arr[2] = 1;
        arr[3] = 1;
        for(int i{4};i<=n;i++){
            arr[i] = arr[i-2] + arr[i-3];
        }

        printf("%lld\n", arr[n]);
    }

    return 0;
}