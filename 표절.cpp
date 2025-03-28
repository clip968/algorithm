#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; scanf("%d", &n);
    vector<long long> v(n);
    for(int i{};i<n;++i){
        scanf("%lld", &v[i]);
    }
    long long answer{};
    sort(v.begin(), v.end());

    for(int i{};i<n-1;++i){
        int low = i;
        int high = n-1;
        int idx = i;
        while(low <= high){
            int mid = (low + high) / 2;
            if(v[mid] * 9 <= v[i] * 10){
                idx = max(idx, mid);
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        answer+=idx-i;
    }
    printf("%lld", answer);
}