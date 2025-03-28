#include<bits/stdc++.h>
using namespace std;
set<long long> s;
long long answer = -1;

bool f2(long long mid){
    if(s.find(mid) != s.end()){
        return true;
    }
    return false;

}

void f(long long low, long long high, long long back) {
    if(low > high) return;

    long long mid = (low + high) / 2;
    if(mid < back){
        if(f2(mid)) answer = max(answer, mid);
        f(mid+1, high, back);
    }
    else {
        f(low, mid-1, back);
    }
}

int main(){
    int n; scanf("%d", &n);
    long long tmp;

    for(int i{};i<n;++i){
        scanf("%lld", &tmp);
        s.insert(tmp);
    }
    auto it1 = s.begin();
    auto it2 = s.rbegin();
    long long low = *it1 + *next(it1, 1) + *next(it1, 2);
    long long high = *it2 + *next(it2, 1) + *next(it2, 2);

    f(low, high, *it2);

    printf("%lld", answer);

}