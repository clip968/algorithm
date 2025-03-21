#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    scanf("%d%d", &n, &k);

    int low = 1, high = k;
    while(low<high) {
        int mid = (low + high) / 2;
        int cnt{};

        for(int i{1};i<=n;i++){
            cnt += min(n, mid / i);
        }

        if(cnt < k) low = mid + 1;
        else high = mid;
    }

    printf("%d\n", low);
}