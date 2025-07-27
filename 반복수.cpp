#include<bits/stdc++.h>
using namespace std;
long long a,b,m;
int k;

int is_val(long long n){
    long long start{pow(10, k-1)};
    long long end{pow(10, k)};
    int cnt{};
    for(long long i{start};i<end;++i){
        if(i > n) break;
        if(i % m == 0) cnt++;

        long long cur{i};
        string num{to_string(i)};
        int idx{};
        while(1){
            int next_digit{num[idx]-'0'};
            if(cur > n/10) break;
            // if(cur == n/10 && next_digit > n%10) break;

            cur = 10 * cur + next_digit;

            if(cur > n) break;
            if(cur % m == 0) cnt++;

            idx = (idx + 1) % k;
        }
    }
    return cnt;
    
}

int main(){
    
    scanf("%lld %lld %d %lld", &a, &b, &k, &m);

    int result{is_val(b) - is_val(a-1)};

    printf("%d\n", result);
}