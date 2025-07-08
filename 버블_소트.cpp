#include<bits/stdc++.h>
using namespace std;
long long result{};

void merge(vector<long long>& v, long long left, long long mid, long long right){
    vector<long long> tmp(right - left + 1);
    long long i{left}, j{mid+1},k{};

    while(i <= mid && j <= right){
        if(v[i] <= v[j]){
            tmp[k++] = v[i++];
        }
        else{
            result += mid - i + 1;    
            tmp[k++] = v[j++];
        }
    }
    
    while(i <= mid){
        tmp[k++] = v[i++];
    }
    while(j<=right){
        tmp[k++] = v[j++];
    }

    for(int i{};i<tmp.size();++i){
        v[left+i] = tmp[i];
    }
}

void merge_sort(vector<long long>& v, long long start, long long end){
    if(start >= end) return;
    long long mid = start + (end - start) / 2;
    
    merge_sort(v, start, mid);
    merge_sort(v, mid+1, end);
    merge(v, start, mid, end);
}

int main(){
    int n; scanf("%d", &n);
    vector<long long> v(n);

    for(int i{};i<n;++i){
        scanf("%lld", &v[i]);
    }

    merge_sort(v, 0, n-1);
    printf("%lld", result);

}