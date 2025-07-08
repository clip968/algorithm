#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> v(n);
    int s{}, e{};
    for(int i{};i<n;++i){
        int tmp; scanf("%d", &tmp);
        if(s < tmp) s = tmp;
        e += tmp;
        v[i] = tmp;
    }

    while(s <= e){
        int mid = (s + e) / 2;
        int sum{}, cnt{};
        for(int i{};i<n;++i){
            sum += v[i];
            if(sum > mid){
                cnt++;
                sum = v[i];
            }
            
        }
        if(sum != 0){
            cnt++;
        }
        if(cnt > m) s = mid + 1;
        else e = mid - 1;
    }

    printf("%d\n", s);
}