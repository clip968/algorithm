#include<bits/stdc++.h>
using namespace std;


void merge(vector<int>& v, int left, int mid, int right){
    vector<int> tmp(right - left + 1);
    int i{left}, j{mid+1}, k{};

    while(i <= mid && j <= right){
        if(v[i] <= v[j]){
            tmp[k++] = v[i++];
        }
        else{
            tmp[k++] = v[j++];
        }
    }

    while(i<=mid){
        tmp[k++] = v[i++];
    }
    while(j<=right){
        tmp[k++] = v[j++];
    }

    for(int i{};i<tmp.size();i++){
        v[left+i] = tmp[i];
    }
}

void merge_sort(vector<int>& v, int start, int end){
    if(start >= end) {
        return;
    }
    int mid = start + (end - start) / 2;

    merge_sort(v, start, mid);
    merge_sort(v, mid+1, end);
    merge(v, start, mid, end);
}


int main(){
    int n; scanf("%d", &n);
    vector<int> v(n);

    for(int i{};i<n;++i){
        scanf("%d", &v[i]);
    }

    merge_sort(v, 0, n-1);
    for(int i{};i<n;++i){
        printf("%d\n", v[i]);
    }
}