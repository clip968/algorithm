#include<bits/stdc++.h>
using namespace std;

int main() {
    unsigned long long n, m;
    vector<int> v;
    scanf("%lld %lld", &n, &m);

    for(int i{};i<n;i++){
        int temp; scanf("%d", &temp);
        v.push_back(temp);
    }
    sort(v.begin(), v.end());

    unsigned long long low = 0;
    unsigned long long high = v.back() * m;
    unsigned long long mid;
    while(low < high){
        mid = (low + high) / 2;
        long long cnt = 0;
        for(int i{};i<v.size();i++){
            cnt += mid / v[i];
        }

        if(cnt < m) low = mid + 1;
        else high = mid;
    }

    printf("%lld\n", low);
}