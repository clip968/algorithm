#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int n, total, result{INT_MIN/2};

int chk(int mid){
    int cnt{};
    for(int i{};i<n;++i){
        if(mid < v[i]){
            cnt += mid;
        }
        else{
            cnt += v[i];
        }
    }
    return cnt;
}

void binary_search(int low, int high){
    if(low > high) return;

    int mid = (low + high) / 2;
    int tmp = chk(mid); // 상한선 제한해서 모두 더한 값

    //만약 모두 더한 값이 total 보다 크다면 상한선을 줄여야함
    if(tmp > total){
        binary_search(low, mid-1);
    }
    else{
        result = max(result, mid);
        binary_search(mid+1, high);
    }
}

int main(){
    scanf("%d", &n);
    int tmp, maxx{};
    for(int i{};i<n;++i){
        scanf("%d", &tmp);
        maxx = max(maxx, tmp);
        v.push_back(tmp);
    }
    scanf("%d", &total);

    // sort(v.begin(), v.end());

    binary_search(0, maxx);

    printf("%d", result);


}