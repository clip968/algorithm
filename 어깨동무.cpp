#include<bits/stdc++.h>
using namespace std;
int n, k;
int result{INT_MAX/2};
vector<int> v;

int chk(int h){
    int cnt{};

    for(int i{};i<n;++i){
        if(i == 0){
            if(n > 1){
                int first = v[i];
                int second = v[i+1];
    
                if(abs(second - first) > h) cnt++;
            }
        }
        else if(i == n-1){
            int first = v[i];
            int second = v[i-1];
            if(abs(second - first) > h) cnt++;
        }
        else {
            int first = v[i-1];
            int second = v[i];
            int third = v[i+1];
            if(abs(first - second) > h || abs(second - third) > h) cnt++;
        }
    }
    return cnt;
}

void binary(int low, int high){
    if(low > high) return;

    int mid = (low + high) / 2;

    int cnt = chk(mid);
    if(cnt > k){//cnt는 지친사람
        binary(mid+1, high);
    }
    else{ // 지친사람이 k보다 작다면 여기서 최적화가능
        result = min(result, mid);
        binary(low, mid-1);
    }
}

int main(){
    scanf("%d %d", &n, &k);
    int tmp, max_tmp{};
    for(int i{};i<n;++i){
        scanf("%d", &tmp);
        max_tmp = max(max_tmp, tmp);
        v.push_back(tmp);
    }

    binary(0, max_tmp);

    printf("%d", result);
}