#include<bits/stdc++.h>
using namespace std;
int lope[10001];


int main(){
    int n, m;
    scanf("%d%d", &n, &m);

    int maxNum;
    for(int i{};i<n;i++){
        scanf("%d", &lope[i]);
        if(maxNum < lope[i]) maxNum = lope[i];
    }
    long long low = 1;
    long long high = maxNum;
    int result{};
    while(low<=high){
        long long mid = (low + high) / 2;
        int cnt{};
        for(int i{};i<n;i++){
            cnt += (lope[i] / mid);
        }
        if(cnt >= m){
            low = mid+1;
            result = mid;
        }
        else{
            high = mid-1;
        }
    }
    printf("%d\n", result);
}